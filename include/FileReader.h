#ifndef TESTLIBRARY_FILEREADER_H
#define TESTLIBRARY_FILEREADER_H

#include <unistd.h>
#include <fcntl.h>

#include <cstdint>
#include <cstdlib>

#ifdef __GNUC__
#   include <sys/stat.h>
#else
#   include <cstdio>
#endif

namespace tl
{
    class FileReader {
    public:
        explicit FileReader(const char* path);
        ~FileReader();

        [[nodiscard]] bool isOpen() const;
        [[nodiscard]] bool isEndOfFile() const;
        bool readNextInt(int& num);
        bool readStr(std::string& s);

    private:
        char* mData;
        char* mBegin;
        const int fileDir;
        std::size_t pos;

        static std::size_t charPtrSize(const char* charPtr);
    };
}

#endif //TESTLIBRARY_FILEREADER_H
