#include <cmath>
#include "../include/StringTools.h"

namespace tl
{
    std::string
    StringTools::partOfStr(std::string str)
    {
        if (str.length() <= 64)
        {
            return str;
        }
        else
        {
            return str.substr(0, 30) + "..." +
                   str.substr(str.length() - 31, 31);
        }
    }

    char*
    StringTools::withEnglishEnding(std::uint8_t num)
    {
        return withEnglishEnding(num, "%u");
    }

    char*
    StringTools::withEnglishEnding(std::uint16_t num)
    {
        return withEnglishEnding(num, "%u");
    }

    char*
    StringTools::withEnglishEnding(std::uint32_t num)
    {
        return withEnglishEnding(num, "%u");
    }

    char*
    StringTools::withEnglishEnding(std::uint64_t num)
    {
#ifdef __GNUC__
        return withEnglishEnding(num, "%lu");
#elif defined(_MSC_VER)
        return withEnglishEnding(num, "%llu");
#endif
    }

    char*
    StringTools::withEnglishEnding(std::int8_t num)
    {
        return withEnglishEnding(num,
                                 "%i",
                                 num > 0 ?
                                 static_cast<int8_t>(0) :
                                 static_cast<int8_t>(1));
    }

    char*
    StringTools::withEnglishEnding(std::int16_t num)
    {
        return withEnglishEnding(num,
                                 "%i",
                                 num > 0 ?
                                 static_cast<int16_t>(0) :
                                 static_cast<int16_t>(1));
    }

    char*
    StringTools::withEnglishEnding(std::int32_t num)
    {
        return withEnglishEnding(num, "%i", num > 0 ? 0 : 1);
    }

    char*
    StringTools::withEnglishEnding(std::int64_t num)
    {
#ifdef __GNUC__
        return withEnglishEnding(num, "%li", num > 0L ? 0L : 1L);
#elif defined(_MSC_VER)
        return withEnglishEnding(num, "%lli", num > 0LL ? 0LL : 1LL);
#endif
    }

    template<typename Int>
    char*
    StringTools::withEnglishEnding(const Int num,
                                         const char* format,
                                         const Int beginSize)
    {
        Int numSize(std::log10(num) + 2);
        Int resultSize(numSize + 2 + beginSize);
        char* result = new char[resultSize];
        result[resultSize - 1] = '\000';
        std::snprintf(result, numSize, format, num);

        const char* ending;
        if (num / 10 == 1)
        {
            ending = "th";
        }
        else
        {
            switch (num % 10) {
                case 1:
                    ending = "st";
                    break;
                case 2:
                    ending = "nd";
                    break;
                case 3:
                    ending = "rd";
                    break;
                default:
                    ending = "th";
                    break;
            }
        }

        std::snprintf(result, 3, "%s", ending);

        return result;
    }
}
