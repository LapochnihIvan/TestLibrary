#include "../include/AbstractPartOfFileReader.h"
namespace tl
{
    AbstractPartOfFileReader::AbstractPartOfFileReader(const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {

    }

    AbstractPartOfFileReader::AbstractPartOfFileReader(const int fd,
                                                       const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        openPart(fd);
    }

    void AbstractPartOfFileReader::openPart(const int fd)
    {
        TESTLIBRARY_ASSERT(fd != -1, "file doesn't exist");
        TESTLIBRARY_ASSERT(fd != 1,
                           "PartOfFileReader doesn't work with stdout");
        TESTLIBRARY_ASSERT(fd != 2,
                           "PartOfFileReader doesn't work with stderr");

        std::size_t sizeOfPart;

        ::CORRECT_VER(read)(fd, static_cast<void*>(&sizeOfPart), 8);

        mData = new char[sizeOfPart + 1];
        mData[sizeOfPart] = '\000';
        ::CORRECT_VER(read)(fd, static_cast<void*>(mData), sizeOfPart);

        mBegin = mData;
    }
}
