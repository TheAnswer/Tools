#include "zcompression.h"
#include <stdexcept>

ZCompression::ZCompression()
{
}

QByteArray ZCompression::compress(QByteArray source)
{
    int ret;
    z_stream strm;
    char out[CHUNK];
    QByteArray output;

    /* allocate deflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK) {
        zerr(ret);
        return output;
    }

    strm.next_in = (Bytef*)source.data();
    strm.avail_in = source.size();

    do {
        strm.next_out = (Bytef*)out;
        strm.avail_out = CHUNK;

        ret = deflate(&strm, Z_FINISH);
        if (ret != Z_OK && ret != Z_STREAM_END) {
            deflateEnd(&strm);
            zerr(ret);
            return output;
        }

        int wrote = CHUNK - strm.avail_out;

        output.append(out, wrote);
    } while (strm.avail_out == 0);

    deflateEnd(&strm);

    return output;
}

QByteArray ZCompression::decompress(QByteArray source)
{
    int ret;
    z_stream strm;
    char out[CHUNK];
    QByteArray output;

    /* allocate inflate state */
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;
    ret = inflateInit(&strm);
    if (ret != Z_OK) {
        zerr(ret);
        return output;
    }

    strm.next_in = (Bytef*)source.data();
    strm.avail_in = source.size();

    /* decompress until deflate stream ends or end of file */
    do {
        strm.next_out = (Bytef*)out;
        strm.avail_out = CHUNK;

        ret = inflate(&strm, Z_NO_FLUSH);

        if (ret == Z_DATA_ERROR) {
            output = source;
            inflateEnd(&strm);
            return output;
        }

        if (ret != Z_OK && ret != Z_STREAM_END) {
            inflateEnd(&strm);
            zerr(ret);
            return output;
        }

        int wrote = CHUNK - strm.avail_out;

        output.append(out, wrote);
    } while (strm.avail_out == 0);

    (void)inflateEnd(&strm);

    return output;
}

/* report a zlib or i/o error */
void ZCompression::zerr(int ret)
{
    switch (ret) {
    case Z_ERRNO:
        throw std::runtime_error("ZCompression: error reading stream");
        break;
    case Z_STREAM_ERROR:
        throw std::runtime_error("ZCompression: invalid compression level");
        break;
    case Z_DATA_ERROR:
        throw std::runtime_error("ZCompression: invalid or incomplete deflate data");
        break;
    case Z_MEM_ERROR:
        throw std::runtime_error("ZCompression: out of memory");
        break;
    case Z_VERSION_ERROR:
        throw std::runtime_error("ZCompression: zlib version mismatch");
        break;
    default:
        throw std::runtime_error("ZCompression: general zlib error");
        break;
    }
}
