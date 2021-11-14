#include <iostream>
#include "../include/StdinReader.h"

int main()
{
    freopen("../test.txt", "r", stdin);
    tl::StdinReader reader(true);

    std::vector<float> arr(4);
    if (reader.readNumArr(arr))
    {
        for (float& i : arr)
            std::cout << i << ' ';
    }

    return 0;
}
