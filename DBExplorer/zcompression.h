#ifndef ZCOMPRESSION_H
#define ZCOMPRESSION_H

#include <zlib.h>
#include <QByteArray>

#define CHUNK 16384

class ZCompression
{
public:
    ZCompression();

    static QByteArray compress(QByteArray source);
    static QByteArray decompress(QByteArray source);
    static void zerr(int ret);
};

#endif // ZCOMPRESSION_H
