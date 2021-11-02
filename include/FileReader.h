#ifndef TESTLIBRARY_FILEREADER_H
#define TESTLIBRARY_FILEREADER_H

#ifdef __GNUC__
#   include <unistd.h>

#   include <sys/stat.h>

#   define CORRECT_VER(func) func
#elif _MSC_VER
#   define _CRT_SECURE_NO_WARNINGS

#   include <corecrt_io.h>
//#   include <Windows.h>

#   define CORRECT_VER(func) _ ## func
#endif

#   include <fcntl.h>

#include <cstdint>

#include <string>

namespace tl
{
    class FileReader {
    public:
        explicit FileReader(const char* path);
        explicit FileReader(const std::string& path);
        ~FileReader();

        [[nodiscard]] bool isOpen() const;
        [[nodiscard]] bool isEndOfFile() const;
        bool readChar(char& c);
        bool readNextInt(int& num);
        bool readStr(char*& s, const std::size_t size);
        bool readStr(std::string& s);
        bool readBool(bool& b);

    private:
        char* mData;
        char* mBegin;
        const int mFileDir;

        static std::size_t charPtrSize(const char* charPtr);
    };
}

#endif //TESTLIBRARY_FILEREADER_H
