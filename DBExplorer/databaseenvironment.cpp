#include "databaseenvironment.h"
#include "databaseexception.h"

DatabaseEnvironment::DatabaseEnvironment(QDir p)
    : dbEnv(0),
      homePath(p),
      flags(DB_INIT_LOCK | DB_INIT_LOG | DB_INIT_MPOOL | DB_INIT_TXN)
{
    try {
    dbEnv.open(homePath.path().toStdString().c_str(), flags, 0);
    } catch(DbException &e) {
	throw DatabaseException(QString("Error opening environment with %1\n\nHome: %2\n\nError: %3").arg(e.what()).arg(homePath.path()).arg(e.get_errno()));
    } catch(std::exception &e) {
	throw DatabaseException(QString("Error opening environment with %1\n\nFile: %2").arg(e.what()).arg(homePath.path()));
    }
}

void DatabaseEnvironment::close() {
    try {
        dbEnv.close(0);
    } catch(DbException &e) {
	throw DatabaseException(QString("Error closing file with %1\n\nHome: %2\n\nError: %3").arg(e.what()).arg(homePath.path()).arg(e.get_errno()));
    } catch(std::exception &e) {
	throw DatabaseException(QString("Error closing file with %1\n\nHome: %2").arg(e.what()).arg(homePath.path()));
    }
}
