#ifndef TESTLIBRARY_INSTREAM_H
#define TESTLIBRARY_INSTREAM_H

#include "../include/AbstractReader.h"

#if __cplusplus >= 201703L
namespace tl::bc
#else
namespace tl { namespace bc
#endif //__cplusplus >= 201703L
{
    class InStream {
    public:
        explicit InStream(tl::AbstractReader& reader);

        bool seekEof();

        void readWordTo(std::string& result);

        void readTokenTo(std::string& result);

        void readStringTo(std::string& result);

        std::string readWord();

        std::string readToken();

        std::string readString();

        int readInteger();

        int readInt();

        long long readLong();

        double readReal();

        double readDouble();

    private:
        tl::AbstractReader &mReader;
    };
#if __cplusplus >= 201703L
}
#else
}}
#endif //__cplusplus >= 201703L

#endif //TESTLIBRARY_INSTREAM_H
