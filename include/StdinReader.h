#ifndef TESTLIBRARY_STDINREADER_H
#define TESTLIBRARY_STDINREADER_H

#include "AbstractReader.h"

namespace tl
{
    class StdinReader : public AbstractReader
    {
    public:
        explicit StdinReader(bool ignoreWhitespaces = false);

    private:
        using AbstractReader::open;
    };
}

#endif //TESTLIBRARY_STDINREADER_H
