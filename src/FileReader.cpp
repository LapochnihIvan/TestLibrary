#include "../include/FileReader.h"

namespace tl {
    FileReader::FileReader(const int fd, const bool ignoreWhitespaces) :
            AbstractReader(fd, ignoreWhitespaces)
    {
        TESTLIBRARY_ASSERT(fd != 0,
                           "FileReader doesn't work with stdin");
    }

    FileReader::FileReader(const char *path,
                           const bool ignoreWhitespaces) :
            AbstractReader(
                    ::CORRECT_VER(open)(path, CORRECT_VER(O_RDONLY)),
                    ignoreWhitespaces)
    {
        TESTLIBRARY_NONNULL_ASSERT(path);
    }

    FileReader::FileReader(const std::string &path,
                           const bool ignoreWhitespaces) :
            FileReader(path.c_str(), ignoreWhitespaces)
    {
        TESTLIBRARY_ASSERT(!path.empty(), "path is empty");
    }
}
