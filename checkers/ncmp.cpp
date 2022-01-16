#include "../inOneFile/testlib.h"

int main()
{
//    tl::StandardReaders::input.open("../input/input");
//    tl::StandardReaders::output.open(nullptr);
//    tl::StandardReaders::ans.open(nullptr);
//    tl::StandardReaders::input.open("/home/ivan/Рабочий стол/resources/working_directory/tests/3-0");
//    tl::StandardReaders::output.open("/home/ivan/Рабочий стол/resources/working_directory/outputs/3-0");
//    tl::StandardReaders::ans.open("/home/ivan/Рабочий стол/resources/working_directory/answers/3-0");

    int n = 0;
    std::string firstNums;

    while (!tl::StandardReaders::ans.isEndOfFile()
           && !tl::StandardReaders::output.isEndOfFile())
    {
        n++;
        std::int64_t jNum;
        tl::StandardReaders::ans.readInt64(jNum);
        std::int64_t pNum;
        tl::StandardReaders::output.readInt64(pNum);
        if (jNum != pNum)
        {
            std::printf(
                    "wa %s numbers differ - expected: '%ld', found: '%ld'",
                    tl::StringTools::withEnglishEnding(n),
                    jNum,
                    pNum);

            return 0;
        }
        else if (n <= 5)
        {
            if (!firstNums.empty())
            {
                firstNums.push_back(' ');
            }
            firstNums += std::to_string(pNum);
        }
    }

    int extraInAnsCount = 0;

    while (!tl::StandardReaders::ans.isEndOfFile())
    {
        std::int64_t temp;
        tl::StandardReaders::ans.readInt64(temp);
        extraInAnsCount++;
    }

    int extraInOufCount = 0;

    while (!tl::StandardReaders::output.isEndOfFile())
    {
        std::int64_t temp;
        tl::StandardReaders::output.readInt64(temp);
        extraInOufCount++;
    }

    if (extraInAnsCount > 0)
    {
        std::printf(
                "wa Answer contains longer sequence [length = %d],"
                " but output contains %d elements",
                n + extraInAnsCount, n);
    }

    else if (extraInOufCount > 0)
    {
        std::printf(
                "wa Output contains longer sequence [length = %d],"
                " but answer contains %d elements",
                n + extraInOufCount, n);
    }

    else if (n <= 5)
    {
        std::printf("ok %d number(s): '%s'",
                    n,
                    tl::StringTools::partOfStr(firstNums).c_str());
    }

    else
    {
        std::printf("ok %d numbers", n);
    }
}