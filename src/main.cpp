#include <iostream>

#include "../include/FileReader.h"

int main()
{
    tl::FileReader file("../test.txt");

    int num;
    std::string s;
    if (file.isOpen())
    {
        for (int i(0); i < 5; i++)
        {
            if (file.readNextInt(num))
            {
                std::cout << "Int " << num << '\n';
            }
            else
            {
                if (file.readStr(s))
                {
                    std::cout << "Str " << s << '\n';
                }
                else
                {
                    std::cout << "Doesn't exist\n";
                }
            }
        }
    }
    else
    {
        std::cout << "File Doesn't exist\n";
    }

    return 0;
}
