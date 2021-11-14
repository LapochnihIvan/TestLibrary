#ifndef TESTLIBRARY_STDINREADER_H
#define TESTLIBRARY_STDINREADER_H

#include "AbstractReader.h"

namespace tl
{
    class StdinReader : public AbstractReader
    {
    public:
        explicit StdinReader(bool ignoreWhitespaces = false);
    };
}

#endif //TESTLIBRARY_STDINREADER_H
