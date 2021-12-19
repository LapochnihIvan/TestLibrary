#include "../inOneFle/TestLibrary.h"

int main()
{
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
            std::printf(
                "%s numbers differ - expected: '%ld', found: '%ld'",
                tl::StringTools::withEnglishEnding(n),
                jNum,
                pNum);
        else if (n <= 5)
        {
            if (firstNums.length() > 0) 
            {
                firstNums.push_back(' ');
            }
            firstNums += std::to_string(n);
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
                "Answer contains longer sequence [length = %d],"
                " but output contains %d elements",
                n + extraInAnsCount, n);
    }

    if (extraInOufCount > 0)
    {
        std::printf(
                "Output contains longer sequence [length = %d],"
                " but answer contains %d elements",
                n + extraInOufCount, n);
    }

    if (n <= 5)
    {
        std::printf("%d number(s): '%s'",
                    n,
                    tl::StringTools::partOfStr(firstNums).c_str());
    }

    else
    {
        std::printf("%d numbers", n);
    }
}
