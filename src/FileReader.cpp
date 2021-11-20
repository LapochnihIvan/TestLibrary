#include "../include/FileReader.h"

namespace tl {
    FileReader::FileReader(const int fd, const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        TESTLIBRARY_ASSERT(fd != 0,
                           "FileReader doesn't work with stdin");

        AbstractReader::open(fd);
    }

    FileReader::FileReader(FILE*& file, const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        open(file);
    }

    FileReader::FileReader(const char *path,
                           const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        open(path);
    }

    FileReader::FileReader(const std::string &path,
                           const bool ignoreWhitespaces) :
            FileReader(path.c_str(), ignoreWhitespaces)
    {
        open(path);
    }

    void
    FileReader::open(FILE*& file)
    {
        TESTLIBRARY_NONNULL_ASSERT(file);

        AbstractReader::open(::fileno(file));
    }

    void
    FileReader::open(const char* path)
    {
        TESTLIBRARY_NONNULL_ASSERT(path);

        AbstractReader::open(::CORRECT_VER(open)(path,
                             CORRECT_VER(O_RDONLY)));
    }

    void
    FileReader::open(const std::string& path)
    {
        TESTLIBRARY_ASSERT(!path.empty(), "path is empty");

        open(path.c_str());
    }
}
