#ifndef DATABASEEXCEPTION_H
#define DATABASEEXCEPTION_H

#include <db5.0/db_cxx.h>

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

#endif // DATABASEEXCEPTION_H
