#ifndef TESTLIBRARY_STDINREADER_H
#define TESTLIBRARY_STDINREADER_H

#include "AbstractFileReader.h"

namespace tl
{
    class StdinReader : public AbstractFileReader
    {
    public:
        explicit StdinReader(bool ignoreWhitespaces = false);

    private:
        using AbstractFileReader::open;
    };
}

#endif //TESTLIBRARY_STDINREADER_H
