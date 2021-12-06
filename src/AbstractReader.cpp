#include "../include/AbstractReader.h"

namespace tl
{
    void AbstractReader::changeMode()
    {
        mIgnoreWhitespaces = !mIgnoreWhitespaces;
    }

    AbstractReader::~AbstractReader()
    {
        delete[] mBegin;
    }

    bool
    AbstractReader::isOpen() const
    {
        return mData != nullptr;
    }

    bool
    AbstractReader::isEndOfFile() const
    {
        return *mData == '\000';
    }

    void
    AbstractReader::skipWhitespaces()
    {
        while (isWhitespace() && !isEndOfFile())
        {
            mData++;
        }
    }

    void
    AbstractReader::skipChar()
    {
        if (!isEndOfFile())
        {
            mData++;
        }
    }

    void
    AbstractReader::readAllFile(char*& fileStr)
    {
        fileStr = mBegin;
    }

    bool
    AbstractReader::readWhitespace(char& whitespace)
    {
        if (isNotWhitespace())
        {
            return false;
        }

        return readChar(whitespace);
    }

    bool
    AbstractReader::readWhitespaces(char*& whitespaces)
    {
        return readAbstractStr(whitespaces, &AbstractReader::isWhitespace);
    }

    bool
    AbstractReader::readWhitespaces(std::string& whitespaces)
    {
        return readAbstractStr(whitespaces, &AbstractReader::isWhitespace);
    }

    bool
    AbstractReader::readChar(char& c)
    {
        if (isEndOfFile())
        {
            return false;
        }

        c = *mData++;

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readNum(std::int8_t& num)
    {
        return readAbstractSignedInt(num,
                                     static_cast<std::int8_t>(INT8_MAX),
                                     static_cast<std::int8_t>(INT8_MIN));
    }

    bool
    AbstractReader::readNum(std::uint8_t& num)
    {
        return readAbstractInt(num,
                               static_cast<std::uint8_t>(UINT8_MAX));
    }

    bool
    AbstractReader::readNum(std::int16_t& num)
    {
        return readAbstractSignedInt(num,
                                     static_cast<std::int16_t>(INT16_MAX),
                                     static_cast<std::int16_t>(INT16_MIN));
    }

    bool
    AbstractReader::readNum(std::uint16_t& num)
    {
        return readAbstractInt(num,
                               static_cast<std::uint16_t>(UINT16_MAX));
    }

    bool
    AbstractReader::readNum(std::int32_t &num)
    {
        return readAbstractSignedInt(num, INT32_MAX, INT32_MAX);
    }

    bool
    AbstractReader::readNum(std::uint32_t& num)
    {
        return readAbstractInt(num, UINT32_MAX);
    }

    bool
    AbstractReader::readNum(std::int64_t& num)
    {
        return readAbstractSignedInt(num, INT64_MAX, INT64_MIN);
    }

    bool
    AbstractReader::readNum(std::uint64_t& num)
    {
        return readAbstractInt(num, UINT64_MAX);
    }

    bool
    AbstractReader::readInt8(std::int8_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt8(std::uint8_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readInt16(std::int16_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt16(std::uint16_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readInt32(std::int32_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt32(std::uint32_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readInt64(std::int64_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt64(std::uint64_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readShort(short& s)
    {
        return readNum(s);
    }

    bool
    AbstractReader::readUShort(unsigned short& s)
    {
        return readNum(s);
    }

    bool
    AbstractReader::readInt(int& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt(unsigned int& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readLong(long& l)
    {
#ifdef __GNUC__
        return readNum(l);
#elif defined(_MSC_VER)
        return readAbstractSignedInt(l,
            static_cast<long>(INT32_MAX),
            static_cast<long>(INT32_MIN));
#endif
    }

    bool
    AbstractReader::readULong(unsigned long& l)
    {
#ifdef __GNUC__
        return readNum(l);
#elif defined(_MSC_VER)
        return readAbstractInt(l,
            static_cast<unsigned long>(UINT32_MAX));
#endif
    }

    bool
    AbstractReader::readLongLong(long long& ll)
    {
#ifdef __GNUC__
        return readAbstractSignedInt(ll,
            static_cast<long long>(INT64_MAX),
            static_cast<long long>(INT64_MIN));
#elif defined(_MSC_VER)
        return readNum(ll);
#endif
    }

    bool
    AbstractReader::readULongLong(unsigned long long& ll)
    {
#ifdef __GNUC__
        return readAbstractInt(ll,
            static_cast<unsigned long long>(UINT64_MAX));
#elif defined(_MSC_VER)
        return readNum(ll);
#endif
    }

    bool
    AbstractReader::readHugeInt(hugeIntPtr& num)
    {
        return readAbstractStr(num, &AbstractReader::isNotWhitespace,
                               [this]()
                                {
                                    return isNotDigit();
                                });
    }

    bool
    AbstractReader::readHugeInt(hugeInt& num)
    {
        return readAbstractStr(num, &AbstractReader::isNotWhitespace,
                               [this]()
                               {
                                   return isNotDigit();
                               });
    }

    bool
    AbstractReader::readNum(float& num)
    {
        return readAbstractReal(num, FLT_MAX, FLT_MIN);
    }

    bool
    AbstractReader::readNum(double& num)
    {
        return readAbstractReal(num, DBL_MAX, DBL_MIN);
    }

    bool
    AbstractReader::readBool(bool& b)
    {
        if (isEndOfFile() || (*mData != '0' && *mData != '1'))
        {
            return false;
        }

        b = static_cast<bool>(*mData++ - '0');

        if (isNotWhitespace())
        {
            mData--;

            return false;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readStr(char* s, const std::size_t sSize)
    {
        TESTLIBRARY_NONNULL_ASSERT(s);

        if (isEndOfFile())
        {
            return false;
        }

        for (std::size_t pos(UINT64_C(0));
             pos < sSize; pos++)
        {
            if (!readChar(s[pos]))
            {
                return false;
            }
        }

        return true;
    }

    bool
    AbstractReader::readStr(char*& emptyS)
    {
        return readAbstractStr(emptyS, &AbstractReader::isNotWhitespace);
    }

    bool
    AbstractReader::readStr(std::string& s, const std::size_t sSize)
    {
        if (isEndOfFile())
        {
            return false;
        }

        s.resize(sSize);

        char* begin = mData;
        for (char& sym : s)
        {
            if (mIgnoreWhitespaces)
            {
                skipWhitespaces();
            }

            if (!readChar(sym))
            {
                mData = begin;

                return false;
            }
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readStr(std::string& s)
    {
        return readAbstractStr(s, &AbstractReader::isNotWhitespace);
    }

    bool
    AbstractReader::readInt8ArrSplitC(std::int8_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitC(std::uint8_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitC(std::int16_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitC(std::uint16_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readIntArrSplitC(std::int32_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUIntArrSplitC(std::uint32_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt64ArrSplitC(std::int64_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitC(std::uint64_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt8ArrSplitS(std::int8_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitS(std::uint8_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitS(std::int16_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitS(std::uint16_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readIntArrSplitS(std::int32_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUIntArrSplitS(std::uint32_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt64ArrSplitS(std::int64_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitS(std::uint64_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt8ArrSplitC(std::vector <std::int8_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitC(std::vector <std::uint8_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitC(std::vector <std::int16_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitC(std::vector <std::uint16_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readIntArrSplitC(std::vector <std::int32_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUIntArrSplitC(std::vector <std::uint32_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }
    bool
    AbstractReader::readInt64ArrSplitC(std::vector <std::int64_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitC(std::vector <std::uint64_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readFltArrSplitC(std::vector<float>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readDblArrSplitC(std::vector<double>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt8ArrSplitS(std::vector<std::int8_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitS(std::vector<std::uint8_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitS(std::vector<std::int16_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitS(std::vector<std::uint16_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readIntArrSplitS(std::vector<std::int32_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUIntArrSplitS(std::vector<std::uint32_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt64ArrSplitS(std::vector<std::int64_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitS(std::vector<std::uint64_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readFltArrSplitS(std::vector<float>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
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

    }

    bool
    AbstractReader::isNotWhitespace() const
    {
        return *mData != ' ' && *mData != '\n';
    }

    bool
    AbstractReader::isWhitespace() const
    {
        return *mData == ' ' || *mData == '\n';
    }

    bool
    AbstractReader::isNotDigit()
    {
        return *mData < '0' || *mData > '9';
    }

    template<typename Num>
    bool
    AbstractReader::isNotInRange(const Num& num,
                                  const Num& nextNum,
                                  const Num& limit)
    {
        return ((limit - nextNum) / 10) < num;
    }

#define BUFF_SIZE UINT64_C(256)

    bool
    AbstractReader::readAbstractStr(char*& s,
                                    bool (AbstractReader::*continueCond)() const,
                                    const std::function<bool()>& exitCond)
    {
        if (isEndOfFile() || !(this->*continueCond)())
        {
            s = nullptr;

            return false;
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

                return false;
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

        return true;
    }

    bool
    AbstractReader::readAbstractStr(std::string& s,
                                    bool (AbstractReader::*continueCond)() const,
                                    const std::function<bool()>& exitCond)
    {
        s.clear();

        if (isEndOfFile())
        {
            return false;
        }

        while ((this->*continueCond)() && !isEndOfFile())
        {
            if (exitCond())
            {
                return false;
            }

            s.push_back(*mData++);
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    template<typename Int>
    bool
    AbstractReader::readAbstractInt(Int& num, const Int limit)
    {
        if (isEndOfFile())
        {
            return false;
        }

        num = 0;

        char* begin(mData);
        Int nexNum;
        while (isNotWhitespace() && !isEndOfFile())
        {
            nexNum = *mData - '0';
            if (isNotDigit() || isNotInRange(num, nexNum, limit))
            {
                mData = begin;

                return false;
            }
            num = num * 10 + nexNum;

            mData++;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    template<typename Int>
    bool
    AbstractReader:: readAbstractSignedInt(Int& num, const Int maxSize, const Int minSize)
    {
        bool minus = false;
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        if (!readAbstractInt(num, minus ? minSize : maxSize))
        {
            return false;
        }

        if (minus)
        {
            num *= -1;
        }

        return true;
    }

    template<typename Real>
    bool
    AbstractReader::readAbstractReal(Real& num, const Real maxSize, const Real minSize)
    {
        if (isEndOfFile())
        {
            return false;
        }

        bool minus = false;
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        double limit = minus ? minSize : maxSize;

        num = 0.F;

        char* begin(mData);
        Real nexNum;
        while (*mData != '.' && isNotWhitespace()
               && !isEndOfFile())
        {
            nexNum = static_cast<Real>(*mData - '0');
            if (isNotDigit()
                || ((limit - nexNum) / 10) < num)
            {
                mData = begin;

                return false;
            }
            num = num * 10.F + nexNum;

            mData++;
        }

        if (isNotWhitespace() && !isEndOfFile())
        {
            if (*mData++ != '.')
            {
                mData = begin;

                return false;
            }

            Real afterPoint = 0.F;
            Real countDigit = 0.F;

            while (isNotWhitespace() && !isEndOfFile())
            {
                nexNum = static_cast<Real>(*mData - '0');
                if (isNotDigit())
                {
                    mData = begin;

                    return false;
                }
                afterPoint = afterPoint * 10.F + nexNum;
                countDigit++;

                mData++;
            }

            afterPoint /= std::pow(10.F, countDigit);

            if (((limit - afterPoint) / 10) < num)
            {
                mData = begin;

                return false;
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

        return true;
    }

    template<typename Num>
    bool
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize,
                                       char delim)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

        char* begin = mData;

        for (std::size_t numElem(UINT64_C(0));
             numElem < arrSize; numElem++)
        {
            if (!readNum(arr[numElem]))
            {
                mData = begin;

                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == '\000')
                {
                    readWhitespace(delim);
                }
                else if (delim != *mData++ || isWhitespace())
                {
                    mData = begin;

                    return false;
                }
            }
        }

        return true;
    }

    template<typename Num>
    bool
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize,
                                       char* delim)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

        char* begin = mData;

        for (std::size_t numElem(UINT64_C(0));
             numElem < arrSize; numElem++)
        {
            if (!readNum(arr[numElem]))
            {
                mData = begin;

                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == nullptr)
                {
                    readWhitespaces(delim);
                }
                else
                {
                    for (std::size_t numDigitSym(UINT64_C(0));
                         delim[numDigitSym] != '\000';
                         numDigitSym++)
                    {
                        if (delim[numDigitSym] != *mData++)
                        {
                            mData = begin;

                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    template<typename iterableArrT>
    bool
    AbstractReader::readAbstractNumArr(iterableArrT& arr, char delim)
    {
        char* begin = mData;

        for (auto& elem : arr)
        {
            if (!readNum(elem))
            {
                mData = begin;

                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == '\000')
                {
                    readWhitespace(delim);
                }
                else if (delim != *mData++ || isWhitespace())
                {
                    mData = begin;

                    return false;
                }
            }
        }

        return true;
    }

    template<typename iterableArrT>
    bool
    AbstractReader::readAbstractNumArr(iterableArrT& arr, char* delim)
    {
        char* begin = mData;

        for (auto& elem : arr)
        {
            if (!readNum(elem))
            {
                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == nullptr)
                {
                    readWhitespaces(delim);
                }
                else
                {
                    for (std::size_t numDigitSym(UINT64_C(0));
                         delim[numDigitSym] != '\000';
                         numDigitSym++)
                    {
                        if (delim[numDigitSym] != *mData++)
                        {
                            mData = begin;

                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}
