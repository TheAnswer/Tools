#ifndef DATABASE_H
#define DATABASE_H

#include <db5.0/db_cxx.h>
#include <QList>
#include <QString>
#include <QStringList>
#include <QByteArray>


/**
 * @brief The DatabaseException class because QT 4.8 doesn't handle exceptions
 */
class DatabaseException : public std::exception
{
protected:
    QString msg;

public:
    DatabaseException(const QString& m) : std::exception() {
        this->msg = m;
    }

    virtual ~DatabaseException() throw() {}

    const char* what() const throw() { return msg.toAscii(); }

    QString getMsg() {
        return msg;
    }
};


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

    Database() : db(NULL, 0) {}

    void close();

public:
    Database(QString &path);
    ~Database() { close(); }

    inline Db &getDb() { return db; }

    inline QString &getFileName() { return fileName; }

    inline unsigned long long int &getKey(int i) { return keys[i]; }

    inline int getSize() { return keys.size(); }

    QByteArray getData(int i);
};

#endif // DATABASE_H
