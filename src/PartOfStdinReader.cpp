#include "../include/PartOfStdinReader.h"

namespace tl
{
    PartOfStdinReader::PartOfStdinReader(const bool ignoreWhitespaces) :
            AbstractFileReader(ignoreWhitespaces)
    {
        union
        {
            char buff[8];
            std::uint64_t num;
        } sizeOfPart{};

        ::CORRECT_VER(read(0, sizeOfPart.buff, 8));

        mData = new char[sizeOfPart.num + 1];
        mData[sizeOfPart.num] = '\000';
        ::CORRECT_VER(read(0, mData, sizeOfPart.num));

        mBegin = mData;
    }
}
