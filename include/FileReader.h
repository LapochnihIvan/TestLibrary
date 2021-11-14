#ifndef TESTLIBRARY_FILEREADER_H
#define TESTLIBRARY_FILEREADER_H

#include "AbstractReader.h"

namespace tl
{
    class FileReader : public AbstractReader
    {
    public:
        explicit FileReader(int fd, bool ignoreWhitespaces = false);

        explicit FileReader(const char *path,
                            bool ignoreWhitespaces = false) __nonnull((2));

        explicit FileReader(const std::string &path, bool ignoreWhitespaces = false);
    };
}

#endif //TESTLIBRARY_FILEREADER_H
