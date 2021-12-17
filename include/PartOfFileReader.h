#ifndef TESTLIBRARY_PARTOFFILEREADER_H
#define TESTLIBRARY_PARTOFFILEREADER_H

#include "AbstractPartOfFileReader.h"

namespace tl
{
    class PartOfFileReader : public AbstractPartOfFileReader
    {
    public:
        explicit PartOfFileReader(bool ignoreWhitespaces = false);

        explicit PartOfFileReader(int fd,
                                  bool ignoreWhitespaces = false);

        explicit PartOfFileReader(FILE*& file,
                                  bool ignoreWhitespaces = false);

        explicit PartOfFileReader(const char* path,
                                  bool ignoreWhitespaces = false);

        explicit PartOfFileReader(const std::string& path,
                                  bool ignoreWhitespaces = false);

        void open(int fd);

        void open(FILE*& file);

        void open(const char* path);

        void open(const std::string& path);

    private:
        static int mFd;
    };
}

#endif //TESTLIBRARY_PARTOFFILEREADER_H
