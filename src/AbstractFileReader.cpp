#include "../include/AbstractFileReader.h"

namespace tl
{
    AbstractFileReader::AbstractFileReader(bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {

    }

    AbstractFileReader::AbstractFileReader(const int fd,
                                               const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        open(fd);
    }

    void
    AbstractFileReader::open(const int fd)
    {
        TESTLIBRARY_ASSERT(fd != -1, "file doesn't exist");
        TESTLIBRARY_ASSERT(fd != 1,
                           "FileReader doesn't work with stdout");
        TESTLIBRARY_ASSERT(fd != 2,
                           "FileReader doesn't work with stderr");

#ifdef __GNUC__
        struct ::stat file{};
        ::fstat(fd, &file);
        const ::off_t fSize(file.st_size);
//#elif _MSC_VER
//      HANDLE hF = CreateFileA("F:\\TestLib\\TestLib\\test.exe", 0x00, 0x00, NULL,
//            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//      const DWORD fSize(GetFileSize(hF, NULL));
#else
        const long fSize(::CORRECT_VER(lseek)(fd, 0L, SEEK_END));
            ::CORRECT_VER(lseek)(fd, 0L, SEEK_SET);
#endif

        mData = new char[fSize + 1];
        mData[fSize] = '\000';

        ::CORRECT_VER(read)(fd, mData, fSize);
        ::CORRECT_VER(close)(fd);
        mBegin = mData;
    }
}
