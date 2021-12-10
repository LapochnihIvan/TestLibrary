#include "../include/AbstractPartOfFileReader.h"
namespace tl
{
    AbstractPartOfFileReader::AbstractPartOfFileReader(const int fd,
                                                       const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        union
        {
            unsigned char buff[8];
            std::uint64_t num;
        } sizeOfPart{};

        ::CORRECT_VER(read)(fd, sizeOfPart.buff, 8);

        mData = new char[sizeOfPart.num + 1];
        mData[sizeOfPart.num] = '\000';
        ::CORRECT_VER(read)(fd, mData, sizeOfPart.num);

        mBegin = mData;
    }
}
