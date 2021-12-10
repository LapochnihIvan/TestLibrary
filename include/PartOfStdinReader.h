#ifndef TESTLIBRARY_PARTOFSTDINREADER_H
#define TESTLIBRARY_PARTOFSTDINREADER_H

#include "AbstractPartOfFileReader.h"

namespace tl
{
    class PartOfStdinReader : public AbstractPartOfFileReader
    {
    public:
        explicit PartOfStdinReader(bool ignoreWhitespaces = false);
    };
}

#endif //TESTLIBRARY_PARTOFSTDINREADER_H
