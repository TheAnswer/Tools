#ifndef DATABASEENVIRONMENT_H
#define DATABASEENVIRONMENT_H

#include "database.h"
#include <QDir>

class DatabaseEnvironment
{
protected:
    DbEnv dbEnv;
    Database currentDb;

    QDir homePath;
    u_int32_t flags;

    void close();

public:
    DatabaseEnvironment(QDir p);
    ~DatabaseEnvironment() { close(); }

    // These are accessors for the current database. We don't need to be careful because they are only read operations.
    inline unsigned long long int &getKey(int i) { return currentDb.getKey(i); }
    inline int getSize() { return currentDb.getSize(); }
    QByteArray getData(int i, bool compressed) { return currentDb.getData(i, compressed); }
    
    
};

#endif // DATABASEENVIRONMENT_H
