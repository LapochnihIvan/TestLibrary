#include "../include/FileReader.h"



namespace tl
{
    FileReader::FileReader(const char* path) :
            mFileDir(::CORRECT_VER(open)(path, CORRECT_VER(O_RDONLY)))
    {
        if (mFileDir != -1)
        {
#ifdef __GNUC__
            struct ::stat file{};
            ::stat(path, &file);
            const ::__off_t fSize(file.st_size);
//#elif _MSC_VER
//            HANDLE hF = CreateFileA("F:\\TestLib\\TestLib\\test.exe", 0x00, 0x00, NULL,
//                OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//            const DWORD fSize(GetFileSize(hF, NULL));
#else
            const long fSize(::CORRECT_VER(lseek)(mFileDir, 0L, SEEK_END));
            ::CORRECT_VER(lseek)(mFileDir, 0L, SEEK_SET);
#endif

            mData = new char[fSize + 1];
            mData[fSize] = '\000';

            ::CORRECT_VER(read)(mFileDir, mData, fSize);
            ::CORRECT_VER(close)(mFileDir);

            mBegin = mData;
        }
        else
        {
            mData = nullptr;
            mBegin = nullptr;
        }
    }

    FileReader::FileReader(const std::string& path) :
            FileReader(path.c_str())
    {

    }

    FileReader::~FileReader()
    {
        delete[] mBegin;
    }

    bool FileReader::isOpen() const
    {
        return mFileDir != -1;
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

    bool FileReader::readNextInt(int &num)
    {
        num = 0;

        if (isEndOfFile())
        {
            return false;
        }

        char* begin(mData);
        while (*mData != ' ' && !isEndOfFile())
        {
            num *= 10;
            if (*mData < '0' || *mData > '9')
            {
                mData = begin;
                return false;
            }
            num += *mData++ - '0';
        }

        mData++;

        return true;
    }

    bool FileReader::readStr(char*& s, const std::size_t size)
    {
        return false;
    }

    bool FileReader::readStr(std::string& s)
    {
        s.clear();

        if (isEndOfFile())
        {
            return false;
        }

        while (*mData != ' ' && !isEndOfFile())
        {
            s.push_back(*mData++);
        }

        mData++;

        return true;
    }

    bool FileReader::readBool(bool& b)
    {
        if (isEndOfFile() || *mData != '0' || *mData != '1')
        {
            return false;
        }

        b = static_cast<bool>(*mData++ - '0');

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
