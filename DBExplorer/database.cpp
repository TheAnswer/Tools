#include "database.h"
#include "databaseexception.h"
#include "zcompression.h"
#include <QMessageBox>
#include <QByteArray>

//using namespace std;

Database::Database(QString &path)
    : db(NULL, 0),
      fileName(path),
      cFlags(0)
{
    try {
        db.set_error_stream(&std::cerr);
        db.open(NULL, fileName.toAscii(), NULL, DB_HASH, cFlags, 0);

        Dbc *cursorp;
        db.cursor(NULL, &cursorp, 0);

        Dbt key, value;

        while (cursorp->get(&key, &value, DB_NEXT) == 0) {
            unsigned long long int oid = *(unsigned long long int*)key.get_data();
            keys.append(oid);
        }

    } catch(DbException &e) {
        throw DatabaseException(QString("Error opening file with %1\n\nFile: %2\n\nError: %3").arg(e.what()).arg(fileName).arg(e.get_errno()));
    } catch(std::exception &e) {
        throw DatabaseException(QString("Error opening file with %1\n\nFile: %2").arg(e.what()).arg(fileName));
    }
}

void Database::close() {
    try {
        db.close(0);
    } catch(DbException &e) {
        throw DatabaseException(QString("Error closing file with %1\n\nFile: %2\n\nError: %3").arg(e.what()).arg(fileName).arg(e.get_errno()));
    } catch(std::exception &e) {
        throw DatabaseException(QString("Error closing file with %1\n\nFile: %2").arg(e.what()).arg(fileName));
    }
}

QByteArray Database::getData(int i, bool compressed) {
    unsigned long long int oid = keys[i];

    Dbt key, data;

    key.set_data(&oid);
    key.set_size(sizeof(unsigned long long int));

    data.set_flags(DB_DBT_MALLOC);

    db.get(NULL, &key, &data, 0);
    if (!(data.get_flags() & DB_DBT_USERMEM) && data.get_data() != NULL) {
        QByteArray object((char*)data.get_data(), data.get_size());
        free(data.get_data());

        if (compressed) {
            try {
                object = ZCompression::decompress(object);
            } catch (std::exception &e) {
                throw DatabaseException(QString("Error decompressing %1\n\nOID: %2").arg(e.what()).arg(oid));
            }
        }

        return object;
    }

    return QByteArray();
}
