#include "../include/StandardReaders.h"

#define EPS 1.5E-6

int main(int argc, char* argv[])
{
    double ja;
    tl::StandardReaders::ans.readNum(ja);
    double pa;
    tl::StandardReaders::output.readNum(pa);

    if (std::fabs(ja - pa) > EPS + 1E-15)
    {
        std::printf("expected %.15f, found %.15f", ja, pa);
    }
    else
    {
        std::printf("answer is %.15f", ja);
    }
}
