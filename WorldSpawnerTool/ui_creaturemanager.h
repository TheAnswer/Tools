/********************************************************************************
** Form generated from reading UI file 'creaturemanager.ui'
**
** Created: Fri Dec 30 10:32:40 2011
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATUREMANAGER_H
#define UI_CREATUREMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatureManager
{
public:
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_11;
    QLabel *label_13;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label_12;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *reloadCreature;
    QPushButton *saveCreature;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *objectName;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *socialGroup;
    QLineEdit *pvpFaction;
    QLabel *label_4;
    QSpinBox *level;
    QLabel *label_5;
    QDoubleSpinBox *chanceHit;
    QLabel *label_6;
    QSpinBox *minDamage;
    QLabel *label_7;
    QSpinBox *baseXp;
    QLabel *label_8;
    QSpinBox *baseHAM;
    QLabel *label_9;
    QSpinBox *baseHAMmax;
    QLabel *label_10;
    QSpinBox *armor;
    QLabel *label_11;
    QSpinBox *maxDamage;
    QLabel *label_27;
    QLineEdit *meatType;
    QLabel *label_28;
    QSpinBox *meatAmount;
    QLabel *label_29;
    QLineEdit *hideType;
    QLabel *label_30;
    QSpinBox *hideAmount;
    QLabel *label_31;
    QLineEdit *boneType;
    QLabel *label_32;
    QSpinBox *boneAmount;
    QLabel *label_33;
    QSpinBox *milk;
    QLabel *label_42;
    QLabel *label_34;
    QDoubleSpinBox *tamingChance;
    QLabel *label_35;
    QSpinBox *ferocity;
    QLineEdit *lineEdit_ConversationTemplate;
    QGridLayout *gridLayout_10;
    QLabel *label_14;
    QCheckBox *attackable;
    QCheckBox *aggressive;
    QCheckBox *overt;
    QCheckBox *enemy;
    QLabel *label_15;
    QCheckBox *pack;
    QCheckBox *herd;
    QCheckBox *killer;
    QCheckBox *stalker;
    QCheckBox *baby;
    QCheckBox *lair;
    QLabel *label_16;
    QCheckBox *carnivore;
    QCheckBox *herbivore;
    QCheckBox *checkBox_healer;
    QGridLayout *gridLayout_2;
    QProgressBar *progressBar;
    QGridLayout *gridLayout_3;
    QLabel *label_17;
    QLabel *label_18;
    QDoubleSpinBox *kinetic;
    QLabel *label_19;
    QDoubleSpinBox *energy;
    QLabel *label_20;
    QDoubleSpinBox *blast;
    QLabel *label_21;
    QDoubleSpinBox *heat;
    QLabel *label_22;
    QDoubleSpinBox *cold;
    QLabel *label_23;
    QDoubleSpinBox *electricity;
    QLabel *label_24;
    QDoubleSpinBox *acid;
    QLabel *label_25;
    QDoubleSpinBox *stun;
    QLabel *label_26;
    QDoubleSpinBox *lightsaber;
    QGridLayout *gridLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *templates;
    QPushButton *removeTemplate;
    QGridLayout *gridLayout_9;
    QLabel *label_36;
    QLineEdit *newTemplate;
    QGridLayout *gridLayout_5;
    QPushButton *addTemplate;
    QPushButton *pushButton_view3d;
    QGridLayout *gridLayout_8;
    QLabel *label_40;
    QComboBox *lootGroups;
    QPushButton *removeLootGroup;
    QLineEdit *newLootGroup;
    QPushButton *addLoutGroup;
    QGridLayout *gridLayout_6;
    QLabel *label_37;
    QComboBox *weapons;
    QLineEdit *newWeapon;
    QPushButton *removeWeapon;
    QPushButton *addWeapon;
    QGridLayout *gridLayout_7;
    QLabel *label_38;
    QListWidget *attackList;
    QPushButton *pushButton_addAttack;
    QPushButton *pushButton_removeAttack;
    QDialogButtonBox *buttonBox;
    QGridLayout *gridLayout_4;
    QLabel *label_41;
    QComboBox *comboBox_OptionsBitmask;
    QCheckBox *checkBox_optionsBitmask;

    void setupUi(QDialog *CreatureManager)
    {
        if (CreatureManager->objectName().isEmpty())
            CreatureManager->setObjectName(QString::fromUtf8("CreatureManager"));
        CreatureManager->resize(979, 585);
        CreatureManager->setSizeGripEnabled(true);
        horizontalLayout_3 = new QHBoxLayout(CreatureManager);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        scrollArea = new QScrollArea(CreatureManager);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -73, 942, 839));
        gridLayout_13 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_11->addWidget(label_13, 0, 1, 1, 1);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(300, 0));

        gridLayout_11->addWidget(comboBox, 1, 0, 1, 1);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_11->addWidget(lineEdit, 1, 1, 1, 1);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_11->addWidget(label_12, 0, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_11, 0, 0, 1, 4);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_13->addWidget(pushButton, 0, 4, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        reloadCreature = new QPushButton(scrollAreaWidgetContents);
        reloadCreature->setObjectName(QString::fromUtf8("reloadCreature"));
        reloadCreature->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(reloadCreature);

        saveCreature = new QPushButton(scrollAreaWidgetContents);
        saveCreature->setObjectName(QString::fromUtf8("saveCreature"));
        saveCreature->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(saveCreature);


        gridLayout_13->addLayout(horizontalLayout, 0, 7, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        objectName = new QLineEdit(scrollAreaWidgetContents);
        objectName->setObjectName(QString::fromUtf8("objectName"));

        gridLayout->addWidget(objectName, 0, 1, 1, 1);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        socialGroup = new QLineEdit(scrollAreaWidgetContents);
        socialGroup->setObjectName(QString::fromUtf8("socialGroup"));

        gridLayout->addWidget(socialGroup, 1, 1, 1, 1);

        pvpFaction = new QLineEdit(scrollAreaWidgetContents);
        pvpFaction->setObjectName(QString::fromUtf8("pvpFaction"));

        gridLayout->addWidget(pvpFaction, 2, 1, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        level = new QSpinBox(scrollAreaWidgetContents);
        level->setObjectName(QString::fromUtf8("level"));
        level->setMaximum(1000);

        gridLayout->addWidget(level, 3, 1, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        chanceHit = new QDoubleSpinBox(scrollAreaWidgetContents);
        chanceHit->setObjectName(QString::fromUtf8("chanceHit"));

        gridLayout->addWidget(chanceHit, 4, 1, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        minDamage = new QSpinBox(scrollAreaWidgetContents);
        minDamage->setObjectName(QString::fromUtf8("minDamage"));
        minDamage->setMaximum(10000);

        gridLayout->addWidget(minDamage, 5, 1, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        baseXp = new QSpinBox(scrollAreaWidgetContents);
        baseXp->setObjectName(QString::fromUtf8("baseXp"));
        baseXp->setMaximum(10000000);

        gridLayout->addWidget(baseXp, 7, 1, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        baseHAM = new QSpinBox(scrollAreaWidgetContents);
        baseHAM->setObjectName(QString::fromUtf8("baseHAM"));
        baseHAM->setMaximum(100000000);

        gridLayout->addWidget(baseHAM, 8, 1, 1, 1);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 9, 0, 1, 1);

        baseHAMmax = new QSpinBox(scrollAreaWidgetContents);
        baseHAMmax->setObjectName(QString::fromUtf8("baseHAMmax"));
        baseHAMmax->setMaximum(10000000);

        gridLayout->addWidget(baseHAMmax, 9, 1, 1, 1);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 10, 0, 1, 1);

        armor = new QSpinBox(scrollAreaWidgetContents);
        armor->setObjectName(QString::fromUtf8("armor"));

        gridLayout->addWidget(armor, 10, 1, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        maxDamage = new QSpinBox(scrollAreaWidgetContents);
        maxDamage->setObjectName(QString::fromUtf8("maxDamage"));
        maxDamage->setMaximum(1000000);

        gridLayout->addWidget(maxDamage, 6, 1, 1, 1);

        label_27 = new QLabel(scrollAreaWidgetContents);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_27, 11, 0, 1, 1);

        meatType = new QLineEdit(scrollAreaWidgetContents);
        meatType->setObjectName(QString::fromUtf8("meatType"));

        gridLayout->addWidget(meatType, 11, 1, 1, 1);

        label_28 = new QLabel(scrollAreaWidgetContents);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 12, 0, 1, 1);

        meatAmount = new QSpinBox(scrollAreaWidgetContents);
        meatAmount->setObjectName(QString::fromUtf8("meatAmount"));
        meatAmount->setMaximum(1000000);

        gridLayout->addWidget(meatAmount, 12, 1, 1, 1);

        label_29 = new QLabel(scrollAreaWidgetContents);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 13, 0, 1, 1);

        hideType = new QLineEdit(scrollAreaWidgetContents);
        hideType->setObjectName(QString::fromUtf8("hideType"));

        gridLayout->addWidget(hideType, 13, 1, 1, 1);

        label_30 = new QLabel(scrollAreaWidgetContents);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 14, 0, 1, 1);

        hideAmount = new QSpinBox(scrollAreaWidgetContents);
        hideAmount->setObjectName(QString::fromUtf8("hideAmount"));
        hideAmount->setMaximum(10000000);

        gridLayout->addWidget(hideAmount, 14, 1, 1, 1);

        label_31 = new QLabel(scrollAreaWidgetContents);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_31, 15, 0, 1, 1);

        boneType = new QLineEdit(scrollAreaWidgetContents);
        boneType->setObjectName(QString::fromUtf8("boneType"));

        gridLayout->addWidget(boneType, 15, 1, 1, 1);

        label_32 = new QLabel(scrollAreaWidgetContents);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_32, 16, 0, 1, 1);

        boneAmount = new QSpinBox(scrollAreaWidgetContents);
        boneAmount->setObjectName(QString::fromUtf8("boneAmount"));
        boneAmount->setMaximum(1000000);

        gridLayout->addWidget(boneAmount, 16, 1, 1, 1);

        label_33 = new QLabel(scrollAreaWidgetContents);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_33, 17, 0, 1, 1);

        milk = new QSpinBox(scrollAreaWidgetContents);
        milk->setObjectName(QString::fromUtf8("milk"));
        milk->setMaximum(1000000);

        gridLayout->addWidget(milk, 17, 1, 1, 1);

        label_42 = new QLabel(scrollAreaWidgetContents);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout->addWidget(label_42, 18, 0, 1, 1);

        label_34 = new QLabel(scrollAreaWidgetContents);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout->addWidget(label_34, 19, 0, 1, 1);

        tamingChance = new QDoubleSpinBox(scrollAreaWidgetContents);
        tamingChance->setObjectName(QString::fromUtf8("tamingChance"));
        tamingChance->setMaximum(100);

        gridLayout->addWidget(tamingChance, 19, 1, 1, 1);

        label_35 = new QLabel(scrollAreaWidgetContents);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout->addWidget(label_35, 20, 0, 1, 1);

        ferocity = new QSpinBox(scrollAreaWidgetContents);
        ferocity->setObjectName(QString::fromUtf8("ferocity"));
        ferocity->setMaximum(100000);

        gridLayout->addWidget(ferocity, 20, 1, 1, 1);

        lineEdit_ConversationTemplate = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_ConversationTemplate->setObjectName(QString::fromUtf8("lineEdit_ConversationTemplate"));

        gridLayout->addWidget(lineEdit_ConversationTemplate, 18, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout, 1, 0, 5, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(16777215, 20));

        gridLayout_10->addWidget(label_14, 0, 0, 1, 1);

        attackable = new QCheckBox(scrollAreaWidgetContents);
        attackable->setObjectName(QString::fromUtf8("attackable"));

        gridLayout_10->addWidget(attackable, 1, 0, 1, 1);

        aggressive = new QCheckBox(scrollAreaWidgetContents);
        aggressive->setObjectName(QString::fromUtf8("aggressive"));

        gridLayout_10->addWidget(aggressive, 2, 0, 1, 1);

        overt = new QCheckBox(scrollAreaWidgetContents);
        overt->setObjectName(QString::fromUtf8("overt"));

        gridLayout_10->addWidget(overt, 3, 0, 1, 1);

        enemy = new QCheckBox(scrollAreaWidgetContents);
        enemy->setObjectName(QString::fromUtf8("enemy"));

        gridLayout_10->addWidget(enemy, 4, 0, 1, 1);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(16777215, 20));

        gridLayout_10->addWidget(label_15, 5, 0, 1, 1);

        pack = new QCheckBox(scrollAreaWidgetContents);
        pack->setObjectName(QString::fromUtf8("pack"));

        gridLayout_10->addWidget(pack, 6, 0, 1, 1);

        herd = new QCheckBox(scrollAreaWidgetContents);
        herd->setObjectName(QString::fromUtf8("herd"));

        gridLayout_10->addWidget(herd, 7, 0, 1, 1);

        killer = new QCheckBox(scrollAreaWidgetContents);
        killer->setObjectName(QString::fromUtf8("killer"));

        gridLayout_10->addWidget(killer, 8, 0, 1, 1);

        stalker = new QCheckBox(scrollAreaWidgetContents);
        stalker->setObjectName(QString::fromUtf8("stalker"));

        gridLayout_10->addWidget(stalker, 9, 0, 1, 1);

        baby = new QCheckBox(scrollAreaWidgetContents);
        baby->setObjectName(QString::fromUtf8("baby"));

        gridLayout_10->addWidget(baby, 10, 0, 1, 1);

        lair = new QCheckBox(scrollAreaWidgetContents);
        lair->setObjectName(QString::fromUtf8("lair"));

        gridLayout_10->addWidget(lair, 11, 0, 1, 1);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMaximumSize(QSize(16777215, 20));

        gridLayout_10->addWidget(label_16, 13, 0, 1, 1);

        carnivore = new QCheckBox(scrollAreaWidgetContents);
        carnivore->setObjectName(QString::fromUtf8("carnivore"));

        gridLayout_10->addWidget(carnivore, 14, 0, 1, 1);

        herbivore = new QCheckBox(scrollAreaWidgetContents);
        herbivore->setObjectName(QString::fromUtf8("herbivore"));

        gridLayout_10->addWidget(herbivore, 15, 0, 1, 1);

        checkBox_healer = new QCheckBox(scrollAreaWidgetContents);
        checkBox_healer->setObjectName(QString::fromUtf8("checkBox_healer"));

        gridLayout_10->addWidget(checkBox_healer, 12, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_10, 1, 1, 4, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        progressBar = new QProgressBar(scrollAreaWidgetContents);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 2, 0, 1, 2);


        gridLayout_13->addLayout(gridLayout_2, 1, 5, 1, 2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(0, 20));
        label_17->setMaximumSize(QSize(16777215, 20));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_17, 0, 0, 1, 1);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_18, 1, 0, 1, 1);

        kinetic = new QDoubleSpinBox(scrollAreaWidgetContents);
        kinetic->setObjectName(QString::fromUtf8("kinetic"));
        kinetic->setMinimum(-1);
        kinetic->setMaximum(100);

        gridLayout_3->addWidget(kinetic, 1, 1, 1, 1);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_19, 2, 0, 1, 1);

        energy = new QDoubleSpinBox(scrollAreaWidgetContents);
        energy->setObjectName(QString::fromUtf8("energy"));
        energy->setMinimum(-1);
        energy->setMaximum(100);

        gridLayout_3->addWidget(energy, 2, 1, 1, 1);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_20, 3, 0, 1, 1);

        blast = new QDoubleSpinBox(scrollAreaWidgetContents);
        blast->setObjectName(QString::fromUtf8("blast"));
        blast->setMinimum(-1);
        blast->setMaximum(100);

        gridLayout_3->addWidget(blast, 3, 1, 1, 1);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_21, 4, 0, 1, 1);

        heat = new QDoubleSpinBox(scrollAreaWidgetContents);
        heat->setObjectName(QString::fromUtf8("heat"));
        heat->setMinimum(-1);
        heat->setMaximum(100);

        gridLayout_3->addWidget(heat, 4, 1, 1, 1);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_22, 5, 0, 1, 1);

        cold = new QDoubleSpinBox(scrollAreaWidgetContents);
        cold->setObjectName(QString::fromUtf8("cold"));
        cold->setMinimum(-1);
        cold->setMaximum(100);

        gridLayout_3->addWidget(cold, 5, 1, 1, 1);

        label_23 = new QLabel(scrollAreaWidgetContents);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_23, 6, 0, 1, 1);

        electricity = new QDoubleSpinBox(scrollAreaWidgetContents);
        electricity->setObjectName(QString::fromUtf8("electricity"));
        electricity->setMinimum(-1);
        electricity->setMaximum(100);

        gridLayout_3->addWidget(electricity, 6, 1, 1, 1);

        label_24 = new QLabel(scrollAreaWidgetContents);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_24, 7, 0, 1, 1);

        acid = new QDoubleSpinBox(scrollAreaWidgetContents);
        acid->setObjectName(QString::fromUtf8("acid"));
        acid->setMinimum(-1);
        acid->setMaximum(100);

        gridLayout_3->addWidget(acid, 7, 1, 1, 1);

        label_25 = new QLabel(scrollAreaWidgetContents);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_25, 8, 0, 1, 1);

        stun = new QDoubleSpinBox(scrollAreaWidgetContents);
        stun->setObjectName(QString::fromUtf8("stun"));
        stun->setMinimum(-1);
        stun->setMaximum(100);

        gridLayout_3->addWidget(stun, 8, 1, 1, 1);

        label_26 = new QLabel(scrollAreaWidgetContents);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_26, 9, 0, 1, 1);

        lightsaber = new QDoubleSpinBox(scrollAreaWidgetContents);
        lightsaber->setObjectName(QString::fromUtf8("lightsaber"));
        lightsaber->setMinimum(-1);
        lightsaber->setMaximum(100);

        gridLayout_3->addWidget(lightsaber, 9, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_3, 2, 3, 2, 3);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        templates = new QComboBox(scrollAreaWidgetContents);
        templates->setObjectName(QString::fromUtf8("templates"));
        templates->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(templates);

        removeTemplate = new QPushButton(scrollAreaWidgetContents);
        removeTemplate->setObjectName(QString::fromUtf8("removeTemplate"));

        horizontalLayout_2->addWidget(removeTemplate);


        gridLayout_12->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_36 = new QLabel(scrollAreaWidgetContents);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_9->addWidget(label_36, 0, 0, 1, 1);

        newTemplate = new QLineEdit(scrollAreaWidgetContents);
        newTemplate->setObjectName(QString::fromUtf8("newTemplate"));

        gridLayout_9->addWidget(newTemplate, 0, 1, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        addTemplate = new QPushButton(scrollAreaWidgetContents);
        addTemplate->setObjectName(QString::fromUtf8("addTemplate"));
        addTemplate->setMaximumSize(QSize(120, 16777215));

        gridLayout_5->addWidget(addTemplate, 0, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_5, 1, 1, 1, 1);

        pushButton_view3d = new QPushButton(scrollAreaWidgetContents);
        pushButton_view3d->setObjectName(QString::fromUtf8("pushButton_view3d"));

        gridLayout_9->addWidget(pushButton_view3d, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_9, 1, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 2, 6, 1, 2);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_40 = new QLabel(scrollAreaWidgetContents);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_8->addWidget(label_40, 0, 0, 1, 1);

        lootGroups = new QComboBox(scrollAreaWidgetContents);
        lootGroups->setObjectName(QString::fromUtf8("lootGroups"));

        gridLayout_8->addWidget(lootGroups, 0, 1, 1, 2);

        removeLootGroup = new QPushButton(scrollAreaWidgetContents);
        removeLootGroup->setObjectName(QString::fromUtf8("removeLootGroup"));

        gridLayout_8->addWidget(removeLootGroup, 0, 3, 1, 1);

        newLootGroup = new QLineEdit(scrollAreaWidgetContents);
        newLootGroup->setObjectName(QString::fromUtf8("newLootGroup"));

        gridLayout_8->addWidget(newLootGroup, 1, 0, 1, 2);

        addLoutGroup = new QPushButton(scrollAreaWidgetContents);
        addLoutGroup->setObjectName(QString::fromUtf8("addLoutGroup"));
        addLoutGroup->setMaximumSize(QSize(120, 16777215));

        gridLayout_8->addWidget(addLoutGroup, 1, 2, 1, 2);


        gridLayout_13->addLayout(gridLayout_8, 3, 6, 1, 2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_37 = new QLabel(scrollAreaWidgetContents);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_6->addWidget(label_37, 2, 0, 1, 1);

        weapons = new QComboBox(scrollAreaWidgetContents);
        weapons->setObjectName(QString::fromUtf8("weapons"));

        gridLayout_6->addWidget(weapons, 2, 1, 1, 2);

        newWeapon = new QLineEdit(scrollAreaWidgetContents);
        newWeapon->setObjectName(QString::fromUtf8("newWeapon"));

        gridLayout_6->addWidget(newWeapon, 3, 0, 1, 2);

        removeWeapon = new QPushButton(scrollAreaWidgetContents);
        removeWeapon->setObjectName(QString::fromUtf8("removeWeapon"));

        gridLayout_6->addWidget(removeWeapon, 0, 2, 1, 1);

        addWeapon = new QPushButton(scrollAreaWidgetContents);
        addWeapon->setObjectName(QString::fromUtf8("addWeapon"));

        gridLayout_6->addWidget(addWeapon, 3, 2, 1, 1);


        gridLayout_13->addLayout(gridLayout_6, 5, 1, 1, 4);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_38 = new QLabel(scrollAreaWidgetContents);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_7->addWidget(label_38, 0, 0, 1, 1);

        attackList = new QListWidget(scrollAreaWidgetContents);
        attackList->setObjectName(QString::fromUtf8("attackList"));

        gridLayout_7->addWidget(attackList, 1, 0, 1, 2);

        pushButton_addAttack = new QPushButton(scrollAreaWidgetContents);
        pushButton_addAttack->setObjectName(QString::fromUtf8("pushButton_addAttack"));

        gridLayout_7->addWidget(pushButton_addAttack, 2, 0, 1, 1);

        pushButton_removeAttack = new QPushButton(scrollAreaWidgetContents);
        pushButton_removeAttack->setObjectName(QString::fromUtf8("pushButton_removeAttack"));

        gridLayout_7->addWidget(pushButton_removeAttack, 2, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_7, 5, 5, 1, 3);

        buttonBox = new QDialogButtonBox(scrollAreaWidgetContents);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_13->addWidget(buttonBox, 6, 7, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_41 = new QLabel(scrollAreaWidgetContents);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(0, 20));
        label_41->setMaximumSize(QSize(16777215, 20));

        gridLayout_4->addWidget(label_41, 0, 0, 1, 1);

        comboBox_OptionsBitmask = new QComboBox(scrollAreaWidgetContents);
        comboBox_OptionsBitmask->setObjectName(QString::fromUtf8("comboBox_OptionsBitmask"));
        comboBox_OptionsBitmask->setMinimumSize(QSize(121, 22));

        gridLayout_4->addWidget(comboBox_OptionsBitmask, 1, 0, 1, 1);

        checkBox_optionsBitmask = new QCheckBox(scrollAreaWidgetContents);
        checkBox_optionsBitmask->setObjectName(QString::fromUtf8("checkBox_optionsBitmask"));

        gridLayout_4->addWidget(checkBox_optionsBitmask, 1, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_4, 4, 7, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);


        retranslateUi(CreatureManager);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreatureManager, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreatureManager, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreatureManager);
    } // setupUi

    void retranslateUi(QDialog *CreatureManager)
    {
        CreatureManager->setWindowTitle(QApplication::translate("CreatureManager", "Creature Tool", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("CreatureManager", "Search", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CreatureManager", "File", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CreatureManager", "Load objects", 0, QApplication::UnicodeUTF8));
        reloadCreature->setText(QApplication::translate("CreatureManager", "Reload Creature", 0, QApplication::UnicodeUTF8));
        saveCreature->setText(QApplication::translate("CreatureManager", "Save Creature", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreatureManager", "Object Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreatureManager", "Social Group", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreatureManager", "Pvp Faction", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreatureManager", "Level", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreatureManager", "Hit Chance", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CreatureManager", "Min Damage", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CreatureManager", "Base XP", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CreatureManager", "Base HAM", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CreatureManager", "Base HAM Max", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CreatureManager", "Armor", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CreatureManager", "Max Damage", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("CreatureManager", "Meat type", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("CreatureManager", "Meat amount", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("CreatureManager", "Hide type", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("CreatureManager", "Hide amount", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("CreatureManager", "Bone type", 0, QApplication::UnicodeUTF8));
        boneType->setText(QString());
        label_32->setText(QApplication::translate("CreatureManager", "Bone amount", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("CreatureManager", "Milk", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("CreatureManager", "Convo Template", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("CreatureManager", "Taming chance", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("CreatureManager", "Ferocity", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("CreatureManager", "Pvp Bitmask", 0, QApplication::UnicodeUTF8));
        attackable->setText(QApplication::translate("CreatureManager", "Attackable", 0, QApplication::UnicodeUTF8));
        aggressive->setText(QApplication::translate("CreatureManager", "Aggressive", 0, QApplication::UnicodeUTF8));
        overt->setText(QApplication::translate("CreatureManager", "Overt", 0, QApplication::UnicodeUTF8));
        enemy->setText(QApplication::translate("CreatureManager", "Enemy", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("CreatureManager", "Creature Bitmask", 0, QApplication::UnicodeUTF8));
        pack->setText(QApplication::translate("CreatureManager", "Pack", 0, QApplication::UnicodeUTF8));
        herd->setText(QApplication::translate("CreatureManager", "Herd", 0, QApplication::UnicodeUTF8));
        killer->setText(QApplication::translate("CreatureManager", "Killer", 0, QApplication::UnicodeUTF8));
        stalker->setText(QApplication::translate("CreatureManager", "Stalker", 0, QApplication::UnicodeUTF8));
        baby->setText(QApplication::translate("CreatureManager", "Baby", 0, QApplication::UnicodeUTF8));
        lair->setText(QApplication::translate("CreatureManager", "Lair", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("CreatureManager", "Diet", 0, QApplication::UnicodeUTF8));
        carnivore->setText(QApplication::translate("CreatureManager", "Carnivore", 0, QApplication::UnicodeUTF8));
        herbivore->setText(QApplication::translate("CreatureManager", "Herbivore", 0, QApplication::UnicodeUTF8));
        checkBox_healer->setText(QApplication::translate("CreatureManager", "Healer", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("CreatureManager", "Resists", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("CreatureManager", "kinetic", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("CreatureManager", "energy", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("CreatureManager", "blast", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("CreatureManager", "heat", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("CreatureManager", "cold", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("CreatureManager", "electricity", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("CreatureManager", "acid", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("CreatureManager", "stun", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("CreatureManager", "lightsaber", 0, QApplication::UnicodeUTF8));
        removeTemplate->setText(QApplication::translate("CreatureManager", "Remove Template", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("CreatureManager", "Template", 0, QApplication::UnicodeUTF8));
        addTemplate->setText(QApplication::translate("CreatureManager", "Add Template", 0, QApplication::UnicodeUTF8));
        pushButton_view3d->setText(QApplication::translate("CreatureManager", "View 3d model", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("CreatureManager", "Loot Groups", 0, QApplication::UnicodeUTF8));
        removeLootGroup->setText(QApplication::translate("CreatureManager", "Remove", 0, QApplication::UnicodeUTF8));
        addLoutGroup->setText(QApplication::translate("CreatureManager", "Add Loot Group", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("CreatureManager", "Weapons", 0, QApplication::UnicodeUTF8));
        newWeapon->setText(QString());
        removeWeapon->setText(QApplication::translate("CreatureManager", "Remove Weapon", 0, QApplication::UnicodeUTF8));
        addWeapon->setText(QApplication::translate("CreatureManager", "Add Weapon", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("CreatureManager", "Attack Data", 0, QApplication::UnicodeUTF8));
        pushButton_addAttack->setText(QApplication::translate("CreatureManager", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_removeAttack->setText(QApplication::translate("CreatureManager", "Remove", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("CreatureManager", "Options Bitmask", 0, QApplication::UnicodeUTF8));
        comboBox_OptionsBitmask->clear();
        comboBox_OptionsBitmask->insertItems(0, QStringList()
         << QApplication::translate("CreatureManager", "bit1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit2(vendor flag)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit4(converse flag)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit9(no health flag)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit12(info icon)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit16(info icon2)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CreatureManager", "bit32", 0, QApplication::UnicodeUTF8)
        );
        checkBox_optionsBitmask->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreatureManager: public Ui_CreatureManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATUREMANAGER_H
