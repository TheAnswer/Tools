#include "datamanager.h"
#include "swgRepository.hpp"
#include "mainwindow.h"
#include "QComboBox"
#include "QLinkedList"
#include "treLib/treArchive.hpp"

DataManager::DataManager() {
    repo = NULL;
    mutex = new QMutex();
}

DataManager::~DataManager() {
    if (repo != NULL) {
        delete repo;
        repo = NULL;
    }

    delete mutex;
}


void DataManager::loadTreData(QString treDirectory) {
    if (!QFile::exists(treDirectory)) {
        emit loadingResource("Could not load TRE files from directory.");
        return;
    }

    emit loadingResource("Loading SWG repository.");

    treDirectory.replace(QChar('\\'), QChar('/'));

    if (!treDirectory.endsWith('/'))
        treDirectory.append('/');

    repo = new swgRepository(treDirectory.toStdString());

    treArchive* archive = repo->getTreArchive();

    emit loadingResource("Mapping TRE files directory structure.");

    std::list<std::string>* items = archive->getArchiveContents();

    for (std::list<std::string>::iterator i = items->begin(); i != items->end(); ++i) {
        QString filepath =  QString::fromStdString(*i);

        int lastsep = filepath.lastIndexOf('/');
        int len = filepath.length();

        QString directory = filepath.left(lastsep + 1);
        QString filename = filepath.right(len - lastsep - 1);

        if (treDirectories.contains(directory)) {
            QVector<QString>* dirContents = &treDirectories[directory];
            dirContents->append(filename);
        } else {
            QVector<QString> dirContents;
            dirContents.append(filename);
            treDirectories.insert(directory, dirContents);
        }
    }
}

void DataManager::loadLuaData() {
    loadLootData();
}

void DataManager::loadLootData() {

}
