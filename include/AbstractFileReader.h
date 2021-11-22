#ifndef TESTLIBRARY_ABSTRACTFILEREADER_H
#define TESTLIBRARY_ABSTRACTFILEREADER_H

#include "AbstractReader.h"

namespace tl
{
    class AbstractFileReader : public AbstractReader
    {
    public:
        void open(int fd);

    protected:
        explicit AbstractFileReader(int fd, bool ignoreWhitespaces = false);

        explicit AbstractFileReader(bool ignoreWhitespaces);
    };
}

#endif //TESTLIBRARY_ABSTRACTFILEREADER_H
