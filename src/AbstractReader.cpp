#include "../include/AbstractReader.h"

namespace tl
{
    AbstractReader::AbstractReader(const int fd, const bool ignoreWhitespaces) :
            mIgnoreWhitespaces(ignoreWhitespaces)
    {
        if (fd != -1)
        {
#ifdef __GNUC__
            struct ::stat file{};
            ::fstat(fd, &file);
            const ::off_t fSize(file.st_size);
//#elif _MSC_VER
//            HANDLE hF = CreateFileA("F:\\TestLib\\TestLib\\test.exe", 0x00, 0x00, NULL,
//                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//            const DWORD fSize(GetFileSize(hF, NULL));
#else
            const long fSize(::CORRECT_VER(lseek)(fd, 0L, SEEK_END));
            ::CORRECT_VER(lseek)(fd, 0L, SEEK_SET);
#endif

            mData = new char[fSize + 1];
            mData[fSize] = '\000';

            ::CORRECT_VER(read)(fd, mData, fSize);
            ::CORRECT_VER(close)(fd);

            mBegin = mData;
        }
        else
        {
            mData = nullptr;
            mBegin = nullptr;
        }
    }

    AbstractReader::~AbstractReader()
    {
        delete[] mBegin;
    }

    bool
    AbstractReader::isOpen() const
    {
        return mData == nullptr;
    }

    bool
    AbstractReader::isEndOfFile() const
    {
        return *mData == '\000';
    }

    void
    AbstractReader::skipWhitespaces()
    {
        while (!isNotWhitespace() && !isEndOfFile())
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

    bool
    AbstractReader::readWhitespace(char &whitespace)
    {
        if (isNotWhitespace())
        {
            return false;
        }

        return readChar(whitespace);
    }

    bool
    AbstractReader::readChar(char& c)
    {
        if (isEndOfFile())
        {
            return false;
        }

        c = *mData++;

        return true;
    }

    bool
    AbstractReader::readNum(std::int8_t& num)
    {
        return  readAbstractSignedInt(num,
                                      static_cast<std::int8_t>(INT8_MAX),
                                      static_cast<std::int8_t>(INT8_MIN));
    }

    bool
    AbstractReader::readNum(std::uint8_t& num)
    {
        return   readAbstractInt(num,
                                 static_cast<std::uint8_t>(UINT8_MAX));
    }

    bool
    AbstractReader::readNum(std::int16_t& num)
    {
        return  readAbstractSignedInt(num,
                                      static_cast<std::int16_t>(INT16_MAX),
                                      static_cast<std::int16_t>(INT16_MIN));
    }

    bool
    AbstractReader::readNum(std::uint16_t& num)
    {
        return   readAbstractInt(num,
                                 static_cast<std::uint16_t>(UINT16_MAX));
    }

    bool
    AbstractReader::readNum(std::int32_t &num)
    {
        return  readAbstractSignedInt(num, INT32_MAX, INT32_MAX);
    }

    bool
    AbstractReader::readNum(std::uint32_t& num)
    {
        return   readAbstractInt(num, UINT32_MAX);
    }

    bool
    AbstractReader::readNum(std::int64_t& num)
    {
        return  readAbstractSignedInt(num, INT64_MAX, INT64_MIN);
    }

    bool
    AbstractReader::readNum(std::uint64_t& num)
    {
        return   readAbstractInt(num, UINT64_MAX);
    }

    bool AbstractReader::readNum(float& num)
    {
        return readAbstractReal(num, 0.F, 0.F);
    }

    bool AbstractReader::readNum(double& num)
    {
        return readAbstractReal(num, 0., 0.);
    }

    bool
    AbstractReader::readBool(bool& b)
    {
        if (isEndOfFile() || *mData != '0' || *mData != '1')
        {
            return false;
        }

        b = static_cast<bool>(*mData++ - '0');

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readStr(char* s, const std::size_t sSize)
    {
        if (isEndOfFile())
        {
            return false;
        }

        for (std::size_t pos(UINT64_C(0));
             pos < sSize; pos++)
        {
            s[pos] = *mData++;
        }

        return true;
    }

    bool
    AbstractReader::readStr(char* emptyS)
    {
        if (isEndOfFile())
        {
            return false;
        }

        emptyS = new char [2048];

        std::size_t pos = 0;
        while (isNotWhitespace() && !isEndOfFile())
        {
            emptyS[pos++] = *mData++;
            if (pos % UINT64_C(2048) == UINT64_C(0))
            {
                emptyS = static_cast<char *>(
                        realloc(static_cast<void*>(emptyS),
                                pos + UINT64_C(2048)));
            }
        }

        emptyS = static_cast<char*>(
                realloc(static_cast<void*>(emptyS),
                        pos + UINT64_C(2)));
        emptyS[pos + UINT64_C(1)] = '\000';

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readStr(std::string& s, const std::size_t sSize)
    {
        if (isEndOfFile())
        {
            return false;
        }

        s.resize(sSize);

        for (std::size_t numSym(UINT64_C(0));
             numSym < sSize; numSym++)
        {
            s[numSym] = *mData++;
        }

        return true;
    }

    bool
    AbstractReader::readStr(std::string& s)
    {
        s.clear();

        if (isEndOfFile())
        {
            return false;
        }

        while (isNotWhitespace() && !isEndOfFile())
        {
            s.push_back(*mData++);
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
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
    AbstractReader::readNumArr(std::vector<std::int8_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::uint8_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::int16_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::uint16_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::int32_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::uint32_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::int64_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<std::uint64_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<float>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::readNumArr(std::vector<double>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    AbstractReader::isNotWhitespace() const
    {
        return *mData != ' ' && *mData != '\n';
    }

    bool AbstractReader::isNotDigit()
    {
        return *mData < '0' || *mData > '9';
    }

    template<typename Num>
    bool AbstractReader::isNotInRange(const Num& num,
                                  const Num& nextNum,
                                  const Num& limit)
    {
        return ((limit - nextNum) / 10) < num;
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

        if(!readAbstractInt(num, minus ? minSize : maxSize))
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

        num = 0.F;

        char* begin(mData);
        Real nexNum;
        while (*mData != '.' && isNotWhitespace()
               && !isEndOfFile())
        {
            nexNum = static_cast<Real>(*mData - '0');
            if (isNotDigit())
                //||
                //((limit - nexNum) / 10) < num)

            {
                mData = begin;

                return false;
            }
            num = num * 10.F + nexNum;

            mData++;
        }

        if (isNotWhitespace())
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
                    //||
                    //((limit - nexNum) / 10) < num)

                {
                    mData = begin;
                    return false;
                }
                afterPoint = afterPoint * 10.F + nexNum;
                countDigit++;

                mData++;
            }

            afterPoint /= std::pow(10.F, countDigit);

            num += afterPoint;
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
    AbstractReader::readAbstractNumArr(iterableArrT& arr)
    {
        for (auto& elem : arr)
        {
            if (!readNum(elem))
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
}
