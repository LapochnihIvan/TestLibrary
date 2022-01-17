#ifdef PART_OF_FILE_STD_READERS
#	define PART_OF_FILE_READER_ADD
#endif

#ifndef TESTLIBRARY_TESTLIBRARYSECURE_H
#define TESTLIBRARY_TESTLIBRARYSECURE_H

#ifdef _MSC_VER
#   define _CRT_SECURE_NO_WARNINGS

#   define __nonnull(params)
#endif

#ifdef SYSTEMKA_RUNNING
#   define NDEBUG
#endif

#include <cassert>

#ifdef NDEBUG
#   define TESTLIBRARY_ASSERT(expression, message)
#   define TESTLIBRARY_NONNULL_ASSERT(ptr)
#else
#    ifdef __GNUC__
#        define TESTLIBRARY_ASSERT(expression, message)						\
         if (!(expression))                                                 \
             __assert_fail(message, __FILE__, __LINE__, __ASSERT_FUNCTION)
#    elif _MSC_VER
#        define TESTLIBRARY_ASSERT(expression, message)						\
         if (!(expression))                                                 \
             _wassert(L ## message, __FILEW__,                              \
                     static_cast<unsigned>(__LINE__))
#   endif
#   define TESTLIBRARY_NONNULL_ASSERT(ptr)                                  \
        TESTLIBRARY_ASSERT(ptr != nullptr, #ptr " can't be null")
#endif

#endif //TESTLIBRARY_TESTLIBRARYSECURE_H

#ifndef TESTLIBRARY_ABSTRACTREADER_H
#define TESTLIBRARY_ABSTRACTREADER_H


#ifdef __GNUC__
#   include <unistd.h>

#   include <sys/stat.h>

#   define CORRECT_VER(func) func
#elif defined(_MSC_VER)
#   include <io.h>

//#   include <Windows.h>

#   define CORRECT_VER(func) _ ## func
#endif

#include <fcntl.h>

#include <cmath>
#include <cfloat>

#include <string>
#include <vector>
#include <functional>

namespace tl
{
    using hugeInt = std::string;
    using hugeIntPtr = char*;

    class AbstractReader
    {
    public:
        ~AbstractReader();

        void changeMode();

        [[nodiscard]] bool isOpen() const;

        [[nodiscard]] bool isEndOfFile() const;

        void skipWhitespaces();

        void skipChar();

        void readAllFile(char*& fileStr);

        bool readWhitespace(char& whitespace);

        bool readWhitespaces(char*& whitespaces);

        bool readWhitespaces(std::string& whitespaces);

        bool readChar(char& c);

        bool readNum(std::int8_t& num);

        bool readNum(std::uint8_t& num);

        bool readNum(std::int16_t& num);

        bool readNum(std::uint16_t& num);

        bool readNum(std::int32_t& num);

        bool readNum(std::uint32_t& num);

        bool readNum(std::int64_t& num);

        bool readNum(std::uint64_t& num);

        bool readInt8(std::int8_t& i);

        bool readUInt8(std::uint8_t& i);

        bool readInt16(std::int16_t& i);

        bool readUInt16(std::uint16_t& i);

        bool readInt32(std::int32_t& i);

        bool readUInt32(std::uint32_t& i);

        bool readInt64(std::int64_t& i);

        bool readUInt64(std::uint64_t& i);

        bool readShort(short& s);

        bool readUShort(unsigned short& s);

        bool readInt(int& i);

        bool readUInt(unsigned int& i);

        bool readLong(long& l);

        bool readULong(unsigned long& l);

        bool readLongLong(long long& ll);

        bool readULongLong(unsigned long long& ll);

        bool readHugeInt(hugeIntPtr& num);

        bool readHugeInt(hugeInt& num);

        bool readNum(float& num);

        bool readNum(double& num);

        bool readBool(bool& b);

        bool readStr(char* s,
                     std::size_t sSize) __nonnull((2));

        bool readStr(char*& emptyS) __nonnull((2));

        bool readStr(std::string& s, std::size_t sSize);

        bool readStr(std::string& s);

        bool readInt8ArrSplitC(std::int8_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUInt8ArrSplitC(std::uint8_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readInt16ArrSplitC(std::int16_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUInt16ArrSplitC(std::uint16_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readIntArrSplitC(std::int32_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUIntArrSplitC(std::uint32_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readInt64ArrSplitC(std::int64_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readUInt64ArrSplitC(std::uint64_t* arr,
                              std::size_t arrSize,
                              char delim = '\000')
            __nonnull((2));

        bool readInt8ArrSplitS(std::int8_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUInt8ArrSplitS(std::uint8_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readInt16ArrSplitS(std::int16_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUInt16ArrSplitS(std::uint16_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readIntArrSplitS(std::int32_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUIntArrSplitS(std::uint32_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readInt64ArrSplitS(std::int64_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readUInt64ArrSplitS(std::uint64_t* arr,
                              std::size_t arrSize,
                              char* delim = nullptr)
            __nonnull((2));

        bool readInt8ArrSplitC(std::vector <std::int8_t>& arr,
                              char delim = '\000');

        bool readUInt8ArrSplitC(std::vector <std::uint8_t>& arr,
                              char delim = '\000');

        bool readInt16ArrSplitC(std::vector <std::int16_t>& arr,
                              char delim = '\000');

        bool readUInt16ArrSplitC(std::vector <std::uint16_t>& arr,
                              char delim = '\000');

        bool readIntArrSplitC(std::vector <std::int32_t>& arr,
                              char delim = '\000');

        bool readUIntArrSplitC(std::vector <std::uint32_t>& arr,
                              char delim = '\000');

        bool readInt64ArrSplitC(std::vector <std::int64_t>& arr,
                              char delim = '\000');

        bool readUInt64ArrSplitC(std::vector <std::uint64_t>& arr,
                              char delim = '\000');

        bool readFltArrSplitC(std::vector<float>& arr,
                              char delim = '\000');

        bool readDblArrSplitC(std::vector<double>& arr,
                              char delim = '\000');

        bool readInt8ArrSplitS(std::vector <std::int8_t>& arr,
                              char* delim = nullptr);

        bool readUInt8ArrSplitS(std::vector <std::uint8_t>& arr,
                              char* delim = nullptr);

        bool readInt16ArrSplitS(std::vector <std::int16_t>& arr,
                              char* delim = nullptr);

        bool readUInt16ArrSplitS(std::vector <std::uint16_t>& arr,
                              char* delim = nullptr);

        bool readIntArrSplitS(std::vector <std::int32_t>& arr,
                              char* delim = nullptr);

        bool readUIntArrSplitS(std::vector <std::uint32_t>& arr,
                              char* delim = nullptr);

        bool readInt64ArrSplitS(std::vector <std::int64_t>& arr,
                              char* delim = nullptr);

        bool readUInt64ArrSplitS(std::vector <std::uint64_t>& arr,
                              char* delim = nullptr);

        bool readFltArrSplitS(std::vector<float>& arr,
                              char* delim = nullptr);

        bool readDblArrSplitS(std::vector<double>& arr,
                              char* delim = nullptr);

    protected:
        char* mData;
        char* mBegin;

        explicit AbstractReader(bool ignoreWhitespaces = false);

    private:
        bool mIgnoreWhitespaces;

        [[nodiscard]] inline bool isNotWhitespace() const;

        [[nodiscard]] inline bool isWhitespace() const;

        [[nodiscard]] inline bool isNotDigit();

        template<typename Num>
        [[nodiscard]] inline bool isNotInRange(const Num& num,
                                               const Num& nextNum,
                                               const Num& limit);

        [[nodiscard]] inline bool readAbstractStr(char*& s,
                                                  bool (AbstractReader::*continueCond)() const,
                                                  const std::function<bool()>& exitCond = [](){
                                                      return false;
                                                  });

        [[nodiscard]] inline bool readAbstractStr(std::string& s,
                                                  bool (AbstractReader::*continueCond)() const,
                                                  const std::function<bool()>& exitCond = [](){
                                                      return false;
                                                  });

        template<typename Int>
        [[nodiscard]] inline bool readAbstractInt(Int& num, Int limit);

        template<typename Int>
        [[nodiscard]] inline bool readAbstractSignedInt(Int& num,
                                                        Int maxSize,
                                                        Int minSize);

        template<typename Real>
        [[nodiscard]] inline bool readAbstractReal(Real& num,
                                                   Real maxSize,
                                                   Real minSize);

        template<typename Num>
        [[nodiscard]] inline bool readAbstractNumArr(Num* arr,
                                                     std::size_t arrSize,
                                                     char delim)
            __nonnull((2));

        template<typename Num>
        [[nodiscard]] inline bool readAbstractNumArr(Num* arr,
                                                     std::size_t arrSize,
                                                     char* delim)
            __nonnull((2));

        template<typename iterableArrT>
        [[nodiscard]] inline bool readAbstractNumArr(iterableArrT& arr,
                                                     char delim);

        template<typename iterableArrT>
        [[nodiscard]] inline bool readAbstractNumArr(iterableArrT& arr,
                                                     char* delim);
    };
}

#endif //TESTLIBRARY_ABSTRACTREADER_H

#ifndef TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H
#define TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H

namespace tl
{
    class AbstractPartOfFileReader : public AbstractReader
    {
    protected:
        explicit AbstractPartOfFileReader(bool ignoreWhitespaces = false);

        explicit AbstractPartOfFileReader(int fd,
                                          bool ignoreWhitespaces = false);

        void openPart(int fd);
    };
}

#endif //TESTLIBRARY_ABSTRACTPARTOFFILEREADER_H

#ifndef TESTLIBRARY_ABSTRACTFILEREADER_H
#define TESTLIBRARY_ABSTRACTFILEREADER_H


namespace tl
{
    class AbstractFileReader : public AbstractReader
    {
    public:
        void open(int fd);

    protected:
        explicit AbstractFileReader(int fd, bool ignoreWhitespaces = false);

        explicit AbstractFileReader(bool ignoreWhitespaces);
    };
}

#endif //TESTLIBRARY_ABSTRACTFILEREADER_H

#ifndef TESTLIBRARY_PARTOFSTDINREADER_H
#define TESTLIBRARY_PARTOFSTDINREADER_H


namespace tl
{
    class PartOfStdinReader : public AbstractPartOfFileReader
    {
    public:
        explicit PartOfStdinReader(bool ignoreWhitespaces = false);
    };
}

#endif //TESTLIBRARY_PARTOFSTDINREADER_H

#ifdef PART_OF_FILE_READER_ADD
#ifndef TESTLIBRARY_PARTOFFILEREADER_H
#define TESTLIBRARY_PARTOFFILEREADER_H


namespace tl
{
    class PartOfFileReader : public AbstractPartOfFileReader
    {
    public:
        explicit PartOfFileReader(bool ignoreWhitespaces = false);

        explicit PartOfFileReader(int fd,
                                  bool ignoreWhitespaces = false);

        explicit PartOfFileReader(FILE*& file,
                                  bool ignoreWhitespaces = false);

        explicit PartOfFileReader(const char* path,
                                  bool ignoreWhitespaces = false);

        explicit PartOfFileReader(const std::string& path,
                                  bool ignoreWhitespaces = false);

        void open(int fd);

        void open(FILE*& file);

        void open(const char* path);

        void open(const std::string& path);

    private:
        static int mFd;
    };
}

#endif //TESTLIBRARY_PARTOFFILEREADER_H
#endif

#ifndef TESTLIBRARY_STDINREADER_H
#define TESTLIBRARY_STDINREADER_H


namespace tl
{
    class StdinReader : public AbstractFileReader
    {
    public:
        explicit StdinReader(bool ignoreWhitespaces = false);

    private:
        using AbstractFileReader::open;
    };
}

#endif //TESTLIBRARY_STDINREADER_H

#ifndef TESTLIBRARY_FILEREADER_H
#define TESTLIBRARY_FILEREADER_H


namespace tl
{
    class FileReader : public AbstractFileReader
    {
    public:
        explicit FileReader(bool ignoreWhitespaces = false);
        explicit FileReader(int fd, bool ignoreWhitespaces = false);

        explicit FileReader(FILE*& file, bool ignoreWhitespaces = false);

        explicit FileReader(const char* path,
                            bool ignoreWhitespaces = false) __nonnull((2));

        explicit FileReader(const std::string& path, bool ignoreWhitespaces = false);

        void open(FILE*& file);

        void open(const char* path) __nonnull((2));

        void open(const std::string& path);
    };
}

#endif //TESTLIBRARY_FILEREADER_H

#ifndef TESTLIBRARY_STANDARDREADERS_H
#define TESTLIBRARY_STANDARDREADERS_H

#ifdef PART_OF_FILE_STD_READERS
#elif defined(FILE_STD_READERS)
#else
#endif

namespace tl
{
    struct StandardReaders
    {
#ifdef PART_OF_FILE_STD_READERS
        static PartOfFileReader input;
        static PartOfFileReader output;
        static PartOfFileReader ans;
#elif defined(FILE_STD_READERS)
        static FileReader input;
        static FileReader output;
        static FileReader ans;
#else
        static PartOfStdinReader input;
        static PartOfStdinReader output;
        static PartOfStdinReader ans;
#endif
    };
}

#endif //TESTLIBRARY_STANDARDREADERS_H

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

#ifndef TESTLIBRARY_STRINGTOOLS_H
#define TESTLIBRARY_STRINGTOOLS_H

#include <cstring>

#include <string>

namespace tl
{
    class StringTools
    {
    public:
        static std::string partOfStr(std::string str);

        static char* withEnglishEnding(std::uint8_t num);

        static char* withEnglishEnding(std::uint16_t num);

        static char* withEnglishEnding(std::uint32_t num);

        static char* withEnglishEnding(std::uint64_t num);

        static char* withEnglishEnding(std::int8_t num);

        static char* withEnglishEnding(std::int16_t num);

        static char* withEnglishEnding(std::int32_t num);

        static char* withEnglishEnding(std::int64_t num);

    private:
        template<typename Int>
        static char* withEnglishEnding(Int num,
                                       const char* format,
                                       Int beginSize = 0);
    };
}

#endif //TESTLIBRARY_STRINGTOOLS_H

#ifndef WITHOUT_BACK_COMP
#ifndef TESTLIBRARY_INSTREAM_H
#define TESTLIBRARY_INSTREAM_H


namespace tl::bc {
    class InStream {
    public:
        InStream(tl::AbstractReader &reader);

        bool seekEof();

        void readWordTo(std::string &result);

        void readTokenTo(std::string &result);

        void readStringTo(std::string &result);

        std::string readWord();

        std::string readToken();

        std::string readString();

        int readInteger();

        int readInt();

        long long readLong();

        double readReal();

        double readDouble();

    private:
        tl::AbstractReader &mReader;
    };
}


#endif //TESTLIBRARY_INSTREAM_H

#ifndef TESTLIBRARY_TESTLIBGLOBALS_H
#define TESTLIBRARY_TESTLIBGLOBALS_H


namespace tl::bc
{
    InStream inf(tl::StandardReaders::input);

    InStream ouf(tl::StandardReaders::output);

    InStream ans(tl::StandardReaders::ans);
}

#endif //TESTLIBRARY_TESTLIBGLOBALS_H

#ifndef TESTLIBRARY_TESTLIBFUNCS_H
#define TESTLIBRARY_TESTLIBFUNCS_H

#include <cstdarg>
#include <string>


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

#ifndef TESTLIBRARY_RANDOM_T_H
#define TESTLIBRARY_RANDOM_T_H

class pattern;

namespace tl::bc
{
    class random_t {
    public:
    };
}

#endif //TESTLIBRARY_RANDOM_T_H

#ifndef TESTLIBRARY_PATTERN_H
#define TESTLIBRARY_PATTERN_H

#include <string>
#include <vector>


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

#endif

namespace tl
{
    void AbstractReader::changeMode()
    {
        mIgnoreWhitespaces = !mIgnoreWhitespaces;
    }

    AbstractReader::~AbstractReader()
    {
        delete[] mBegin;
    }

    bool
    AbstractReader::isOpen() const
    {
        return mData != nullptr;
    }

    bool
    AbstractReader::isEndOfFile() const
    {
        return *mData == '\000';
    }

    void
    AbstractReader::skipWhitespaces()
    {
        while (isWhitespace() && !isEndOfFile())
        {
            mData++;
        }
    }

    void
    AbstractReader::skipChar()
    {
        if (!isEndOfFile())
        {
            mData++;
        }
    }

    void
    AbstractReader::readAllFile(char*& fileStr)
    {
        fileStr = mBegin;
    }

    bool
    AbstractReader::readWhitespace(char& whitespace)
    {
        if (isNotWhitespace())
        {
            return false;
        }

        return readChar(whitespace);
    }

    bool
    AbstractReader::readWhitespaces(char*& whitespaces)
    {
        return readAbstractStr(whitespaces, &AbstractReader::isWhitespace);
    }

    bool
    AbstractReader::readWhitespaces(std::string& whitespaces)
    {
        return readAbstractStr(whitespaces, &AbstractReader::isWhitespace);
    }

    bool
    AbstractReader::readChar(char& c)
    {
        if (isEndOfFile())
        {
            return false;
        }

        c = *mData++;

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readNum(std::int8_t& num)
    {
        return readAbstractSignedInt(num,
                                     static_cast<std::int8_t>(INT8_MAX),
                                     static_cast<std::int8_t>(INT8_MIN));
    }

    bool
    AbstractReader::readNum(std::uint8_t& num)
    {
        return readAbstractInt(num,
                               static_cast<std::uint8_t>(UINT8_MAX));
    }

    bool
    AbstractReader::readNum(std::int16_t& num)
    {
        return readAbstractSignedInt(num,
                                     static_cast<std::int16_t>(INT16_MAX),
                                     static_cast<std::int16_t>(INT16_MIN));
    }

    bool
    AbstractReader::readNum(std::uint16_t& num)
    {
        return readAbstractInt(num,
                               static_cast<std::uint16_t>(UINT16_MAX));
    }

    bool
    AbstractReader::readNum(std::int32_t &num)
    {
        return readAbstractSignedInt(num, INT32_MAX, INT32_MAX);
    }

    bool
    AbstractReader::readNum(std::uint32_t& num)
    {
        return readAbstractInt(num, UINT32_MAX);
    }

    bool
    AbstractReader::readNum(std::int64_t& num)
    {
        return readAbstractSignedInt(num, INT64_MAX, INT64_MIN);
    }

    bool
    AbstractReader::readNum(std::uint64_t& num)
    {
        return readAbstractInt(num, UINT64_MAX);
    }

    bool
    AbstractReader::readInt8(std::int8_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt8(std::uint8_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readInt16(std::int16_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt16(std::uint16_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readInt32(std::int32_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt32(std::uint32_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readInt64(std::int64_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt64(std::uint64_t& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readShort(short& s)
    {
        return readNum(s);
    }

    bool
    AbstractReader::readUShort(unsigned short& s)
    {
        return readNum(s);
    }

    bool
    AbstractReader::readInt(int& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readUInt(unsigned int& i)
    {
        return readNum(i);
    }

    bool
    AbstractReader::readLong(long& l)
    {
#ifdef __GNUC__
        return readNum(l);
#elif defined(_MSC_VER)
        return readAbstractSignedInt(l,
            static_cast<long>(INT32_MAX),
            static_cast<long>(INT32_MIN));
#endif
    }

    bool
    AbstractReader::readULong(unsigned long& l)
    {
#ifdef __GNUC__
        return readNum(l);
#elif defined(_MSC_VER)
        return readAbstractInt(l,
            static_cast<unsigned long>(UINT32_MAX));
#endif
    }

    bool
    AbstractReader::readLongLong(long long& ll)
    {
#ifdef __GNUC__
        return readAbstractSignedInt(ll,
            static_cast<long long>(INT64_MAX),
            static_cast<long long>(INT64_MIN));
#elif defined(_MSC_VER)
        return readNum(ll);
#endif
    }

    bool
    AbstractReader::readULongLong(unsigned long long& ll)
    {
#ifdef __GNUC__
        return readAbstractInt(ll,
            static_cast<unsigned long long>(UINT64_MAX));
#elif defined(_MSC_VER)
        return readNum(ll);
#endif
    }

    bool
    AbstractReader::readHugeInt(hugeIntPtr& num)
    {
        return readAbstractStr(num, &AbstractReader::isNotWhitespace,
                               [this]()
                                {
                                    return isNotDigit();
                                });
    }

    bool
    AbstractReader::readHugeInt(hugeInt& num)
    {
        return readAbstractStr(num, &AbstractReader::isNotWhitespace,
                               [this]()
                               {
                                   return isNotDigit();
                               });
    }

    bool
    AbstractReader::readNum(float& num)
    {
        return readAbstractReal(num, FLT_MAX, FLT_MIN);
    }

    bool
    AbstractReader::readNum(double& num)
    {
        return readAbstractReal(num, DBL_MAX, DBL_MIN);
    }

    bool
    AbstractReader::readBool(bool& b)
    {
        if (isEndOfFile() || (*mData != '0' && *mData != '1'))
        {
            return false;
        }

        b = static_cast<bool>(*mData++ - '0');

        if (isNotWhitespace())
        {
            mData--;

            return false;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readStr(char* s, const std::size_t sSize)
    {
        TESTLIBRARY_NONNULL_ASSERT(s);

        if (isEndOfFile())
        {
            return false;
        }

        for (std::size_t pos(UINT64_C(0));
             pos < sSize; pos++)
        {
            if (!readChar(s[pos]))
            {
                return false;
            }
        }

        return true;
    }

    bool
    AbstractReader::readStr(char*& emptyS)
    {
        return readAbstractStr(emptyS, &AbstractReader::isNotWhitespace);
    }

    bool
    AbstractReader::readStr(std::string& s, const std::size_t sSize)
    {
        if (isEndOfFile())
        {
            return false;
        }

        s.resize(sSize);

        char* begin = mData;
        for (char& sym : s)
        {
            if (mIgnoreWhitespaces)
            {
                skipWhitespaces();
            }

            if (!readChar(sym))
            {
                mData = begin;

                return false;
            }
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readStr(std::string& s)
    {
        return readAbstractStr(s, &AbstractReader::isNotWhitespace);
    }

    bool
    AbstractReader::readInt8ArrSplitC(std::int8_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitC(std::uint8_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitC(std::int16_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitC(std::uint16_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readIntArrSplitC(std::int32_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUIntArrSplitC(std::uint32_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt64ArrSplitC(std::int64_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitC(std::uint64_t* arr,
                                     std::size_t arrSize,
                                     char delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt8ArrSplitS(std::int8_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitS(std::uint8_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitS(std::int16_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitS(std::uint16_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readIntArrSplitS(std::int32_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUIntArrSplitS(std::uint32_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt64ArrSplitS(std::int64_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitS(std::uint64_t* arr,
                                     std::size_t arrSize,
                                     char* delim)
    {
        return readAbstractNumArr(arr, arrSize, delim);
    }

    bool
    AbstractReader::readInt8ArrSplitC(std::vector <std::int8_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitC(std::vector <std::uint8_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitC(std::vector <std::int16_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitC(std::vector <std::uint16_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readIntArrSplitC(std::vector <std::int32_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUIntArrSplitC(std::vector <std::uint32_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }
    bool
    AbstractReader::readInt64ArrSplitC(std::vector <std::int64_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitC(std::vector <std::uint64_t>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readFltArrSplitC(std::vector<float>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readDblArrSplitC(std::vector<double>& arr,
                                     char delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt8ArrSplitS(std::vector<std::int8_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt8ArrSplitS(std::vector<std::uint8_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt16ArrSplitS(std::vector<std::int16_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt16ArrSplitS(std::vector<std::uint16_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readIntArrSplitS(std::vector<std::int32_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUIntArrSplitS(std::vector<std::uint32_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readInt64ArrSplitS(std::vector<std::int64_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readUInt64ArrSplitS(std::vector<std::uint64_t>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readFltArrSplitS(std::vector<float>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    bool
    AbstractReader::readDblArrSplitS(std::vector<double>& arr,
                                     char* delim)
    {
        return readAbstractNumArr(arr, delim);
    }

    AbstractReader::AbstractReader(const bool ignoreWhitespaces) :
            mIgnoreWhitespaces(ignoreWhitespaces),
            mData(nullptr),
            mBegin(nullptr)
    {

    }

    bool
    AbstractReader::isNotWhitespace() const
    {
        return *mData != ' ' && *mData != '\n' && *mData != '\r';
    }

    bool
    AbstractReader::isWhitespace() const
    {
        return !isNotWhitespace();
    }

    bool
    AbstractReader::isNotDigit()
    {
        return *mData < '0' || *mData > '9';
    }

    template<typename Num>
    bool
    AbstractReader::isNotInRange(const Num& num,
                                  const Num& nextNum,
                                  const Num& limit)
    {
        return ((limit - nextNum) / 10) < num;
    }

#define BUFF_SIZE UINT64_C(256)

    bool
    AbstractReader::readAbstractStr(char*& s,
                                    bool (AbstractReader::*continueCond)() const,
                                    const std::function<bool()>& exitCond)
    {
        if (isEndOfFile() || !(this->*continueCond)())
        {
            s = nullptr;

            return false;
        }

        s = new char [BUFF_SIZE];

        std::size_t pos = 0;
        while ((this->*continueCond)() && !isEndOfFile())
        {
            if (exitCond())
            {
                s = static_cast<char*>(
                        realloc(static_cast<void*>(s),
                                pos + UINT64_C(1)));
                s[pos] = '\000';

                return false;
            }

            s[pos++] = *mData++;
            if (pos % BUFF_SIZE == UINT64_C(0))
            {
                s = static_cast<char*>(
                        realloc(static_cast<void*>(s),
                                pos + BUFF_SIZE));
            }
        }

        s = static_cast<char*>(
                realloc(static_cast<void*>(s),
                        pos + UINT64_C(1)));
        s[pos] = '\000';

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    bool
    AbstractReader::readAbstractStr(std::string& s,
                                    bool (AbstractReader::*continueCond)() const,
                                    const std::function<bool()>& exitCond)
    {
        s.clear();

        if (isEndOfFile())
        {
            return false;
        }

        while ((this->*continueCond)() && !isEndOfFile())
        {
            if (exitCond())
            {
                return false;
            }

            s.push_back(*mData++);
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    template<typename Int>
    bool
    AbstractReader::readAbstractInt(Int& num, const Int limit)
    {
        if (isEndOfFile())
        {
            return false;
        }

        num = 0;

        char* begin(mData);
        Int nexNum;
        while (isNotWhitespace() && !isEndOfFile())
        {
            nexNum = *mData - '0';
            if (isNotDigit() || isNotInRange(num, nexNum, limit))
            {
                mData = begin;

                return false;
            }
            num = num * 10 + nexNum;

            mData++;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    template<typename Int>
    bool
    AbstractReader:: readAbstractSignedInt(Int& num, const Int maxSize, const Int minSize)
    {
        bool minus = false;
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        if (!readAbstractInt(num, minus ? minSize : maxSize))
        {
            return false;
        }

        if (minus)
        {
            num *= -1;
        }

        return true;
    }

    template<typename Real>
    bool
    AbstractReader::readAbstractReal(Real& num, const Real maxSize, const Real minSize)
    {
        if (isEndOfFile())
        {
            return false;
        }

        bool minus = false;
        if (*mData == '-')
        {
            minus = true;
            mData++;
        }

        double limit = minus ? minSize : maxSize;

        num = 0.F;

        char* begin(mData);
        Real nexNum;
        while (*mData != '.' && isNotWhitespace()
               && !isEndOfFile())
        {
            nexNum = static_cast<Real>(*mData - '0');
            if (isNotDigit()
                || ((limit - nexNum) / 10) < num)
            {
                mData = begin;

                return false;
            }
            num = num * 10.F + nexNum;

            mData++;
        }

        if (isNotWhitespace() && !isEndOfFile())
        {
            if (*mData++ != '.')
            {
                mData = begin;

                return false;
            }

            Real afterPoint = 0.F;
            Real countDigit = 0.F;

            while (isNotWhitespace() && !isEndOfFile())
            {
                nexNum = static_cast<Real>(*mData - '0');
                if (isNotDigit())
                {
                    mData = begin;

                    return false;
                }
                afterPoint = afterPoint * 10.F + nexNum;
                countDigit++;

                mData++;
            }

            afterPoint /= std::pow(10.F, countDigit);

            if (((limit - afterPoint) / 10) < num)
            {
                mData = begin;

                return false;
            }

            num += afterPoint;
        }

        if (minus)
        {
            num *= -1.F;
        }

        if (mIgnoreWhitespaces)
        {
            skipWhitespaces();
        }

        return true;
    }

    template<typename Num>
    bool
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize,
                                       char delim)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

        char* begin = mData;

        for (std::size_t numElem(UINT64_C(0));
             numElem < arrSize; numElem++)
        {
            if (!readNum(arr[numElem]))
            {
                mData = begin;

                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == '\000')
                {
                    readWhitespace(delim);
                }
                else if (delim != *mData++ || isWhitespace())
                {
                    mData = begin;

                    return false;
                }
            }
        }

        return true;
    }

    template<typename Num>
    bool
    AbstractReader::readAbstractNumArr(Num* arr, const std::size_t arrSize,
                                       char* delim)
    {
        TESTLIBRARY_NONNULL_ASSERT(arr);

        char* begin = mData;

        for (std::size_t numElem(UINT64_C(0));
             numElem < arrSize; numElem++)
        {
            if (!readNum(arr[numElem]))
            {
                mData = begin;

                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == nullptr)
                {
                    readWhitespaces(delim);
                }
                else
                {
                    for (std::size_t numDigitSym(UINT64_C(0));
                         delim[numDigitSym] != '\000';
                         numDigitSym++)
                    {
                        if (delim[numDigitSym] != *mData++)
                        {
                            mData = begin;

                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }

    template<typename iterableArrT>
    bool
    AbstractReader::readAbstractNumArr(iterableArrT& arr, char delim)
    {
        char* begin = mData;

        for (auto& elem : arr)
        {
            if (!readNum(elem))
            {
                mData = begin;

                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == '\000')
                {
                    readWhitespace(delim);
                }
                else if (delim != *mData++ || isWhitespace())
                {
                    mData = begin;

                    return false;
                }
            }
        }

        return true;
    }

    template<typename iterableArrT>
    bool
    AbstractReader::readAbstractNumArr(iterableArrT& arr, char* delim)
    {
        char* begin = mData;

        for (auto& elem : arr)
        {
            if (!readNum(elem))
            {
                return false;
            }

            if (!mIgnoreWhitespaces && !isEndOfFile())
            {
                if (delim == nullptr)
                {
                    readWhitespaces(delim);
                }
                else
                {
                    for (std::size_t numDigitSym(UINT64_C(0));
                         delim[numDigitSym] != '\000';
                         numDigitSym++)
                    {
                        if (delim[numDigitSym] != *mData++)
                        {
                            mData = begin;

                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}

namespace tl
{
    AbstractPartOfFileReader::AbstractPartOfFileReader(const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {

    }

    AbstractPartOfFileReader::AbstractPartOfFileReader(const int fd,
                                                       const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        openPart(fd);
    }

    void
    AbstractPartOfFileReader::openPart(const int fd)
    {
        TESTLIBRARY_ASSERT(fd != -1, "file doesn't exist");
        TESTLIBRARY_ASSERT(fd != 1,
                           "PartOfFileReader doesn't work with stdout");
        TESTLIBRARY_ASSERT(fd != 2,
                           "PartOfFileReader doesn't work with stderr");

        std::size_t sizeOfPart;

#ifdef __GNUC__
        ::CORRECT_VER(read)(fd, static_cast<void*>(&sizeOfPart), 8);
#elif defined(_MSC_VER)
        ::CORRECT_VER(read)(fd, static_cast<void*>(&sizeOfPart), 4);

        std::size_t lastFourBites;
        ::CORRECT_VER(read)(fd, static_cast<void*>(&lastFourBites), 4);
        TESTLIBRARY_ASSERT(lastFourBites == 0, "You can't read so long file in Windows");
#endif

        mData = new char[sizeOfPart + 1];
        mData[sizeOfPart] = '\000';
        ::CORRECT_VER(read)(fd, static_cast<void*>(mData), sizeOfPart);

        mBegin = mData;
    }
}


namespace tl
{
    AbstractFileReader::AbstractFileReader(bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {

    }

    AbstractFileReader::AbstractFileReader(const int fd,
                                           const bool ignoreWhitespaces) :
            AbstractReader(ignoreWhitespaces)
    {
        open(fd);
    }

    void
    AbstractFileReader::open(const int fd)
    {
        TESTLIBRARY_ASSERT(fd != -1, "file doesn't exist");
        TESTLIBRARY_ASSERT(fd != 1,
                           "FileReader doesn't work with stdout");
        TESTLIBRARY_ASSERT(fd != 2,
                           "FileReader doesn't work with stderr");

#ifdef __GNUC__
        struct ::stat file{};
        ::fstat(fd, &file);
        const ::off_t fSize(file.st_size);
//#elif _MSC_VER
//      HANDLE hF = CreateFileA("F:\\TestLib\\TestLib\\test.exe", 0x00, 0x00, NULL,
//            OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//      const DWORD fSize(GetFileSize(hF, NULL));
#else
        const long fSize(::CORRECT_VER(lseek)(fd, 0L, SEEK_END));
        ::CORRECT_VER(lseek)(fd, 0L, SEEK_SET);
#endif

        mData = new char[fSize + 1];
        mData[fSize] = '\000';

        ::CORRECT_VER(read)(fd, static_cast<void*>(mData), fSize);
        ::CORRECT_VER(close)(fd);
        mBegin = mData;
    }
}


namespace tl
{
    PartOfStdinReader::PartOfStdinReader(const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(0, ignoreWhitespaces)
    {

    }
}

#ifdef PART_OF_FILE_READER_ADD

namespace tl
{
    int PartOfFileReader::mFd = -1;

    PartOfFileReader::PartOfFileReader(const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(ignoreWhitespaces)
    {

    }

    PartOfFileReader::PartOfFileReader(const int fd,
                                       const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(ignoreWhitespaces)
    {
        TESTLIBRARY_ASSERT(fd != 0,
                           "PartOfFileReader doesn't work with stdin");

        open(fd);
    }

    PartOfFileReader::PartOfFileReader(FILE*& file,
                                       const bool ignoreWhitespaces)
    {

    }

    PartOfFileReader::PartOfFileReader(const char* path,
                                       const bool ignoreWhitespaces) :
            AbstractPartOfFileReader(ignoreWhitespaces)
    {

        open(path);
    }

    PartOfFileReader::PartOfFileReader(const std::string& path,
                                       const bool ignoreWhitespaces) :
            PartOfFileReader(ignoreWhitespaces)
    {
        open(path);
    }

    void
    PartOfFileReader::open(const int fd)
    {
        PartOfFileReader::mFd = fd;

        openPart(fd);
    }

    void
    PartOfFileReader::open(FILE*& file)
    {
        TESTLIBRARY_NONNULL_ASSERT(file);

        open(::CORRECT_VER(fileno)(file));
    }

    void
    PartOfFileReader::open(const char* path)
    {
        if (path == nullptr)
        {
            open(mFd);
        }
        else
        {
            int fd(::CORRECT_VER(open)(path,
                                       CORRECT_VER(O_RDONLY)));
            PartOfFileReader::mFd = fd;

            open(fd);
        }
    }

    void
    PartOfFileReader::open(const std::string& path)
    {
        TESTLIBRARY_ASSERT(!path.empty(), "path is empty");

        open(path.c_str());
    }
}
#endif


tl::StdinReader::StdinReader(const bool ignoreWhitespaces) :
        AbstractFileReader(0, ignoreWhitespaces)
{

}


namespace tl {
    FileReader::FileReader(const bool ignoreWhitespaces) :
            AbstractFileReader(ignoreWhitespaces)
    {

    }

    FileReader::FileReader(const int fd, const bool ignoreWhitespaces) :
            AbstractFileReader(ignoreWhitespaces)
    {
        TESTLIBRARY_ASSERT(fd != 0,
                           "FileReader doesn't work with stdin");

        AbstractFileReader::open(fd);
    }

    FileReader::FileReader(FILE*& file, const bool ignoreWhitespaces) :
            AbstractFileReader(ignoreWhitespaces)
    {
        open(file);
    }

    FileReader::FileReader(const char *path,
                           const bool ignoreWhitespaces) :
            AbstractFileReader(ignoreWhitespaces)
    {
        open(path);
    }

    FileReader::FileReader(const std::string &path,
                           const bool ignoreWhitespaces) :
            FileReader(path.c_str(), ignoreWhitespaces)
    {
        open(path);
    }

    void
    FileReader::open(FILE*& file)
    {
        TESTLIBRARY_NONNULL_ASSERT(file);

        AbstractFileReader::open(::CORRECT_VER(fileno)(file));
    }

    void
    FileReader::open(const char* path)
    {
        TESTLIBRARY_NONNULL_ASSERT(path);

        AbstractFileReader::open(::CORRECT_VER(open)(path,
                             CORRECT_VER(O_RDONLY)));
    }

    void
    FileReader::open(const std::string& path)
    {
        TESTLIBRARY_ASSERT(!path.empty(), "path is empty");

        open(path.c_str());
    }
}


namespace tl
{
#ifdef PART_OF_FILE_STD_READERS
    PartOfFileReader StandardReaders::input(true);
    PartOfFileReader StandardReaders::output(true);
    PartOfFileReader StandardReaders::ans(true);
#elif defined(FILE_STD_READERS)
    FileReader StandardReaders::input(true);
    FileReader StandardReaders::output(true);
    FileReader StandardReaders::ans(true);
#else
    PartOfStdinReader StandardReaders::input(true);
    PartOfStdinReader StandardReaders::output(true);
    PartOfStdinReader StandardReaders::ans(true);
#endif
}


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

#include <cmath>

namespace tl
{
    std::string
    StringTools::partOfStr(std::string str)
    {
        if (str.length() <= 64)
        {
            return str;
        }
        else
        {
            return str.substr(0, 30) + "..." +
                   str.substr(str.length() - 31, 31);
        }
    }

    char*
    StringTools::withEnglishEnding(std::uint8_t num)
    {
        return withEnglishEnding(num, "%u");
    }

    char*
    StringTools::withEnglishEnding(std::uint16_t num)
    {
        return withEnglishEnding(num, "%u");
    }

    char*
    StringTools::withEnglishEnding(std::uint32_t num)
    {
        return withEnglishEnding(num, "%u");
    }

    char*
    StringTools::withEnglishEnding(std::uint64_t num)
    {
#ifdef __GNUC__
        return withEnglishEnding(num, "%lu");
#elif defined(_MSC_VER)
        return withEnglishEnding(num, "%llu");
#endif
    }

    char*
    StringTools::withEnglishEnding(std::int8_t num)
    {
        return withEnglishEnding(num,
                                 "%i",
                                 num > 0 ?
                                 static_cast<int8_t>(0) :
                                 static_cast<int8_t>(1));
    }

    char*
    StringTools::withEnglishEnding(std::int16_t num)
    {
        return withEnglishEnding(num,
                                 "%i",
                                 num > 0 ?
                                 static_cast<int16_t>(0) :
                                 static_cast<int16_t>(1));
    }

    char*
    StringTools::withEnglishEnding(std::int32_t num)
    {
        return withEnglishEnding(num, "%i", num > 0 ? 0 : 1);
    }

    char*
    StringTools::withEnglishEnding(std::int64_t num)
    {
#ifdef __GNUC__
        return withEnglishEnding(num, "%li", num > 0L ? 0L : 1L);
#elif defined(_MSC_VER)
        return withEnglishEnding(num, "%lli", num > 0LL ? 0LL : 1LL);
#endif
    }

    template<typename Int>
    char*
    StringTools::withEnglishEnding(const Int num,
                                         const char* format,
                                         const Int beginSize)
    {
        Int numSize(std::log10(num) + 2);
        Int resultSize(numSize + 2 + beginSize);
        char* result = new char[resultSize];
        result[resultSize - 1] = '\000';
        std::snprintf(result, numSize, format, num);

        const char* ending;
        if (num / 10 == 1)
        {
            ending = "th";
        }
        else
        {
            switch (num % 10) {
                case 1:
                    ending = "st";
                    break;
                case 2:
                    ending = "nd";
                    break;
                case 3:
                    ending = "rd";
                    break;
                default:
                    ending = "th";
                    break;
            }
        }

        std::snprintf(result, 3, "%s", ending);

        return result;
    }
}

#ifndef WITHOUT_BACK_COMP

namespace tl::bc
{
    InStream::InStream(tl::AbstractReader& reader) :
            mReader(reader)
    {

    }

    bool
    InStream::seekEof()
    {
        return mReader.isEndOfFile();
    }

    void
    InStream::readWordTo(std::string& result)
    {
        mReader.readStr(result);
    }

    void
    InStream::readTokenTo(std::string& result)
    {
        mReader.readStr(result);
    }

    void
    InStream::readStringTo(std::string& result)
    {
        mReader.readStr(result);
    }

    std::string
    InStream::readWord()
    {
        std::string result;
        mReader.readStr(result);

        return result;
    }

    std::string
    InStream::readToken()
    {
        return readWord();
    }

    std::string
    InStream::readString()
    {
        return readWord();
    }

    int
    InStream::readInteger()
    {
        int result;
        mReader.readNum(result);

        return result;
    }

    int
    InStream::readInt()
    {
        return readInteger();
    }

    long long
    InStream::readLong()
    {
        long long result;
        mReader.readLongLong(result);

        return result;
    }

    double
    InStream::readReal()
    {
        double result;
        mReader.readNum(result);

        return result;
    }

    double
    InStream::readDouble()
    {
        return readReal();
    }
}


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
        static char buff[16777216];

        std::va_list ap;
        va_start(ap, fmt);
        std::vsnprintf(buff, 16777216, fmt, ap);
        va_end(ap);

        return buff;
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

        switch (x % 10)
        {
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

    inline std::string compress(const std::string &s)
    {
        return tl::StringTools::partOfStr(s);
    }
}


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


namespace tl::bc
{

}

#endif
using namespace tl::bc;