#include "../include/PartOfFileReader.h"

namespace tl
{
    int PartOfFileReader::mFd = -1;

    PartOfFileReader::PartOfFileReader(const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(ignoreWhitespaces)
    {

    }

    PartOfFileReader::PartOfFileReader(const int fd,
                                       const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(ignoreWhitespaces)
    {
        TESTLIBRARY_ASSERT(fd != 0,
                           "PartOfFileReader doesn't work with stdin");

        open(fd);
    }

    PartOfFileReader::PartOfFileReader(FILE*& file,
                                       const bool ignoreWhitespaces)
    {

    }

    PartOfFileReader::PartOfFileReader(const char* path,
                                       const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(ignoreWhitespaces)
    {

        open(path);
    }

    PartOfFileReader::PartOfFileReader(const std::string& path,
                                       const bool ignoreWhitespaces) :
            PartOfFileReader(ignoreWhitespaces)
    {
        open(path);
    }

    void PartOfFileReader::open(const int fd)
    {
        PartOfFileReader::mFd = fd;

        openPart(fd);
    }

    void
    PartOfFileReader::open(FILE*& file)
    {
        TESTLIBRARY_NONNULL_ASSERT(file);

        open(::CORRECT_VER(fileno)(file));
    }

    void
    PartOfFileReader::open(const char* path)
    {
        if (path == nullptr)
        {
            open(mFd);
        }
        else
        {
            int fd(::CORRECT_VER(open)(path,
                                       CORRECT_VER(O_RDONLY)));
            PartOfFileReader::mFd = fd;

            open(fd);
        }
    }

    void
    PartOfFileReader::open(const std::string& path)
    {
        TESTLIBRARY_ASSERT(!path.empty(), "path is empty");

        open(path.c_str());
    }
}
