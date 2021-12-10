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

    const char* StringTools::englishEnding(int num)
    {
        if (num / 10 == 1)
        {
            return "th";
        }

        switch (num % 10)
        {
            case 1:
                return "st";
            case 2:
                return "nd";
            case 3:
                return "rd";
        }

        return "th";
    }
}
