#ifndef TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H
#define TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H

#include "AbstractReader.h"
namespace tl
{
    class AbstractPartOfFileReader : public AbstractReader
    {
    protected:
        explicit AbstractPartOfFileReader(bool ignoreWhitespaces = false);

        explicit AbstractPartOfFileReader(int fd,
                                          bool ignoreWhitespaces = false);

        void openPart(int fd);
    };
}

#endif //TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H
