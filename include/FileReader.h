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
#include <vector>

namespace tl
{
    class FileReader {
    public:
        explicit FileReader(const char* path, bool ignoreWhitespaces = false)
            __attribute__ ((__nonnull__ (2)));
        explicit FileReader(const std::string& path, bool ignoreWhitespaces = false);
        ~FileReader();

        [[nodiscard]] bool isOpen() const;
        [[nodiscard]] bool isEndOfFile() const;
        void skipWhitespaces();
        void skipChar();
        bool readWhitespace(char& whitespace);
        bool readChar(char& c);
        bool readNum(std::int8_t& num);
        bool readNum(std::uint8_t& num);
        bool readNum(std::int16_t& num);
        bool readNum(std::uint16_t& num);
        bool readNum(std::int32_t& num);
        bool readNum(std::uint32_t& num);
        bool readNum(std::int64_t& num);
        bool readNum(std::uint64_t& num);
        bool readNum(float& num);
        bool readNum(double& num);
        bool readBool(bool& b);
        bool readStr(char* s,
                     std::size_t sSize) __attribute__ ((__nonnull__ (2)));
        bool readStr(char* emptyS) __attribute__ ((__nonnull__ (2)));
        bool readStr(std::string& s, std::size_t sSize);
        bool readStr(std::string& s);
        bool readNumArr(std::int8_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::uint8_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::int16_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::uint16_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::int32_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::uint32_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::int64_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::uint64_t* arr,
                        std::size_t arrSize) __attribute__ ((__nonnull__ (2)));
        bool readNumArr(std::vector<std::int8_t>& arr);
        bool readNumArr(std::vector<std::uint8_t>& arr);
        bool readNumArr(std::vector<std::int16_t>& arr);
        bool readNumArr(std::vector<std::uint16_t>& arr);
        bool readNumArr(std::vector<std::int32_t>& arr);
        bool readNumArr(std::vector<std::uint32_t>& arr);
        bool readNumArr(std::vector<std::int64_t>& arr);
        bool readNumArr(std::vector<std::uint64_t>& arr);

    private:
        char* mData;
        char* mBegin;
        const bool mIgnoreWhitespaces;

        [[nodiscard]] bool isNotWhitespace() const;
        template<typename int_t>
        [[nodiscard]] bool readAbstractInt(int_t& num, int_t limit);
        template<typename int_t>
        [[nodiscard]] bool readAbstractSignedInt(int_t& num,
                                                 int_t maxSize, int_t minSize);
        template<typename num_t>
        [[nodiscard]] bool readAbstractNumArr(num_t* arr,
                                              std::size_t arrSize)
            __attribute__ ((__nonnull__ (2)));
        template<typename iterableArrT>
        [[nodiscard]] bool readAbstractNumArr(iterableArrT& arr);
    };
}

#endif //TESTLIBRARY_FILEREADER_H
