#include <iostream>
#include <vector>

#include "../include/FileReader.h"

int main()
{
    tl::FileReader reader("../test.txt");

    int8_t num;
    if (!reader.readNextInt(num))
        return 0;

    std::cout << (int)num;

    return 0;
}
