#ifndef TESTLIBRARY_ABSTRACTREADER_H
#define TESTLIBRARY_ABSTRACTREADER_H

#ifdef __GNUC__
#   include <unistd.h>

#   include <sys/stat.h>

#   define CORRECT_VER(func) func
#elif _MSC_VER
#   define _CRT_SECURE_NO_WARNINGS

#   include <io.h>

//#   include <Windows.h>

#   define CORRECT_VER(func) _ ## func
#   define __nonnull(params)
#endif

#include <fcntl.h>

#include <cstdint>
#include <cmath>

#include <string>
#include <vector>

namespace tl
{
    class AbstractReader
    {
    public:
        explicit AbstractReader(int fd, bool ignoreWhitespaces = false);

        ~AbstractReader();

        [[nodiscard]] bool isOpen() const;

        [[nodiscard]] bool isEndOfFile() const;

        void skipWhitespaces();

        void skipChar();

        bool readWhitespace(char& whitespace);

        bool readWhitespaces(char*& whitespaces);

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
                     std::size_t sSize) __nonnull((2));

        bool readStr(char*& emptyS) __nonnull((2));

        bool readStr(std::string& s, std::size_t sSize);

        bool readStr(std::string& s);

        bool readNumArr(std::int8_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::uint8_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::int16_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::uint16_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::int32_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::uint32_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::int64_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArr(std::uint64_t* arr,
                        std::size_t arrSize)
            __nonnull((2));

        bool readNumArrSplitC(std::vector <std::int8_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::uint8_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::int16_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::uint16_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::int32_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::uint32_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::int64_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector <std::uint64_t>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector<float>& arr,
                        char delim = '\000');

        bool readNumArrSplitC(std::vector<double>& arr,
                        char delim = '\000');

        bool readNumArrSplitS(std::vector <std::int8_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::uint8_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::int16_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::uint16_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::int32_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::uint32_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::int64_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector <std::uint64_t>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector<float>& arr,
                        char* delim = nullptr);

        bool readNumArrSplitS(std::vector<double>& arr,
                        char* delim = nullptr);

    private:
        char* mData;
        char* mBegin;
        const bool mIgnoreWhitespaces;

        [[nodiscard]] inline bool isNotWhitespace() const;

        [[nodiscard]] inline bool isWhitespace() const;

        [[nodiscard]] inline bool isNotDigit();

        template<typename Num>
        [[nodiscard]] inline bool isNotInRange(const Num& num,
                                               const Num& nextNum,
                                               const Num& limit);

        [[nodiscard]] inline bool readAbstractStr(char*& s,
                                                  bool (AbstractReader::*cond)() const);

        template<typename Int>
        [[nodiscard]] inline bool readAbstractInt(Int& num, Int limit);

        template<typename Int>
        [[nodiscard]] inline bool readAbstractSignedInt(Int& num,
                                                        Int maxSize,
                                                        Int minSize);

        template<typename Real>
        [[nodiscard]] inline bool readAbstractReal(Real& num,
                                                   Real maxSize,
                                                   Real minSize);

        template<typename Num>
        [[nodiscard]] inline bool readAbstractNumArr(Num* arr,
                                                     std::size_t arrSize)
            __nonnull((2));

        template<typename iterableArrT>
        [[nodiscard]] inline bool readAbstractNumArr(iterableArrT& arr,
                                                     char delim);

        template<typename iterableArrT>
        [[nodiscard]] inline bool readAbstractNumArr(iterableArrT& arr,
                                                     char* delim);
    };
}

#endif //TESTLIBRARY_ABSTRACTREADER_H
