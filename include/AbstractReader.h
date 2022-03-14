#ifndef TESTLIBRARY_ABSTRACTREADER_H
#define TESTLIBRARY_ABSTRACTREADER_H

#include "TestLibrarySecure.h"

#ifdef __GNUC__
#   include <sys/stat.h>
// #elif defined(_MSC_VER)
// #   include <Windows.h>
#endif

#include <cmath>
#include <cfloat>
#include <cstring>

#include <string>
#include <vector>
#include <functional>

#include "TestLibraryIOSettings.h"

#include "ResultWriter.h"

#define IS_NOT_OPEN_ASSERT \
    TESTLIBRARY_ASSERT(isOpen() != false, "file isn't open")

#ifdef READ_SELFMADE_ERRORS
#   define READ_SUCCESS 0
#   define READ_EOF -1
#   define READ_TYPE_ERROR -2
#   define READ_INCORRECT_SIZE -3

#   define READ_RET_TYPE int

#   define READ_POS_RESULT(logger, result)               \
        FUNC_FINISH_LOG(logger, #result"(%d)", result);  \
                                                         \
        return result

#   define READ_NEG_RESULT(logger, result, message, ...)                       \
        FUNC_FINISH_LOG(logger, #result"(%d), " message, result __VA_ARGS__);  \
                                                                               \
        return result

#   define READ_USE_INSERT_FUNC_RESULT(logger, resultName, insertFuncCall)       \
        FUNC_RETURN_LOG(logger, READ_RET_TYPE, resultName, "%d", insertFuncCall)

#   define READ_CHECK_INSERT_FUNC_RESULT(logger, resultName, insertFuncCall) \
        READ_RET_TYPE resultName(insertFuncCall);                            \
        if (resultName != READ_SUCCESS)                                      \
        {                                                                    \
            FUNC_FINISH_LOG(logger, "%d", resultName);                       \
            return resultName;                                               \
        }
#else
#   define READ_SUCCESS
#   define READ_EOF WAResultWr
#   define READ_TYPE_ERROR PEResultWr
#   define READ_INCORRECT_SIZE WAResultWr

#   define READ_RET_TYPE void

#   define READ_POS_RESULT(logger, result) FUNC_FINISH_LOG(logger)

#   define _READ_NEG_RESULT(logger, result, message, ...) \
        tl::ResultWriter::result(message __VA_ARGS__)

#   define READ_NEG_RESULT(logger, result, message, ...) \
        _READ_NEG_RESULT(logger, result, message, __VA_ARGS__)

#   define READ_USE_INSERT_FUNC_RESULT(logger, resultName, insertFuncCall) \
        insertFuncCall;                                                    \
                                                                           \
        FUNC_FINISH_LOG(logger)

#   define READ_CHECK_INSERT_FUNC_RESULT(logger, resultName, insertFuncCall) \
        insertFuncCall
#endif //READ_SELFMADE_ERRORS

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

        READ_RET_TYPE readWhitespace(char& whitespace);

        READ_RET_TYPE readWhitespaces(char*& whitespaces);

        READ_RET_TYPE readWhitespaces(std::string& whitespaces);

        READ_RET_TYPE readChar(char& c);

        READ_RET_TYPE readNum(std::int8_t& num);

        READ_RET_TYPE readNum(std::uint8_t& num);

        READ_RET_TYPE readNum(std::int16_t& num);

        READ_RET_TYPE readNum(std::uint16_t& num);

        READ_RET_TYPE readNum(std::int32_t& num);

        READ_RET_TYPE readNum(std::uint32_t& num);

        READ_RET_TYPE readNum(std::int64_t& num);

        READ_RET_TYPE readNum(std::uint64_t& num);

        READ_RET_TYPE readInt8(std::int8_t& i);

        READ_RET_TYPE readUInt8(std::uint8_t& i);

        READ_RET_TYPE readInt16(std::int16_t& i);

        READ_RET_TYPE readUInt16(std::uint16_t& i);

        READ_RET_TYPE readInt32(std::int32_t& i);

        READ_RET_TYPE readUInt32(std::uint32_t& i);

        READ_RET_TYPE readInt64(std::int64_t& i);

        READ_RET_TYPE readUInt64(std::uint64_t& i);

        READ_RET_TYPE readShort(short& s);

        READ_RET_TYPE readUShort(unsigned short& s);

        READ_RET_TYPE readInt(int& i);

        READ_RET_TYPE readUInt(unsigned int& i);

        READ_RET_TYPE readLong(long& l);

        READ_RET_TYPE readULong(unsigned long& l);

        READ_RET_TYPE readLongLong(long long& ll);

        READ_RET_TYPE readULongLong(unsigned long long& ll);

        READ_RET_TYPE readHugeInt(hugeIntPtr& i);

        READ_RET_TYPE readHugeInt(hugeInt& i);

        READ_RET_TYPE readNum(float& num);

        READ_RET_TYPE readNum(double& num);

        READ_RET_TYPE readBool(bool& b);

        READ_RET_TYPE readStr(char* s,
                              std::size_t sSize) __nonnull((2));

        READ_RET_TYPE readStr(char*& emptyS) __nonnull((2));

        READ_RET_TYPE readStr(std::string& s, std::size_t sSize);

        READ_RET_TYPE readStr(std::string& s);

        READ_RET_TYPE readInt8ArrSplitC(std::int8_t* arr,
                                        std::size_t arrSize,
                                        char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readUInt8ArrSplitC(std::uint8_t* arr,
                                         std::size_t arrSize,
                                         char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readInt16ArrSplitC(std::int16_t* arr,
                                         std::size_t arrSize,
                                         char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readUInt16ArrSplitC(std::uint16_t* arr,
                                          std::size_t arrSize,
                                          char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readIntArrSplitC(std::int32_t* arr,
                                       std::size_t arrSize,
                                       char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readUIntArrSplitC(std::uint32_t* arr,
                                        std::size_t arrSize,
                                        char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readInt64ArrSplitC(std::int64_t* arr,
                                         std::size_t arrSize,
                                         char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readUInt64ArrSplitC(std::uint64_t* arr,
                                          std::size_t arrSize,
                                          char delim = '\000')
            __nonnull((2));

        READ_RET_TYPE readInt8ArrSplitS(std::int8_t* arr,
                                        std::size_t arrSize,
                                        char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readUInt8ArrSplitS(std::uint8_t* arr,
                                         std::size_t arrSize,
                                         char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readInt16ArrSplitS(std::int16_t* arr,
                                         std::size_t arrSize,
                                         char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readUInt16ArrSplitS(std::uint16_t* arr,
                                          std::size_t arrSize,
                                          char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readIntArrSplitS(std::int32_t* arr,
                                       std::size_t arrSize,
                                       char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readUIntArrSplitS(std::uint32_t* arr,
                                        std::size_t arrSize,
                                        char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readInt64ArrSplitS(std::int64_t* arr,
                                         std::size_t arrSize,
                                         char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readUInt64ArrSplitS(std::uint64_t* arr,
                                          std::size_t arrSize,
                                          char* delim = nullptr)
            __nonnull((2));

        READ_RET_TYPE readInt8ArrSplitC(std::vector <std::int8_t>& arr,
                                        char delim = '\000');

        READ_RET_TYPE readUInt8ArrSplitC(std::vector <std::uint8_t>& arr,
                                         char delim = '\000');

        READ_RET_TYPE readInt16ArrSplitC(std::vector <std::int16_t>& arr,
                                         char delim = '\000');

        READ_RET_TYPE readUInt16ArrSplitC(std::vector <std::uint16_t>& arr,
                                          char delim = '\000');

        READ_RET_TYPE readIntArrSplitC(std::vector <std::int32_t>& arr,
                                       char delim = '\000');

        READ_RET_TYPE readUIntArrSplitC(std::vector <std::uint32_t>& arr,
                                        char delim = '\000');

        READ_RET_TYPE readInt64ArrSplitC(std::vector <std::int64_t>& arr,
                                         char delim = '\000');

        READ_RET_TYPE readUInt64ArrSplitC(std::vector <std::uint64_t>& arr,
                                          char delim = '\000');

        READ_RET_TYPE readFltArrSplitC(std::vector<float>& arr,
                                       char delim = '\000');

        READ_RET_TYPE readDblArrSplitC(std::vector<double>& arr,
                                       char delim = '\000');

        READ_RET_TYPE readInt8ArrSplitS(std::vector <std::int8_t>& arr,
                                        char* delim = nullptr);

        READ_RET_TYPE readUInt8ArrSplitS(std::vector <std::uint8_t>& arr,
                                         char* delim = nullptr);

        READ_RET_TYPE readInt16ArrSplitS(std::vector <std::int16_t>& arr,
                                         char* delim = nullptr);

        READ_RET_TYPE readUInt16ArrSplitS(std::vector <std::uint16_t>& arr,
                                          char* delim = nullptr);

        READ_RET_TYPE readIntArrSplitS(std::vector <std::int32_t>& arr,
                                       char* delim = nullptr);

        READ_RET_TYPE readUIntArrSplitS(std::vector <std::uint32_t>& arr,
                                        char* delim = nullptr);

        READ_RET_TYPE readInt64ArrSplitS(std::vector <std::int64_t>& arr,
                                         char* delim = nullptr);

        READ_RET_TYPE readUInt64ArrSplitS(std::vector <std::uint64_t>& arr,
                                          char* delim = nullptr);

        READ_RET_TYPE readFltArrSplitS(std::vector<float>& arr,
                                       char* delim = nullptr);

        READ_RET_TYPE readDblArrSplitS(std::vector<double>& arr,
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

        inline READ_RET_TYPE readAbstractStr(char*& s,
                                             bool (AbstractReader::*continueCond)() const,
                                             const std::function<bool()>& exitCond = [](){
                                                 return false;
                                             });

        inline READ_RET_TYPE readAbstractStr(std::string& s,
                                             bool (AbstractReader::*continueCond)() const,
                                             const std::function<bool()>& exitCond = [](){
                                                 return false;
                                             });

        template<typename Int>
        inline READ_RET_TYPE readAbstractInt(Int& num, Int limit);

        template<typename Int>
        inline READ_RET_TYPE readAbstractSignedInt(Int& num,
                                                   Int maxSize,
                                                   Int minSize);

        template<typename Real>
        inline READ_RET_TYPE readAbstractReal(Real& num,
                                              Real maxSize,
                                              Real minSize);

        template<typename Num>
        inline READ_RET_TYPE readAbstractNumArr(Num* arr,
                                                std::size_t arrSize,
                                                char delim)
            __nonnull((2));

        template<typename Num>
        inline READ_RET_TYPE readAbstractNumArr(Num* arr,
                                                std::size_t arrSize,
                                                char* delim)
            __nonnull((2));

        template<typename iterableArrT>
        inline READ_RET_TYPE readAbstractNumArr(iterableArrT& arr,
                                                char delim);

        template<typename iterableArrT>
        inline READ_RET_TYPE readAbstractNumArr(iterableArrT& arr,
                                                char* delim);
    };
}

#endif //TESTLIBRARY_ABSTRACTREADER_H
