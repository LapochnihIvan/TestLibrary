#ifndef TESTLIBRARY_PATTERN_H
#define TESTLIBRARY_PATTERN_H

#include <string>
#include <vector>

#include "random_t.h"

namespace tl::bc
{
class pattern
{
    public:
        pattern(std::string s);

        std::string next(random_t& rnd) const;

        bool matches(const std::string& s) const;

        std::string src() const;

    private:
        bool matches(const std::string& s, size_t pos) const;

        std::string s;
        std::vector<pattern> children;
        std::vector<char> chars;
        int from;
        int to;
    };
}

#endif //TESTLIBRARY_PATTERN_H
