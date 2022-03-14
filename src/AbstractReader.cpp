#include "../include/AbstractReader.h"

namespace tl
{
    void
    AbstractReader::changeMode()
    {
        FUNC_START_LOG(logger);

        mIgnoreWhitespaces = !mIgnoreWhitespaces;

        FUNC_FINISH_LOG(logger);
    }

    AbstractReader::~AbstractReader()
    {
        FUNC_START_LOG(logger);

        delete[] mBegin;

        FUNC_FINISH_LOG(logger);
    }

    bool
    AbstractReader::isOpen() const
    {
        FUNC_START_LOG(logger);

        BOOL_FUNC_RETURN_LOG(logger, result, mData != nullptr);
    }

    bool
    AbstractReader::isEndOfFile() const
    {
        FUNC_START_LOG(logger);

        BOOL_FUNC_RETURN_LOG(logger, result, *mData == '\000');
    }

    void
    AbstractReader::skipWhitespaces()
    {
        FUNC_START_LOG(logger);

        while (isWhitespace() && !isEndOfFile())
        {
            mData++;
        }

        FUNC_FINISH_LOG(logger);
    }

    void
    AbstractReader::skipChar()
    {
        FUNC_START_LOG(logger);

        if (!isEndOfFile())
        {
            mData++;
        }

        FUNC_FINISH_LOG(logger);
    }

    void
    AbstractReader::readAllFile(char*& fileStr)
    {
        FUNC_START_LOG(logger);

        IS_NOT_OPEN_ASSERT;

        std::strcpy(fileStr, mBegin);

        FUNC_FINISH_LOG(logger);
    }

    READ_RET_TYPE
    AbstractReader::readWhitespace(char& whitespace)
    {
        FUNC_START_LOG(logger);

        IS_NOT_OPEN_ASSERT;

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected whitespace, but found end of file");
        }

        if (isNotWhitespace())
        {
            READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                            "expected whitespace, but found another symbol");
        }

        whitespace = *mData++;

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    READ_RET_TYPE
    AbstractReader::readWhitespaces(char*& whitespaces)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractStr(whitespaces, &AbstractReader::isWhitespace));
    }

    READ_RET_TYPE
    AbstractReader::readWhitespaces(std::string& whitespaces)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractStr(whitespaces, &AbstractReader::isWhitespace));
    }

    READ_RET_TYPE
    AbstractReader::readChar(char& c)
    {
        FUNC_START_LOG(logger);

        IS_NOT_OPEN_ASSERT;

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected char, but found end of file");
        }

        c = *mData++;

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        READ_POS_RESULT(logger, EXIT_SUCCESS);
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::int8_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractSignedInt(num,
                                     static_cast<std::int8_t>(INT8_MAX),
                                     static_cast<std::int8_t>(INT8_MIN)));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::uint8_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractInt(num,
                                static_cast<std::uint8_t>(UINT8_MAX)));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::int16_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractSignedInt(num,
                                     static_cast<std::int16_t>(INT16_MAX),
                                     static_cast<std::int16_t>(INT16_MIN)));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::uint16_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractInt(num,
                               static_cast<std::uint16_t>(UINT16_MAX)));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::int32_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractSignedInt(num, INT32_MAX, INT32_MAX));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::uint32_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractInt(num, UINT32_MAX));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::int64_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractSignedInt(num, INT64_MAX, INT64_MIN));
    }

    READ_RET_TYPE
    AbstractReader::readNum(std::uint64_t& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractInt(num, UINT64_MAX));
    }

    READ_RET_TYPE
    AbstractReader::readInt8(std::int8_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readUInt8(std::uint8_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readInt16(std::int16_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readUInt16(std::uint16_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readInt32(std::int32_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readUInt32(std::uint32_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readInt64(std::int64_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readUInt64(std::uint64_t& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readShort(short& s)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(s));
    }

    READ_RET_TYPE
    AbstractReader::readUShort(unsigned short& s)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(s));
    }

    READ_RET_TYPE
    AbstractReader::readInt(int& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readUInt(unsigned int& i)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result, readNum(i));
    }

    READ_RET_TYPE
    AbstractReader::readLong(long& l)
    {
        FUNC_START_LOG(logger);

#ifdef __GNUC__
        READ_USE_INSERT_FUNC_RESULT(
                logger, result,readNum(l));
#elif defined(_MSC_VER)
        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractSignedInt(l,
                                      static_cast<long>(INT32_MAX),
                                      static_cast<long>(INT32_MIN)));
#endif
    }

    READ_RET_TYPE
    AbstractReader::readULong(unsigned long& l)
    {
        FUNC_START_LOG(logger);

#ifdef __GNUC__
        READ_USE_INSERT_FUNC_RESULT(
                logger, result, readNum(l));
#elif defined(_MSC_VER)
        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractInt(l,
                                static_cast<unsigned long>(UINT32_MAX)));
#endif
    }

    READ_RET_TYPE
    AbstractReader::readLongLong(long long& ll)
    {
        FUNC_START_LOG(logger);

#ifdef __GNUC__
        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractSignedInt(ll,
                                      static_cast<long long>(INT64_MAX),
                                      static_cast<long long>(INT64_MIN)));
#elif defined(_MSC_VER)
        READ_USE_INSERT_FUNC_RESULT(
                logger, result, readNum(ll));
#endif
    }

    READ_RET_TYPE
    AbstractReader::readULongLong(unsigned long long& ll)
    {
        FUNC_START_LOG(logger);

#ifdef __GNUC__
        READ_USE_INSERT_FUNC_RESULT(
                logger, result,
                readAbstractInt(ll,
                                static_cast<unsigned long long>(UINT64_MAX)));
#elif defined(_MSC_VER)
        READ_USE_INSERT_FUNC_RESULT(
                logger, result, readNum(ll));
#endif
    }

    READ_RET_TYPE
    AbstractReader::readHugeInt(hugeIntPtr& i)
    {
        FUNC_START_LOG(logger);

        //TODO refactoring

        return readAbstractStr(i, &AbstractReader::isNotWhitespace,
                               [this]()
                               {
                                   return isNotDigit();
                               });
    }

    READ_RET_TYPE
    AbstractReader::readHugeInt(hugeInt& i)
    {
        FUNC_START_LOG(logger);
        //TODO refactoring

        return readAbstractStr(i, &AbstractReader::isNotWhitespace,
                               [this]()
                               {
                                   return isNotDigit();
                               });
    }

    READ_RET_TYPE
    AbstractReader::readNum(float& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result,
                                    readAbstractReal(num, FLT_MAX, FLT_MIN));
    }

    READ_RET_TYPE
    AbstractReader::readNum(double& num)
    {
        FUNC_START_LOG(logger);

        READ_USE_INSERT_FUNC_RESULT(logger, result,
                                    readAbstractReal(num, DBL_MAX, DBL_MIN));
    }

    READ_RET_TYPE
    AbstractReader::readBool(bool& b)
    {
        FUNC_START_LOG(logger);

        IS_NOT_OPEN_ASSERT;

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected bool, but found end of file");
        }

        if((*mData != '0' && *mData != '1'))
        {
            READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                            "expected bool, but found another symbol");
        }

        b = static_cast<bool>(*mData++ - '0');

        if (isNotWhitespace() && !isEndOfFile())
        {
            mData--;

            READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                            "expected whitespace after bool");
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    READ_RET_TYPE
    AbstractReader::readStr(char* s, const std::size_t sSize)
    {
        FUNC_START_LOG(logger);

        IS_NOT_OPEN_ASSERT;

        TESTLIBRARY_NONNULL_ASSERT(s);

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected bool, but found end of file");
        }

        //TODO reactoring
        for (std::size_t pos(UINT64_C(0));
             pos < sSize; pos++)
        {
//            if (!readChar(s[pos]))
//            {
//                READ_NEG_RESULT(logger, READ_INCORRECT_SIZE,
//                                "to less symbols");
//            }
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    READ_RET_TYPE
    AbstractReader::readStr(char*& emptyS)
    {
        FUNC_START_LOG(logger);

        //TODO refactoring
        return readAbstractStr(emptyS, &AbstractReader::isNotWhitespace);
    }

    READ_RET_TYPE
    AbstractReader::readStr(std::string& s, const std::size_t sSize)
    {
        FUNC_START_LOG(logger);

        //TODO refactoring
//        if (isEndOfFile())
//        {
//            return false;
//        }
//
//        s.resize(sSize);
//
//        char* begin = mData;
//        for (char& sym : s)
//        {
//            if (mIgnoreWhitespaces)
//            {
//                skipWhitespaces();
//            }
//
//            if (!readChar(sym))
//            {
//                mData = begin;
//
//                return false;
//            }
//        }
//
//        if (mIgnoreWhitespaces)
//        {
//            skipWhitespaces();
//        }
//
//        return true;
    }

    READ_RET_TYPE
    AbstractReader::readStr(std::string& s)
    {
        FUNC_START_LOG(logger);

        //TODO refactoring
        return readAbstractStr(s, &AbstractReader::isNotWhitespace);
    }

    READ_RET_TYPE
    AbstractReader::readInt8ArrSplitC(std::int8_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt8ArrSplitC(std::uint8_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt16ArrSplitC(std::int16_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt16ArrSplitC(std::uint16_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readIntArrSplitC(std::int32_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUIntArrSplitC(std::uint32_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt64ArrSplitC(std::int64_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt64ArrSplitC(std::uint64_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt8ArrSplitS(std::int8_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt8ArrSplitS(std::uint8_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt16ArrSplitS(std::int16_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt16ArrSplitS(std::uint16_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readIntArrSplitS(std::int32_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUIntArrSplitS(std::uint32_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt64ArrSplitS(std::int64_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt64ArrSplitS(std::uint64_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt8ArrSplitC(std::vector <std::int8_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt8ArrSplitC(std::vector <std::uint8_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt16ArrSplitC(std::vector <std::int16_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt16ArrSplitC(std::vector <std::uint16_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readIntArrSplitC(std::vector <std::int32_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUIntArrSplitC(std::vector <std::uint32_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }
    READ_RET_TYPE
    AbstractReader::readInt64ArrSplitC(std::vector <std::int64_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt64ArrSplitC(std::vector <std::uint64_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readFltArrSplitC(std::vector<float>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readDblArrSplitC(std::vector<double>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt8ArrSplitS(std::vector<std::int8_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt8ArrSplitS(std::vector<std::uint8_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt16ArrSplitS(std::vector<std::int16_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt16ArrSplitS(std::vector<std::uint16_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readIntArrSplitS(std::vector<std::int32_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUIntArrSplitS(std::vector<std::uint32_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readInt64ArrSplitS(std::vector<std::int64_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readUInt64ArrSplitS(std::vector<std::uint64_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readFltArrSplitS(std::vector<float>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    READ_RET_TYPE
    AbstractReader::readDblArrSplitS(std::vector<double>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    AbstractReader::AbstractReader(const bool ignoreWhitespaces) :
            mIgnoreWhitespaces(ignoreWhitespaces),
            mData(nullptr),
            mBegin(nullptr)
    {
        FUNC_START_LOG(logger, ignoreWhitespaces ? "true" : "false");

        FUNC_FINISH_LOG(logger);
    }

    bool
    AbstractReader::isNotWhitespace() const
    {
        FUNC_START_LOG(logger);

        BOOL_FUNC_RETURN_LOG(logger, result,
                             *mData != ' ' && *mData != '\n' && *mData != '\r');
    }

    bool
    AbstractReader::isWhitespace() const
    {
        FUNC_START_LOG(logger);

        BOOL_FUNC_RETURN_LOG(logger, result, !isNotWhitespace());
    }

    bool
    AbstractReader::isNotDigit()
    {
        FUNC_START_LOG(logger);

        BOOL_FUNC_RETURN_LOG(logger, result,
                             *mData < '0' || *mData > '9');
    }

    template<typename Num>
    bool
    AbstractReader::isNotInRange(const Num& num,
                                 const Num& nextNum,
                                 const Num& limit)
    {
        FUNC_START_LOG(logger, (std::to_string(num) + ", " +
                               std::to_string(nextNum) + ", " +
                               std::to_string(limit)).c_str());

        BOOL_FUNC_RETURN_LOG(logger, result, ((limit - nextNum) / 10) < num);
    }

#define BUFF_SIZE UINT64_C(256)

    READ_RET_TYPE
    AbstractReader::readAbstractStr(char*& s,
                                    bool (AbstractReader::*continueCond)() const,
                                    const std::function<bool()>& exitCond)
    {
        //TODO refactoring
        FUNC_START_LOG(logger);

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected string, but found end of file");
        }

        if (!(this->*continueCond)())
        {
            READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                            "");
        }

        s = new char [BUFF_SIZE];

        std::size_t pos = 0;
        while ((this->*continueCond)() && !isEndOfFile())
        {
            if (exitCond())
            {
                s = static_cast<char*>(
                        realloc(static_cast<void*>(s),
                                pos + UINT64_C(1)));
                s[pos] = '\000';

                READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                                "");
            }

            s[pos++] = *mData++;
            if (pos % BUFF_SIZE == UINT64_C(0))
            {
                s = static_cast<char*>(
                        realloc(static_cast<void*>(s),
                                pos + BUFF_SIZE));
            }
        }

        s = static_cast<char*>(
                realloc(static_cast<void*>(s),
                        pos + UINT64_C(1)));
        s[pos] = '\000';

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    READ_RET_TYPE
    AbstractReader::readAbstractStr(std::string& s,
                                    bool (AbstractReader::*continueCond)() const,
                                    const std::function<bool()>& exitCond)
    {
        //TODO refactoring
        FUNC_START_LOG(logger);

        s.clear();

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected string, but found end of file");
        }

        if (!(this->*continueCond)())
        {
            READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                            "");
        }

        while ((this->*continueCond)() && !isEndOfFile())
        {
            if (exitCond())
            {
                READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                                "");
            }

            s.push_back(*mData++);
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    template<typename Int>
    READ_RET_TYPE
    AbstractReader::readAbstractInt(Int& num, const Int limit)
    {
        FUNC_START_LOG(logger, "%lld", limit);

        IS_NOT_OPEN_ASSERT;

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected int, but found end of file");
        }

        num = 0;

        char* begin(mData);
        Int nextNum;
        while (isNotWhitespace() && !isEndOfFile())
        {
            nextNum = *mData - '0';
            if (isNotDigit() || isNotInRange(num, nextNum, limit))
            {
                mData = begin;

                READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                                "found another type");
            }
            num = num * 10 + nextNum;

            mData++;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    template<typename Int>
    READ_RET_TYPE
    AbstractReader:: readAbstractSignedInt(Int& num, const Int maxSize, const Int minSize)
    {
        FUNC_START_LOG(logger, "%lld, %lld", maxSize, minSize);

        IS_NOT_OPEN_ASSERT;

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected int, but found end of file");
        }

        bool minus(false);
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        READ_CHECK_INSERT_FUNC_RESULT(logger,
                                      result,
                                      readAbstractInt(num, minus ? minSize : maxSize));

        if (minus)
        {
            num *= -1;
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    template<typename Real>
    READ_RET_TYPE
    AbstractReader::readAbstractReal(Real& num, const Real maxSize, const Real minSize)
    {
        FUNC_START_LOG(logger, "%lf, %lf", maxSize, minSize);

        IS_NOT_OPEN_ASSERT;

        if (isEndOfFile())
        {
            READ_NEG_RESULT(logger, READ_EOF,
                            "expected real, but found end of file");
        }

        bool minus(false);
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        Real limit = minus ? minSize : maxSize;

        num = 0.F;

        char* begin(mData);
        Real nextNum;
        while (*mData != '.' && isNotWhitespace()
               && !isEndOfFile())
        {
            nextNum = static_cast<Real>(*mData - '0');
            if (isNotDigit()
                || isNotInRange(num, nextNum, limit))
            {
                mData = begin;

                READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                                "expected real");
            }
            num = num * 10.F + nextNum;

            mData++;
        }

        if (isNotWhitespace() && !isEndOfFile())
        {
            if (*mData++ != '.')
            {
                mData = begin;

                READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                                "expected \'.\' or whitespace or end of file");
            }

            Real afterPoint = 0.F;
            Real countDigit = 0.F;

            while (isNotWhitespace() && !isEndOfFile())
            {
                nextNum = static_cast<Real>(*mData - '0');
                if (isNotDigit())
                {
                    mData = begin;

                    READ_NEG_RESULT(logger, READ_TYPE_ERROR,
                                    "expected digit, but found another symbol");
                }
                afterPoint = afterPoint * 10.F + nextNum;
                countDigit++;

                mData++;
            }

            afterPoint /= std::pow(10.F, countDigit);

            //TODO fix afterPoint limit

            if (((limit - afterPoint) / 10) < num)
            {
                mData = begin;

                READ_NEG_RESULT(logger, READ_TYPE_ERROR, "");
            }

            num += afterPoint;
        }

        if (minus)
        {
            num *= -1.F;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        READ_POS_RESULT(logger, READ_SUCCESS);
    }

    //TODO refactoring
    template<typename Num>
    READ_RET_TYPE
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize,
                                       char delim)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

//        char* begin = mData;
//
//        for (std::size_t numElem(UINT64_C(0));
//             numElem < arrSize; numElem++)
//        {
//            if (!readNum(arr[numElem]))
//            {
//                mData = begin;
//
//                return false;
//            }
//
//            if (!mIgnoreWhitespaces && !isEndOfFile())
//            {
//                if (delim == '\000')
//                {
//                    readWhitespace(delim);
//                }
//                else if (delim != *mData++ || isWhitespace())
//                {
//                    mData = begin;
//
//                    return false;
//                }
//            }
//        }
//
//        return true;
    }

    //TODO refactoring
    template<typename Num>
    READ_RET_TYPE
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize,
                                       char* delim)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

//        char* begin = mData;
//
//        for (std::size_t numElem(UINT64_C(0));
//             numElem < arrSize; numElem++)
//        {
//            if (!readNum(arr[numElem]))
//            {
//                mData = begin;
//
//                return false;
//            }
//
//            if (!mIgnoreWhitespaces && !isEndOfFile())
//            {
//                if (delim == nullptr)
//                {
//                    readWhitespaces(delim);
//                }
//                else
//                {
//                    for (std::size_t numDigitSym(UINT64_C(0));
//                         delim[numDigitSym] != '\000';
//                         numDigitSym++)
//                    {
//                        if (delim[numDigitSym] != *mData++)
//                        {
//                            mData = begin;
//
//                            return false;
//                        }
//                    }
//                }
//            }
//        }
//
//        return true;
    }

    //TODO refactoring
    template<typename iterableArrT>
    READ_RET_TYPE
    AbstractReader::readAbstractNumArr(iterableArrT& arr, char delim)
    {
//        char* begin = mData;
//
//        for (auto& elem : arr)
//        {
//            if (!readNum(elem))
//            {
//                mData = begin;
//
//                return false;
//            }
//
//            if (!mIgnoreWhitespaces && !isEndOfFile())
//            {
//                if (delim == '\000')
//                {
//                    readWhitespace(delim);
//                }
//                else if (delim != *mData++ || isWhitespace())
//                {
//                    mData = begin;
//
//                    return false;
//                }
//            }
//        }
//
//        return true;
    }

    //TODO refactoring
    template<typename iterableArrT>
    READ_RET_TYPE
    AbstractReader::readAbstractNumArr(iterableArrT& arr, char* delim)
    {
//        char* begin = mData;
//
//        for (auto& elem : arr)
//        {
//            if (!readNum(elem))
//            {
//                return false;
//            }
//
//            if (!mIgnoreWhitespaces && !isEndOfFile())
//            {
//                if (delim == nullptr)
//                {
//                    readWhitespaces(delim);
//                }
//                else
//                {
//                    for (std::size_t numDigitSym(UINT64_C(0));
//                         delim[numDigitSym] != '\000';
//                         numDigitSym++)
//                    {
//                        if (delim[numDigitSym] != *mData++)
//                        {
//                            mData = begin;
//
//                            return false;
//                        }
//                    }
//                }
//            }
//        }
//
//        return true;
    }
}
