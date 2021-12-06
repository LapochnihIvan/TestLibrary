#include "../include/Compares.h"

namespace tl
{
    bool
    Compares::doubleCmp(const double expected,
                        const double result,
                        const double maxDblErr)
    {
        return std::abs(result - expected) <= std::abs(maxDblErr) + 1E-15;
    }
}
