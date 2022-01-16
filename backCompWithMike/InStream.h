#ifndef TESTLIBRARY_INSTREAM_H
#define TESTLIBRARY_INSTREAM_H

#include "../include/AbstractReader.h"

namespace tl::bc {
    class InStream {
    public:
        InStream(tl::AbstractReader &reader);

        bool seekEof();

        void readWordTo(std::string &result);

        void readTokenTo(std::string &result);

        void readStringTo(std::string &result);

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
}


#endif //TESTLIBRARY_INSTREAM_H
