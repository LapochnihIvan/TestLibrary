#ifndef TESTLIBRARY_PARTOFSTDINREADER_H
#define TESTLIBRARY_PARTOFSTDINREADER_H

#include "AbstractFileReader.h"

namespace tl
{
    class PartOfStdinReader : public AbstractFileReader
    {
    public:
        explicit PartOfStdinReader(bool ignoreWhitespaces = false);
    };
}

#endif //TESTLIBRARY_PARTOFSTDINREADER_H
