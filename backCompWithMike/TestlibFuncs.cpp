#include "TestlibFuncs.h"

namespace tl::bc
{
    void setTestCase(int testCase)
    {

    }

    void unsetTestCase()
    {

    }

    static void __testlib_fail(const std::string &message)
    {

    }

    static bool __testlib_prelimIsNaN(double r)
    {
        return false;
    }

    static std::string removeDoubleTrailingZeroes(std::string value)
    {
        return std::string();
    }

    std::string format(const char *fmt, ...)
    {
        return std::string();
    }

    std::string format(const std::string fmt, ...)
    {
        return std::string();
    }

    static std::string __testlib_part(const std::string &s)
    {
        return std::string();
    }

    static bool __testlib_isNaN(double r)
    {
        return false;
    }

    static double __testlib_nan()
    {
        return 0.;
    }

    static bool __testlib_isInfinite(double r)
    {
        return false;
    }

    inline bool doubleCompare(double expected, double result, double MAX_DOUBLE_ERROR)
    {
        return false;
    }

    inline double doubleDelta(double expected, double result)
    {
        return 0.;
    }

    void registerTestlibCmd(int argc, char *argv[])
    {
#ifdef FILE_STD_READERS
        tl::StandardReaders::input.open(argv[1]);
        tl::StandardReaders::output.open(argv[2]);
        tl::StandardReaders::ans.open(argv[3]);
#elif defined(PART_OF_FILE_STD_READERS)
        tl::StandardReaders::input.open(argv[1]);
        tl::StandardReaders::output.open(nullptr);
        tl::StandardReaders::ans.open(nullptr);
#endif
    }

    void setName(const char *format, ...)
    {

    }

    void quitf(TResult result, const char* format, ...)
    {
        switch (result)
        {
            case TResult::_ok:
                CORRECT_VER(write)(1,
                                   static_cast<const void*>("ok "),
                                   3);
                break;
            case TResult::_wa:
                CORRECT_VER(write)(1,
                                   static_cast<const void*>("wa "),
                                   3);
                break;
        }

        va_list ap;
        va_start(ap, format);
        std::vprintf(format, ap);
        va_end(ap);
    }

    inline std::string englishEnding(int x)
    {
        if (x / 10 == 1)
        {
            return "th";
        }
        else
        {
            switch (x % 10) {
                case 1:
                    return "st";
                case 2:
                    return "nd";
                case 3:
                    return "rd";
                default:
                    return "th";
            }
        }
    }

    inline std::string compress(const std::string &s)
    {
        return tl::StringTools::partOfStr(s);
    }
}
