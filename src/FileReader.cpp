#include <stdexcept>
#include "../include/FileReader.h"



namespace tl
{
    FileReader::FileReader(const char* path,
                           const bool ignoreWhitespaces) :
            mIgnoreWhitespaces(ignoreWhitespaces)
    {
        const int fileDir(::CORRECT_VER(open)(path, CORRECT_VER(O_RDONLY)));
        if (fileDir != -1)
        {
#ifdef __GNUC__
            struct ::stat file{};
            ::fstat(fileDir, &file);
            const ::off_t fSize(file.st_size);
//#elif _MSC_VER
//            HANDLE hF = CreateFileA("F:\\TestLib\\TestLib\\test.exe", 0x00, 0x00, NULL,
//                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//            const DWORD fSize(GetFileSize(hF, NULL));
#else
            const long fSize(::CORRECT_VER(lseek)(fileDir, 0L, SEEK_END));
            ::CORRECT_VER(lseek)(fileDir, 0L, SEEK_SET);
#endif

            mData = new char[fSize + 1];
            mData[fSize] = '\000';

            ::CORRECT_VER(read)(fileDir, mData, fSize);
            ::CORRECT_VER(close)(fileDir);

            mBegin = mData;
        }
        else
        {
            mData = nullptr;
            mBegin = nullptr;
        }
    }

    FileReader::FileReader(const std::string& path,
                           const bool ignoreWhitespaces) :
            FileReader(path.c_str(), ignoreWhitespaces)
    {

    }

    FileReader::~FileReader()
    {
        delete[] mBegin;
    }

    bool
    FileReader::isOpen() const
    {
        return mData == nullptr;
    }

    bool
    FileReader::isEndOfFile() const
    {
        return *mData == '\000';
    }

    void
    FileReader::skipWhitespaces()
    {
        while (!isNotWhitespace() && !isEndOfFile())
        {
            mData++;
        }
    }

    void
    FileReader::skipChar()
    {
        if (!isEndOfFile())
        {
            mData++;
        }
    }

    bool
    FileReader::readWhitespace(char &whitespace)
    {
        if (isNotWhitespace())
        {
            return false;
        }

        return readChar(whitespace);
    }

    bool
    FileReader::readChar(char& c)
    {
        if (isEndOfFile())
        {
            return false;
        }

        c = *mData++;

        return true;
    }

    bool
    FileReader::readNum(std::int8_t& num)
    {
        return  readAbstractSignedInt(num,
            static_cast<std::int8_t>(INT8_MAX),
            static_cast<std::int8_t>(INT8_MIN));
    }

    bool
    FileReader::readNum(std::uint8_t& num)
    {
        return   readAbstractInt(num,
            static_cast<std::uint8_t>(UINT8_MAX));
    }

    bool
    FileReader::readNum(std::int16_t& num)
    {
        return  readAbstractSignedInt(num,
                                static_cast<std::int16_t>(INT16_MAX),
                                static_cast<std::int16_t>(INT16_MIN));
    }

    bool
    FileReader::readNum(std::uint16_t& num)
    {
        return   readAbstractInt(num,
            static_cast<std::uint16_t>(UINT16_MAX));
    }

    bool
    FileReader::readNum(std::int32_t &num)
    {
        return  readAbstractSignedInt(num, INT32_MAX, INT32_MAX);
    }

    bool
    FileReader::readNum(std::uint32_t& num)
    {
        return   readAbstractInt(num, UINT32_MAX);
    }

    bool
    FileReader::readNum(std::int64_t& num)
    {
        return  readAbstractSignedInt(num, INT64_MAX, INT64_MIN);
    }

    bool
    FileReader::readNum(std::uint64_t& num)
    {
        return   readAbstractInt(num, UINT64_MAX);
    }

//    bool FileReader::readDouble(double num)
//    {
//        if (isEndOfFile())
//        {
//            return false;
//        }
//
//        num = 0.;
//
//        char* begin(mData);
//        double nexNum;
//        while (isNotWhitespace() && !isEndOfFile())
//        {
//            nexNum = *mData - '0';
//            if (*mData < '0' || *mData > '9')
//                    //||
//                ((limit - nexNum) / 10) < num)
//
//            {
//                mData = begin;
//                return false;
//            }
//            num = num * 10. + nexNum;
//
//            mData++;
//        }
//
//        return true;
//    }

    bool
    FileReader::readBool(bool& b)
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
    FileReader::readStr(char* s, const std::size_t sSize)
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
    FileReader::readStr(char* emptyS)
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
    FileReader::readStr(std::string& s, const std::size_t sSize)
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
    FileReader::readStr(std::string& s)
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
    FileReader::readNumArr(std::int8_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::uint8_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::int16_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::uint16_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::int32_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::uint32_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::int64_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::uint64_t* arr, const std::size_t arrSize)
    {
        return readAbstractNumArr(arr, arrSize);
    }

    bool
    FileReader::readNumArr(std::vector<std::int8_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::uint8_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::int16_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::uint16_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::int32_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::uint32_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::int64_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::readNumArr(std::vector<std::uint64_t>& arr)
    {
        return readAbstractNumArr(arr);
    }

    bool
    FileReader::isNotWhitespace() const
    {
        return *mData != ' ' && *mData != '\n';
    }

    template<typename intT>
    bool
    FileReader::readAbstractInt(intT& num, const intT limit)
    {
        if (isEndOfFile())
        {
            return false;
        }

        num = 0;

        char* begin(mData);
        intT nexNum;
        while (isNotWhitespace() && !isEndOfFile())
        {
            nexNum = *mData - '0';
            if (*mData < '0' || *mData > '9' ||
                ((limit - nexNum) / 10) < num)
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

    template<typename intT>
    bool
    FileReader:: readAbstractSignedInt(intT &num, intT maxSize, intT minSize)
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

    template<typename num_t>
    bool
    FileReader::readAbstractNumArr(num_t* arr, const std::size_t arrSize)
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
    FileReader::readAbstractNumArr(iterableArrT& arr)
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
