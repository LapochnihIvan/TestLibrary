#ifndef TESTLIBRARY_TESTLIBFUNCS_H
#define TESTLIBRARY_TESTLIBFUNCS_H

#include <cstdarg>
#include <string>

#include "../include/StandardReaders.h"
#include "../include/StringTools.h"

namespace tl::bc
{
    void setTestCase(int testCase);

    void unsetTestCase();

    [[noreturn]] static void __testlib_fail(const std::string &message);

    static bool __testlib_prelimIsNaN(double r);

    static std::string removeDoubleTrailingZeroes(std::string value);

    std::string format(const char* fmt, ...);

    std::string format(const std::string fmt, ...);

    static std::string __testlib_part(const std::string& s);

    static bool __testlib_isNaN(double r);

    static double __testlib_nan();

    static bool __testlib_isInfinite(double r);

    inline bool doubleCompare(double expected, double result,
                              double MAX_DOUBLE_ERROR);

    inline double doubleDelta(double expected, double result);

    static void __testlib_set_binary(std::FILE *file);

    void prepareOpts(int argc, char* argv[]);


    void registerTestlibCmd(int argc, char *argv[]);

    void setName(const char *format, ...);

    enum TResult
    {
        _ok = 0,
        _wa = 1,
        _pe = 2,
        _fail = 3,
        _dirt = 4,
        _points = 5,
        _unexpected_eof = 8,
        _partially = 16
    };

    void quitf(TResult result, const char *format, ...);

    inline std::string englishEnding(int x);

    inline std::string compress(const std::string &s);


    template<typename T>
    static inline T __testlib_abs(const T &x)
    {
        return x > 0 ? x : -x;
    }

    template<typename T>
    static inline T __testlib_min(const T& a, const T& b)
    {
        return a < b ? a : b;
    }

    template<typename T>
    static inline T __testlib_max(const T& a, const T& b)
    {
        return a > b ? a : b;
    }

    template<typename T>
    static std::string vtos(const T &t)
    {
        return std::to_string(t);
    }
}

#endif //TESTLIBRARY_TESTLIBFUNCS_H
