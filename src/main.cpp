#include <iostream>

#include "../include/FileReader.h"

int main()
{
    tl::FileReader reader("../test.txt", true);

    std::vector<uint64_t> arr(5);
    reader.readNumArr(arr);

    for (auto& i : arr)
    {
        std::cout << i << ' ';
    }

    return 0;
}
