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
            ::stat(path, &file);
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

    bool FileReader::isOpen() const
    {
        return mData == nullptr;
    }

    bool FileReader::isEndOfFile() const
    {
        return *mData == '\000';
    }

    bool FileReader::readChar(char& c)
    {
        if (isEndOfFile())
        {
            return false;
        }

        c = *mData++;

        return true;
    }

    void FileReader::skipChar()
    {
        if (!isEndOfFile())
        {
            mData++;
        }
    }

    bool FileReader::readNextInt(std::int8_t& num)
    {
        return readSignedIntNum(num,
            static_cast<std::int8_t>(INT8_MAX),
            static_cast<std::int8_t>(INT8_MIN));
    }

    bool FileReader::readNextInt(std::uint8_t& num)
    {
        return readIntNum(num,
            static_cast<std::uint8_t>(UINT8_MAX));
    }

    bool FileReader::readNextInt(std::int16_t& num)
    {
        return readSignedIntNum(num,
                                static_cast<std::int16_t>(INT16_MAX),
                                static_cast<std::int16_t>(INT16_MIN));
    }

    bool FileReader::readNextInt(std::uint16_t& num)
    {
        return readIntNum(num,
            static_cast<std::uint16_t>(UINT16_MAX));
    }

    bool FileReader::readNextInt(std::int32_t &num)
    {
        return readSignedIntNum(num, INT32_MAX, INT32_MAX);
    }

    bool FileReader::readNextInt(std::uint32_t& num)
    {
        return readIntNum(num, UINT32_MAX);
    }

    bool FileReader::readNextInt(std::int64_t& num)
    {
        return readSignedIntNum(num, INT64_MAX, INT64_MIN);
    }

    bool FileReader::readNextInt(std::uint64_t& num)
    {
        return readIntNum(num, UINT64_MAX);
    }

    bool FileReader::readStr(char*& s, const std::size_t size)
    {
        if (isEndOfFile())
        {
            return false;
        }

        for (std::size_t pos = UINT64_C(0);
            pos < size; pos++)
        {
            s[pos] = *mData++;
        }

        return true;
    }

    bool FileReader::readStr(char*& s)
    {
        if (isEndOfFile())
        {
            return false;
        }

        s = new char [2048];

        std::size_t pos = 0;
        while (isNotWhitespace() && !isEndOfFile())
        {
            s[pos++] = *mData++;
            if (pos % UINT64_C(2048) == UINT64_C(0))
            {
                s = static_cast<char *>(
                    realloc(static_cast<void*>(s),
                    pos + UINT64_C(2048)));
            }
        }

        s = static_cast<char*>(
            realloc(static_cast<void*>(s),
            pos + UINT64_C(2)));
        s[pos + UINT64_C(1)] = '\000';

        if (mIgnoreWhitespaces)
        {
            mData++;
        }

        return true;
    }

    bool FileReader::readStr(std::string& s, std::size_t size)
    {
        if (isEndOfFile())
        {
            return false;
        }

        s.resize(size);

        for (std::size_t numSym(UINT64_C(0));
            numSym < size; numSym++)
        {
            s[numSym] = *mData++;
        }

        return true;
    }

    bool FileReader::readStr(std::string& s)
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
            mData++;
        }

        return true;
    }

    bool FileReader::readBool(bool& b)
    {
        if (isEndOfFile() || *mData != '0' || *mData != '1')
        {
            return false;
        }

        b = static_cast<bool>(*mData++ - '0');

        if (mIgnoreWhitespaces && !isNotWhitespace())
        {
            mData++;
        }

        return true;
    }

    bool FileReader::readWhitespace(char &whitespace)
    {
        if (isNotWhitespace())
        {
            return false;
        }

        return readChar(whitespace);
    }

    bool FileReader::isNotWhitespace() const
    {
        return *mData != ' ' && *mData != '\n';
    }

    template<typename Int>
    bool FileReader::readIntNum(Int& num, const Int limit)
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
            mData++;
        }

        return true;
    }

    template<typename Int>
    bool FileReader::readSignedIntNum(Int &num, Int maxSize, Int minSize)
    {
        bool minus = false;
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        if(!readIntNum(num, minus ? minSize : maxSize))
        {
            return false;
        }

        if (minus)
        {
            num *= -1;
        }

        return true;
    }

    std::size_t
    FileReader::charPtrSize(const char* charPtr)
    {
        const char* begin = charPtr;

        while (*charPtr != '\000')
        {
            charPtr++;
        }

        return charPtr - begin;
    }
}
