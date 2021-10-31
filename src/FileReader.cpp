#include <string>
#include "../include/FileReader.h"



namespace tl
{
    FileReader::FileReader(const char* path) :
            fileDir(::open(path, O_RDONLY)),
            pos(UINT64_C(0))
    {
        if (fileDir != -1)
        {
#ifdef __GNUC__
            struct ::stat file{};
            ::stat(path, &file);
            const ::__off_t fSize(file.st_size);
#elif

#else
            std::FILE* file(std::fopen(path, "r"));
            std::fseek(file, 0, SEEK_END);
            const long fSize(std::ftell(file));
#endif

            mData = static_cast<char*>(std::malloc(fSize));

            ::read(fileDir, mData, fSize);
            ::close(fileDir);

            mBegin = mData;
        }
    }

    FileReader::~FileReader()
    {
        delete mBegin;
    }

    bool FileReader::isOpen() const
    {
        return fileDir != -1;
    }

    bool FileReader::isEndOfFile() const
    {
        return *mData == '\000';
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

    bool FileReader::readStr(std::string& s)
    {
        s.clear();

        if (isEndOfFile())
        {
            return false;
        }

        bool result(false);
        while (*mData != ' ' && !isEndOfFile())
        {
            s.push_back(*mData++);
        }

        mData++;

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
