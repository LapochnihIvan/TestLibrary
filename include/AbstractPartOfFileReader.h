#ifndef TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H
#define TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H

#include "AbstractReader.h"
namespace tl
{
    class AbstractPartOfFileReader : public AbstractReader
    {
    public:
        explicit AbstractPartOfFileReader(int fd,
                                          bool ignoreWhitespaces = false);
    };
}

#endif //TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H
