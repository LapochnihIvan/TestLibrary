//#include <iostream>
//#include "../include/FileReader.h"
//
//int main()
//{
//    tl::FileReader reader(
//            ::CORRECT_VER(open)("../test.txt",
//            CORRECT_VER(O_RDONLY)));
//    std::vector<float> arr(5);
//    if (reader.readNumArrSplitC(arr))
//    {
//        for (float& i : arr)
//        {
//            std::cout << i << ' ';
//        }
//    }
//
//    return 0;
//}

//
//using namespace std;
//
//std::string c(const std::string &s) {
//    if (s.length() <= 64)
//        return s;
//    else
//        return s.substr(0, 30) + "..." + s.substr(s.length() - 31, 31);
//}

#include <unistd.h>
#include <fcntl.h>
#include <random>
#include <iostream>

int main()
{
    int n((rand()%9)+1);
    switch (n)
    {
        case 1:
            std::cout << 1;
            break;
        case 2:
            std::cout << 2;
            break;
        case 8:
            std::cout << 8;
            break;
        default:
            std::cout << "default";
    }
}
