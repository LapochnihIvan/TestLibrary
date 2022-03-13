#include "pattern.h"

#if __cplusplus >= 201703L
namespace tl::bc
#else
namespace tl { namespace bc
#endif //__cplusplus >= 201703L
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
#if __cplusplus >= 201703L
}
#else
}}
#endif //__cplusplus >= 201703L
