#include "InStream.h"

#if __cplusplus >= 201703L
namespace tl::bc
#else
namespace tl { namespace bc
#endif //__cplusplus >= 201703L
{
    InStream::InStream(tl::AbstractReader& reader) :
            mReader(reader)
    {

    }

    bool
    InStream::seekEof()
    {
        return mReader.isEndOfFile();
    }

    void
    InStream::readWordTo(std::string& result)
    {
        mReader.readStr(result);
    }

    void
    InStream::readTokenTo(std::string& result)
    {
        mReader.readStr(result);
    }

    void
    InStream::readStringTo(std::string& result)
    {
        mReader.readStr(result);
    }

    std::string
    InStream::readWord()
    {
        std::string result;
        mReader.readStr(result);

        return result;
    }

    std::string
    InStream::readToken()
    {
        return readWord();
    }

    std::string
    InStream::readString()
    {
        return readWord();
    }

    int
    InStream::readInteger()
    {
        int result;
        mReader.readNum(result);

        return result;
    }

    int
    InStream::readInt()
    {
        return readInteger();
    }

    long long
    InStream::readLong()
    {
        long long result;
        mReader.readLongLong(result);

        return result;
    }

    double
    InStream::readReal()
    {
        double result;
        mReader.readNum(result);

        return result;
    }

    double
    InStream::readDouble()
    {
        return readReal();
    }

#if __cplusplus >= 201703L
}
#else
}}
#endif //__cplusplus >= 201703L