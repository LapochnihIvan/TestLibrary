#include "../include/FileReader.h"

namespace tl {
    FileReader::FileReader(const int fd, const bool ignoreWhitespaces) :
            AbstractReader(fd, ignoreWhitespaces)
    {

    }

    FileReader::FileReader(const char *path,
                           const bool ignoreWhitespaces) :
            AbstractReader(
                    ::CORRECT_VER(open)(path, CORRECT_VER(O_RDONLY)),
                    ignoreWhitespaces)
    {

    }

    FileReader::FileReader(const std::string &path,
                           const bool ignoreWhitespaces) :
            FileReader(path.c_str(), ignoreWhitespaces)
    {

    }
}
