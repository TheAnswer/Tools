#ifndef DATABASE_H
#define DATABASE_H

#include <db53/db_cxx.h>
#include <QList>
#include <QString>
#include <QStringList>
#include <QByteArray>


/**
 * @brief The Database class will be the object for the actual berkeley database
 */
class Database
{
protected:
    Db db;
    QString fileName;
    u_int32_t cFlags;

    QList<unsigned long long int> keys;


    void close();

public:
    Database(QString &path);
    Database() : db(NULL, 0) {}
    ~Database() { close(); }

    inline Db &getDb() { return db; }

    inline QString &getFileName() { return fileName; }

    inline unsigned long long int &getKey(int i) { return keys[i]; }

    inline int getSize() { return keys.size(); }

    QByteArray getData(int i, bool compressed);
};

#endif // DATABASE_H
