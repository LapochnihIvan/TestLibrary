#ifndef TESTLIBRARY_COMPARES_H
#define TESTLIBRARY_COMPARES_H

#include <cmath>

namespace tl
{
    class Compares
    {
    public:
        [[nodiscard]] static bool doubleCmp(double expected,
                                            double result,
                                            double maxDblErr);
    };
}

#endif //TESTLIBRARY_COMPARES_H
