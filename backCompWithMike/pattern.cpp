#include "pattern.h"

namespace tl::bc
{
    pattern::pattern(std::string s)
    {

    }

    std::string
    pattern::next(random_t& rnd) const
    {
        return std::string();
    }

    bool
    pattern::matches(const std::string& s) const
    {
        return false;
    }

    std::string
    pattern::src() const
    {
        return std::string();
    }
}
