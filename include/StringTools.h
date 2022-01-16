#ifndef TESTLIBRARY_STRINGTOOLS_H
#define TESTLIBRARY_STRINGTOOLS_H

#include <cstring>

#include <string>

namespace tl
{
    class StringTools
    {
    public:
        static std::string partOfStr(std::string str);

        static char* withEnglishEnding(std::uint8_t num);

        static char* withEnglishEnding(std::uint16_t num);

        static char* withEnglishEnding(std::uint32_t num);

        static char* withEnglishEnding(std::uint64_t num);

        static char* withEnglishEnding(std::int8_t num);

        static char* withEnglishEnding(std::int16_t num);

        static char* withEnglishEnding(std::int32_t num);

        static char* withEnglishEnding(std::int64_t num);

    private:
        template<typename Int>
        static char* withEnglishEnding(Int num,
                                       const char* format,
                                       Int beginSize = 0);
    };
}

#endif //TESTLIBRARY_STRINGTOOLS_H
