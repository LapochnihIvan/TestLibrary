#ifndef TESTLIBRARY_STRINGTOOLS_H
#define TESTLIBRARY_STRINGTOOLS_H

#include <string>

namespace tl
{
    class StringTools
    {
    public:
        static std::string partOfStr(std::string str);

        static char* englishEnding(int num);
    };
}

#endif //TESTLIBRARY_STRINGTOOLS_H
