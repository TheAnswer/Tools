#include "creaturemanager.h"
#include "ui_creaturemanager.h"
#include <QFile>
#include "mainwindow.h"
#include <QTextStream>
#include "settings.h"
#include "CreatureObject.h"
#include <QMessageBox>
#include "creatureluamanager.h"

CreatureManager::CreatureManager(MainWindow* mainWindow, QWidget *parent) :
    QDialog(parent), ui(new Ui::CreatureManager) {
    ui->setupUi(this);

    this->mainWindow = mainWindow;

    ui->progressBar->reset();

    creatureChanged = false;

    currentCreatureObject = NULL;

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(loadCreatureObjects()));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(findCreatureFile(QString)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(currentCreatureChanged(QString)));
    connect(ui->reloadCreature, SIGNAL(clicked()), this, SLOT(reloadCreature()));
    connect(ui->saveCreature, SIGNAL(clicked()), this, SLOT(promptToSave()));
    connect(ui->addWeapon, SIGNAL(clicked()), this, SLOT(addWeapon()));
    connect(ui->removeWeapon, SIGNAL(clicked()), this, SLOT(removeWeapon()));
    connect(ui->addLoutGroup, SIGNAL(clicked()), this, SLOT(addLootGroup()));
    connect(ui->removeLootGroup, SIGNAL(clicked()), this, SLOT(removeLootGroup()));
    connect(ui->addTemplate, SIGNAL(clicked()), this, SLOT(addTemplate()));
    connect(ui->removeTemplate, SIGNAL(clicked()), this, SLOT(removeTemplate()));
    connect(ui->comboBox_OptionsBitmask, SIGNAL(currentIndexChanged(int)), this, SLOT(optionBitSelectionChanged()));
    connect(ui->checkBox_optionsBitmask, SIGNAL(stateChanged(int)), this, SLOT(optionBitValueChanged()));
}

CreatureManager::~CreatureManager() {
    QMapIterator<QString, CreatureObject*> i(creatureMap);

    while (i.hasNext()) {
        i.next();

        delete i.value();
    }

    creatureMap.clear();

    delete ui;
}
/*
void CreatureManager::loadFiles(QByteArray& buffer) {
    int i = 0;

    while (i < buffer.size()) {
        QString token;
        QTextStream stream(&token);
        char c;

        while ((c = buffer[i++]) && c != ' ' && c != '\n' && c != '\0') {
            stream << c;
        }

        if (token.contains("includeFile")) {
            int start = token.indexOf("(");
            int end = token.indexOf(")");

            QString file = token.mid(start + 2, end - start - 3);

            creatureFiles.append(file);
        }
    }
}
*/

void CreatureManager::addCreatureObject(const QString& key, CreatureObject* value) {
    creatureMap[key] = value;
    ui->comboBox->addItem(key);
}

void CreatureManager::loadCreatureObjects() {
    QString serverDir = mainWindow->getSettings()->getServerDirectory();

    QString fullName = serverDir + "/bin/scripts/mobile/creature/serverobjects.lua";

    QApplication::setOverrideCursor(Qt::WaitCursor);

    mainWindow->getLuaManager()->runFile(serverDir + "/bin/scripts/mobile/creatures.lua");

    QApplication::restoreOverrideCursor();

    return;
/*
    QFile objectsFile(fullName);

    if (!objectsFile.open(QIODevice::ReadOnly)) {
        mainWindow->warning("could not open " + fullName);
        return;
    }

    QByteArray buffer = objectsFile.readAll();

    loadFiles(buffer);

    fullName = serverDir + "/bin/scripts/mobile/npc/serverobjects.lua";

    QFile npcFile(fullName);

    if (!npcFile.open(QIODevice::ReadOnly)) {
        mainWindow->warning("could not open " + fullName);
        return;
    }

    QByteArray npcs = npcFile.readAll();

    loadFiles(npcs);

    mainWindow->outputToConsole("detected creature files:" + QString::number(creatureFiles.size()));

    ui->progressBar->reset();
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(creatureFiles.size() - 1);

    QApplication::setOverrideCursor(Qt::WaitCursor);

    for (int i = 0; i < creatureFiles.size(); ++i) {
        CreatureObject* creatureObject = parseCreatureObject(creatureFiles.at(i));

        ui->progressBar->setValue(i);

        creatureMap[creatureFiles.at(i)] = creatureObject;

        ui->comboBox->addItem(creatureFiles.at(i));
    }

    QApplication::restoreOverrideCursor();

    //mainWindow->outputToConsole(creatureMap[creatureFiles.at(0)]->serializeToText());

    mainWindow->outputToConsole("creature files loaded");
    */

}

void CreatureManager::findCreatureFile(const QString& str) {
    int idx = ui->comboBox->findText(str, Qt::MatchContains);

    if (idx != -1)
        ui->comboBox->setCurrentIndex(idx);
}

void CreatureManager::promptToSave() {
    if (currentCreatureObject == NULL)
        return;

    if (QMessageBox::question (this, "Saving file", "Are you sure?", QMessageBox::Save, QMessageBox::Abort) == QMessageBox::Save) {
        mainWindow->outputToConsole("saving to " + currentCreatureObject->getFileName());

        saveCurrentCreature();
    }
}

void CreatureManager::removeWeapon() {
    if (ui->weapons->count() == 0)
        return;

    ui->weapons->removeItem(ui->weapons->currentIndex());
}

void CreatureManager::addWeapon() {
    QString weapon = ui->newWeapon->text();

    if (weapon.isEmpty())
        return;

    ui->weapons->addItem(weapon);
}

void CreatureManager::addTemplate() {
    QString templateS = ui->newTemplate->text();

    if (templateS.isEmpty())
        return;

    ui->templates->addItem(templateS);
}

void CreatureManager::removeTemplate() {
    if (ui->templates->count() == 0)
        return;

    ui->templates->removeItem(ui->templates->currentIndex());
}

void CreatureManager::addLootGroup() {
    QString lootGroup = ui->newLootGroup->text();

    if (lootGroup.isEmpty())
        return;

    ui->lootGroups->addItem(lootGroup);
}

void CreatureManager::removeLootGroup() {
    if (ui->lootGroups->count() == 0)
        return;

    ui->lootGroups->removeItem(ui->lootGroups->currentIndex());
}

void CreatureManager::saveCurrentCreature() {
    if (currentCreatureObject == NULL)
        return;

    currentCreatureObject->setObjectName(ui->objectName->text());
    currentCreatureObject->setPvpFaction(ui->pvpFaction->text());
    currentCreatureObject->setSocialGroup(ui->socialGroup->text());
    currentCreatureObject->setArmor(ui->armor->value());
    currentCreatureObject->setBaseHAM(ui->baseHAM->value());
    currentCreatureObject->setBaseHAMmax(ui->baseHAMmax->value());
    currentCreatureObject->setBaseXp(ui->baseXp->value());
    currentCreatureObject->setMinDamage(ui->minDamage->value());
    currentCreatureObject->setLevel(ui->level->value());
    currentCreatureObject->setChanceHit(ui->chanceHit->value());

    int pvpBitmask = 0;

    if (ui->overt->isChecked())
        pvpBitmask |= CreatureObject::OVERT;

    if (ui->aggressive->isChecked())
        pvpBitmask |= CreatureObject::AGGRESSIVE;

    if (ui->attackable->isChecked())
        pvpBitmask |= CreatureObject::ATTACKABLE;

    if (ui->enemy->isChecked())
        pvpBitmask |= CreatureObject::ENEMY;

    currentCreatureObject->setPvpBitmask(pvpBitmask);

    int creatureBitmask = 0;

    if (ui->herd->isChecked())
        creatureBitmask |= CreatureObject::HERD;

    if (ui->pack->isChecked())
        creatureBitmask |= CreatureObject::PACK;

    if (ui->killer->isChecked())
        creatureBitmask |= CreatureObject::KILLER;

    if (ui->baby->isChecked())
        creatureBitmask |= CreatureObject::BABY;

    if (ui->lair->isChecked())
        creatureBitmask |= CreatureObject::LAIR;

    if (ui->stalker->isChecked())
        creatureBitmask |= CreatureObject::STALKER;

    currentCreatureObject->setCreatureBitmask(creatureBitmask);

    int dietBitmask = 0;

    if (ui->herbivore->isChecked())
        dietBitmask |= CreatureObject::HERBIVORE;

    if (ui->carnivore->isChecked())
        creatureBitmask |= CreatureObject::CARNIVORE;

    currentCreatureObject->setDietBitmask(dietBitmask);

    QVector<float> resists;

    resists.append(ui->kinetic->value());
    resists.append(ui->energy->value());
    resists.append(ui->blast->value());
    resists.append(ui->heat->value());
    resists.append(ui->cold->value());
    resists.append(ui->electricity->value());
    resists.append(ui->acid->value());
    resists.append(ui->stun->value());
    resists.append(ui->lightsaber->value());

    currentCreatureObject->setResists(resists);

    currentCreatureObject->setMaxDamage(ui->maxDamage->value());
    currentCreatureObject->setMeatType(ui->meatType->text());
    currentCreatureObject->setMeatAmount(ui->meatAmount->value());
    currentCreatureObject->setHideType(ui->hideType->text());
    currentCreatureObject->setHideAmount(ui->hideAmount->value());
    currentCreatureObject->setBoneAmount(ui->boneAmount->value());
    currentCreatureObject->setBoneType(ui->boneType->text());

    currentCreatureObject->setMilk(ui->milk->value());
    currentCreatureObject->setTamingChance(ui->tamingChance->value());
    currentCreatureObject->setFerocity(ui->ferocity->value());

    QVector<QString> templates;
    for (int i = 0; i < ui->templates->count(); ++i) {
        templates.append(ui->templates->itemText(i));
    }

    currentCreatureObject->setTemplates(templates);

    QVector<QString> weapons;
    for (int i = 0; i < ui->weapons->count(); ++i) {
        weapons.append(ui->weapons->itemText(i));
    }

    currentCreatureObject->setWeapons(weapons);

    QVector<QString> lootGroups;

    for (int i = 0; i < ui->lootGroups->count(); ++i)
        lootGroups.append(ui->lootGroups->itemText(i));

    currentCreatureObject->setLootGroups(lootGroups);

    //mainWindow->outputToConsole(currentCreatureObject->serializeToLua());

    QString filename = currentCreatureObject->getFileName();
    QString serverDir = MainWindow::instance->getSettings()->getServerDirectory();

    if (serverDir.isEmpty()) {
        MainWindow::instance->warning("No Core3 server directory specified");

        return;
    }

    QString fullDir = serverDir + "/bin/scripts/mobile/" + filename;

    QFile file(fullDir);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << currentCreatureObject->serializeToLua();

        file.close();
    } else {
        MainWindow::instance->warning("Could not open " + fullDir);

        return;
    }

    /*
    ui->attackList->clear();

    QMap<QString, QString>* attacks = currentCreatureObject->getAttacks();

    QMapIterator<QString, QString> i(*attacks);

    while (i.hasNext()) {
        i.next();

        ui->attackList->addItem(i.key() + ":" + i.value());
    }*/
}

void CreatureManager::reloadCreature() {
    if (currentCreatureObject == NULL)
        return;

    ui->objectName->setText(currentCreatureObject->getObjectName());
    ui->pvpFaction->setText(currentCreatureObject->getPvpFaction());
    ui->socialGroup->setText(currentCreatureObject->getSocialGroup());
    ui->armor->setValue(currentCreatureObject->getArmor());
    ui->baseHAM->setValue(currentCreatureObject->getBaseHAM());
    ui->baseHAMmax->setValue(currentCreatureObject->getBaseHAMmax());
    ui->baseXp->setValue(currentCreatureObject->getBaseXp());
    ui->minDamage->setValue(currentCreatureObject->getMinDamage());
    ui->level->setValue(currentCreatureObject->getLevel());
    ui->chanceHit->setValue(currentCreatureObject->getChanceHit());

    ui->overt->setChecked(currentCreatureObject->hasPvpFlag(CreatureObject::OVERT));
    ui->aggressive->setChecked(currentCreatureObject->hasPvpFlag(CreatureObject::AGGRESSIVE));
    ui->attackable->setChecked(currentCreatureObject->hasPvpFlag(CreatureObject::ATTACKABLE));
    ui->enemy->setChecked(currentCreatureObject->hasPvpFlag(CreatureObject::ENEMY));

    ui->herd->setChecked(currentCreatureObject->hasCreatureFlag(CreatureObject::HERD));
    ui->pack->setChecked(currentCreatureObject->hasCreatureFlag(CreatureObject::PACK));
    ui->killer->setChecked(currentCreatureObject->hasCreatureFlag(CreatureObject::KILLER));
    ui->baby->setChecked(currentCreatureObject->hasCreatureFlag(CreatureObject::BABY));
    ui->lair->setChecked(currentCreatureObject->hasCreatureFlag(CreatureObject::LAIR));
    ui->stalker->setChecked(currentCreatureObject->hasCreatureFlag(CreatureObject::STALKER));

    ui->herbivore->setChecked(currentCreatureObject->hasDietFlag(CreatureObject::HERBIVORE));
    ui->carnivore->setChecked(currentCreatureObject->hasDietFlag(CreatureObject::CARNIVORE));

    QVector<float>* resists = currentCreatureObject->getResists();

    if (resists->size() == 9) {
        ui->kinetic->setValue(resists->at(0));
        ui->energy->setValue(resists->at(1));
        ui->blast->setValue(resists->at(2));
        ui->heat->setValue(resists->at(3));
        ui->cold->setValue(resists->at(4));
        ui->electricity->setValue(resists->at(5));
        ui->acid->setValue(resists->at(6));
        ui->stun->setValue(resists->at(7));
        ui->lightsaber->setValue(resists->at(8));
    }

    ui->maxDamage->setValue(currentCreatureObject->getMaxDamage());

    ui->meatType->setText(currentCreatureObject->getMeatType());
    ui->meatAmount->setValue(currentCreatureObject->getMeatAmount());
    ui->hideType->setText(currentCreatureObject->getHideType());
    ui->hideAmount->setValue(currentCreatureObject->getHideAmount());
    ui->boneAmount->setValue(currentCreatureObject->getBoneAmount());
    ui->boneType->setText(currentCreatureObject->getBoneType());
    ui->milk->setValue(currentCreatureObject->getMilk());
    ui->tamingChance->setValue(currentCreatureObject->getTamingChance());
    ui->ferocity->setValue(currentCreatureObject->getFerocity());
    ui->lineEdit_ConversationTemplate->setText(currentCreatureObject->getConverstationTemplate());

    ui->templates->clear();

    QVector<QString>* templates = currentCreatureObject->getTemplates();

    for (int i = 0; i < templates->size(); ++i) {
        ui->templates->addItem(templates->at(i));
    }

    ui->weapons->clear();

    QVector<QString>* weapons = currentCreatureObject->getWeapons();

    for (int i = 0; i < weapons->size(); ++i)
        ui->weapons->addItem(weapons->at(i));

    ui->attackList->clear();

    QMap<QString, QString>* attacks = currentCreatureObject->getAttacks();

    QMapIterator<QString, QString> i(*attacks);

    while (i.hasNext()) {
        i.next();

        ui->attackList->addItem(i.key() + ":" + i.value());
    }

    QVector<QString>* lootGroups = currentCreatureObject->getLootGroups();

    ui->lootGroups->clear();

    for (int i = 0; i < lootGroups->size(); ++i)
        ui->lootGroups->addItem(lootGroups->at(i));

    optionBitSelectionChanged();
}

void CreatureManager::optionBitSelectionChanged() {
    int currentBit = ui->comboBox_OptionsBitmask->currentIndex();

    if (currentBit > -1) {
        ui->checkBox_optionsBitmask->setChecked(currentCreatureObject->getOptionsBitmask() & (1 << currentBit));
    }
}

void CreatureManager::optionBitValueChanged() {
    int val = 1 << ui->comboBox_OptionsBitmask->currentIndex();

    currentCreatureObject->setOptionsBitmaskBit(val, ui->checkBox_optionsBitmask->isChecked());
}

void CreatureManager::currentCreatureChanged(const QString& text) {
    if (!creatureMap.contains(text))
        return;

    currentCreatureObject = creatureMap.value(text);

    reloadCreature();
}
/*
CreatureObject* CreatureManager::parseCreatureObject(const QString& fileName) {
    QString serverDir = mainWindow->getSettings()->getServerDirectory();

    QString fullName = serverDir + "/bin/scripts/mobile/" + fileName;
    QFile objectsFile(fullName);

    if (!objectsFile.open(QIODevice::ReadOnly)) {
        mainWindow->warning("could not open " + fullName);
        return NULL;
    }

    QByteArray buffer = objectsFile.readAll();

    int i = 0;

    QString objectName = parseName(buffer, i);

    //mainWindow->outputToConsole("parsed name " + objectName);

    CreatureObject* creature = new CreatureObject(objectName);

    parseVariables(buffer, creature, i);

    return creature;
}

void CreatureManager::parseVariableData(QByteArray& buffer, CreatureObject* creatureObject, int& currentPosition, QString& name, QString& variableData) {
    QString token;
    QTextStream stream(&token);

    bool open = false;

    while (currentPosition < buffer.size()) {
        char c = buffer[currentPosition++];

        switch (c) {
        case '{':
            if (!open) {
                open = true;
                stream << c;
            } else {
                variableData += token.simplified();

                parseVariableData(buffer, creatureObject, --currentPosition, name, variableData);

                token.clear();
            }

            break;
        case '}':
            stream << c;

            open = false;

            variableData += token.simplified();

            return;
            break;

        case ',':
            if (!open) {
                variableData += token.simplified();

                return;
            } else {
                stream << c;
            }

            break;

        default:
            stream << c;
            break;
        }
    }
}

void CreatureManager::parseVariables(QByteArray& buffer, CreatureObject* creatureObject, int& currentPosition) {
    bool ignoring = true;

    QString token;
    QTextStream stream(&token);

    QString variable;
    QString variableData;

    bool open = false;

    while (currentPosition < buffer.size()) {
        char c = buffer[currentPosition++];

        switch(c) {

        case '{': {

            if (!open) {
                ignoring = false;
                open = true;
            }

            break;
        }

        case '-':
            ignoring = true;
            token.clear();

            break;

        case '}':
            return;

        case '=':
            variable = token.simplified();
            token.clear();

            parseVariableData(buffer, creatureObject, currentPosition, variable, variableData);

            creatureObject->setVariable(variable, variableData);

            variable.clear();
            variableData.clear();
            break;

        case '\n':
            ignoring = false;

            break;

        case ',':
            token.clear();
            break;
        default:
            if (!ignoring)
                stream << c;

            break;
        }
    }
}

QString CreatureManager::parseName(QByteArray& buffer, int& currentPosition) {
    bool ignoring = false;

    QString token;
    QTextStream stream(&token);

    while (currentPosition < buffer.size()) {
        char c = buffer[currentPosition++];

        switch(c) {
        case '=':
            return token.simplified();
            break;
        case '-':
            ignoring = true;
            break;
        case '\t':
        case '\n':
            ignoring = false;
            break;
        default:
            if (!ignoring)
                stream << c;

            break;
        }
    }

    mainWindow->warning("unexpected EOF while trying to parse object name");

    return QString("");
}
*/
