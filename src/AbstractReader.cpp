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
    AbstractReader::readAllFile(char* fileStr)
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
    AbstractReader::readNumArr(std::int8_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::uint8_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::int16_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::uint16_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::int32_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::uint32_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::int64_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArr(std::uint64_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::int8_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::uint8_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::int16_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::uint16_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::int32_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::uint32_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }
    bool
    AbstractReader::readNumArrSplitC(std::vector <std::int64_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector <std::uint64_t>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector<float>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitC(std::vector<double>& arr, char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::int8_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::uint8_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::int16_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::uint16_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::int32_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::uint32_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::int64_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<std::uint64_t>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<float>& arr, char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readNumArrSplitS(std::vector<double>& arr, char* delim)
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
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

        for (std::size_t numElem(UINT64_C(0));
             numElem < arrSize; numElem++)
        {
            if (!readNum(arr[numElem]))
            {
                return false;
            }

            if (!mIgnoreWhitespaces)
            {
                skipWhitespaces();
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
                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == '\000')
                {
                    if (!readWhitespace(delim))
                    {
                        mData = begin;

                        return false;
                    }
                }
                else
                {
                    if (delim != *mData++ || isWhitespace())
                    {
                        mData = begin;

                        return false;
                    }

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
                    if (!readWhitespaces(delim))
                    {
                        mData = begin;

                        return false;
                    }
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
