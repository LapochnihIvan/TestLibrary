#include <iostream>
#include "../include/FileReader.h"

int main()
{
    tl::FileReader reader(
            ::CORRECT_VER(open)("../test.txt",
            CORRECT_VER(O_RDONLY)));

    std::vector<float> arr(5);
    if (reader.readNumArrSplitC(arr))
    {
        for (float& i : arr)
        {
            std::cout << i << ' ';
        }
    }

    return 0;
}
