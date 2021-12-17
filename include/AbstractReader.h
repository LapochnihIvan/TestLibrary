#ifndef TESTLIBRARY_ABSTRACTREADER_H
#define TESTLIBRARY_ABSTRACTREADER_H

#include "TestLibrarySecure.h"

#ifdef __GNUC__
#   include <unistd.h>

#   include <sys/stat.h>

#   define CORRECT_VER(func) func
#elif defined(_MSC_VER)
#   include <io.h>

//#   include <Windows.h>

#   define CORRECT_VER(func) _ ## func
#endif

#include <fcntl.h>

#include <cmath>
#include <cfloat>

#include <string>
#include <vector>
#include <functional>

namespace tl
{
    using hugeInt = std::string;
    using hugeIntPtr = char*;

    class AbstractReader
    {
    public:
        ~AbstractReader();

        void changeMode();

        [[nodiscard]] bool isOpen() const;

        [[nodiscard]] bool isEndOfFile() const;

        void skipWhitespaces();

        void skipChar();

        void readAllFile(char*& fileStr);

        bool readWhitespace(char& whitespace);

        bool readWhitespaces(char*& whitespaces);

        bool readWhitespaces(std::string& whitespaces);

        bool readChar(char& c);

        bool readNum(std::int8_t& num);

        bool readNum(std::uint8_t& num);

        bool readNum(std::int16_t& num);

        bool readNum(std::uint16_t& num);

        bool readNum(std::int32_t& num);

        bool readNum(std::uint32_t& num);

        bool readNum(std::int64_t& num);

        bool readNum(std::uint64_t& num);

        bool readInt8(std::int8_t& i);

        bool readUInt8(std::uint8_t& i);

        bool readInt16(std::int16_t& i);

        bool readUInt16(std::uint16_t& i);

        bool readInt32(std::int32_t& i);

        bool readUInt32(std::uint32_t& i);

        bool readInt64(std::int64_t& i);

        bool readUInt64(std::uint64_t& i);

        bool readShort(short& s);

        bool readUShort(unsigned short& s);

        bool readInt(int& i);

        bool readUInt(unsigned int& i);

        bool readLong(long& l);

        bool readULong(unsigned long& l);

        bool readLongLong(long long& ll);

        bool readULongLong(unsigned long long& ll);

        bool readHugeInt(hugeIntPtr& num);

        bool readHugeInt(hugeInt& num);

        bool readNum(float& num);

        bool readNum(double& num);

        bool readBool(bool& b);

        bool readStr(char* s,
                     std::size_t sSize) __nonnull((2));

        bool readStr(char*& emptyS) __nonnull((2));

        bool readStr(std::string& s, std::size_t sSize);

        bool readStr(std::string& s);

        bool readInt8ArrSplitC(std::int8_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUInt8ArrSplitC(std::uint8_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readInt16ArrSplitC(std::int16_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUInt16ArrSplitC(std::uint16_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readIntArrSplitC(std::int32_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUIntArrSplitC(std::uint32_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readInt64ArrSplitC(std::int64_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUInt64ArrSplitC(std::uint64_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readInt8ArrSplitS(std::int8_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUInt8ArrSplitS(std::uint8_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readInt16ArrSplitS(std::int16_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUInt16ArrSplitS(std::uint16_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readIntArrSplitS(std::int32_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUIntArrSplitS(std::uint32_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readInt64ArrSplitS(std::int64_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUInt64ArrSplitS(std::uint64_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readInt8ArrSplitC(std::vector <std::int8_t>& arr,
                              char delim = '\000');

        bool readUInt8ArrSplitC(std::vector <std::uint8_t>& arr,
                              char delim = '\000');

        bool readInt16ArrSplitC(std::vector <std::int16_t>& arr,
                              char delim = '\000');

        bool readUInt16ArrSplitC(std::vector <std::uint16_t>& arr,
                              char delim = '\000');

        bool readIntArrSplitC(std::vector <std::int32_t>& arr,
                              char delim = '\000');

        bool readUIntArrSplitC(std::vector <std::uint32_t>& arr,
                              char delim = '\000');

        bool readInt64ArrSplitC(std::vector <std::int64_t>& arr,
                              char delim = '\000');

        bool readUInt64ArrSplitC(std::vector <std::uint64_t>& arr,
                              char delim = '\000');

        bool readFltArrSplitC(std::vector<float>& arr,
                              char delim = '\000');

        bool readDblArrSplitC(std::vector<double>& arr,
                              char delim = '\000');

        bool readInt8ArrSplitS(std::vector <std::int8_t>& arr,
                              char* delim = nullptr);

        bool readUInt8ArrSplitS(std::vector <std::uint8_t>& arr,
                              char* delim = nullptr);

        bool readInt16ArrSplitS(std::vector <std::int16_t>& arr,
                              char* delim = nullptr);

        bool readUInt16ArrSplitS(std::vector <std::uint16_t>& arr,
                              char* delim = nullptr);

        bool readIntArrSplitS(std::vector <std::int32_t>& arr,
                              char* delim = nullptr);

        bool readUIntArrSplitS(std::vector <std::uint32_t>& arr,
                              char* delim = nullptr);

        bool readInt64ArrSplitS(std::vector <std::int64_t>& arr,
                              char* delim = nullptr);

        bool readUInt64ArrSplitS(std::vector <std::uint64_t>& arr,
                              char* delim = nullptr);

        bool readFltArrSplitS(std::vector<float>& arr,
                              char* delim = nullptr);

        bool readDblArrSplitS(std::vector<double>& arr,
                              char* delim = nullptr);

    protected:
        char* mData;
        char* mBegin;

        explicit AbstractReader(bool ignoreWhitespaces = false);

    private:
        bool mIgnoreWhitespaces;

        [[nodiscard]] inline bool isNotWhitespace() const;

        [[nodiscard]] inline bool isWhitespace() const;

        [[nodiscard]] inline bool isNotDigit();

        template<typename Num>
        [[nodiscard]] inline bool isNotInRange(const Num& num,
                                               const Num& nextNum,
                                               const Num& limit);

        [[nodiscard]] inline bool readAbstractStr(char*& s,
                                                  bool (AbstractReader::*continueCond)() const,
                                                  const std::function<bool()>& exitCond = [](){
                                                      return false;
                                                  });

        [[nodiscard]] inline bool readAbstractStr(std::string& s,
                                                  bool (AbstractReader::*continueCond)() const,
                                                  const std::function<bool()>& exitCond = [](){
                                                      return false;
                                                  });

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
                                                     std::size_t arrSize,
                                                     char delim)
            __nonnull((2));

        template<typename Num>
        [[nodiscard]] inline bool readAbstractNumArr(Num* arr,
                                                     std::size_t arrSize,
                                                     char* delim)
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
