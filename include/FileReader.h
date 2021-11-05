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

#include <fcntl.h>

#include <cstdint>

#include <string>

namespace tl
{
    class FileReader {
    public:
        explicit FileReader(const char* path, bool ignoreWhitespaces = true);
        explicit FileReader(const std::string& path, bool ignoreWhitespaces = true);
        ~FileReader();

        [[nodiscard]] bool isOpen() const;
        [[nodiscard]] bool isEndOfFile() const;
        void skipChar();
        bool readChar(char& c);
        inline bool readNextInt(std::int8_t& num);
        inline bool readNextInt(std::uint8_t& num);
        inline bool readNextInt(std::int16_t& num);
        inline bool readNextInt(std::uint16_t& num);
        inline bool readNextInt(std::int32_t& num);
        inline bool readNextInt(std::uint32_t& num);
        inline bool readNextInt(std::int64_t& num);
        inline bool readNextInt(std::uint64_t& num);
        bool readStr(char*& s, std::size_t size);
        bool readStr(char*& s);
        bool readStr(std::string& s, std::size_t size);
        bool readStr(std::string& s);
        bool readBool(bool& b);
        bool readWhitespace(char& whitespace);

    private:
        char* mData;
        char* mBegin;
        const bool mIgnoreWhitespaces;

        [[nodiscard]] bool isNotWhitespace() const;
        template<typename Int>
        [[nodiscard]] bool readIntNum(Int& num, Int limit);
        template<typename Int>
        [[nodiscard]] bool readSignedIntNum(Int& num, Int maxSize, Int minSize);
        static std::size_t charPtrSize(const char* charPtr);
    };
}

#endif //TESTLIBRARY_FILEREADER_H
