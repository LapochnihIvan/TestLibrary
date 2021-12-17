#include <cstring>
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

    char* StringTools::withEnglishEnding(int num)
    {
        int resultSize = num / 10 + 4;
        char* result = new char[resultSize];
        result[resultSize - 1] = '\000';
        std::sprintf(result, "%d", num);

        if (num / 10 == 1)
        {
            std::strncat(result, "th", 3);
        }
        else
        {
            switch (num % 10) {
                case 1:
                    std::strncat(result, "st", 3);
                case 2:
                    std::strncat(result, "nd", 3);
                case 3:
                    std::strncat(result, "rd", 3);
                default:
                    std::strncat(result, "th", 3);
            }
        }

        return result;
    }
}
