#ifndef TESTLIBRARY_FILEREADER_H
#define TESTLIBRARY_FILEREADER_H

#include "AbstractReader.h"

namespace tl
{
    class FileReader : public AbstractReader
    {
    public:
        explicit FileReader(int fd, bool ignoreWhitespaces = false);

        explicit FileReader(FILE*& file, bool ignoreWhitespaces = false);

        explicit FileReader(const char* path,
                            bool ignoreWhitespaces = false) __nonnull((2));

        explicit FileReader(const std::string& path, bool ignoreWhitespaces = false);

        void open(FILE*& file);

        void open(const char* path) __nonnull((2));

        void open(const std::string& path);
    };
}

#endif //TESTLIBRARY_FILEREADER_H
