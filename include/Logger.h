#ifndef TESTLIBRARY_LOGGER_H
#define TESTLIBRARY_LOGGER_H

#ifndef WITHOUT_LOGS
#include <cstdio>
#include <cstdint>
#include <cstdarg>

#include <iostream>

#include "TestLibraryIOSettings.h"

namespace tl
{
    class Logger
    {
    public:
        explicit Logger(const char* funcName,
                        std::uint8_t funcNameSize);

        void funcStartLog(const char* format = nullptr, ...);

        void funcFinishLog(const char* format = nullptr, ...);

        static void resultLog(const char* messageFormat, std::va_list& ap);

    private:
        const char* mFuncName;
        std::uint8_t mFuncNameSize;
#ifdef TIME_CHECK_IN_LOGS
        double mStartTime;
        double mFinishTime;
#endif //TIME_CHECK_IN_LOGS

        static std::FILE* mFile;
        static std::uint8_t mCountTabs;

        static void write(const char* message, std::size_t messageSize);
    };
}

#if !defined(__PRETTY_FUNCTION__) && defined(_MSC_VER)
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#define FUNC_START_LOG(loggerName, ...)                                          \
    tl::Logger loggerName(__PRETTY_FUNCTION__, sizeof(__PRETTY_FUNCTION__) - 1); \
    (loggerName).funcStartLog(__VA_ARGS__)

#define FUNC_FINISH_LOG(logger, ...) (logger).funcFinishLog(__VA_ARGS__)

#define FUNC_RETURN_LOG(logger, resultType, resultName, format, returnVal) \
    resultType resultName(returnVal);                                      \
    (logger).funcFinishLog(format, resultName);                            \
                                                                           \
    return resultName

#define BOOL_FUNC_RETURN_LOG(logger, resultName, returnVal)  \
    bool resultName(returnVal);                              \
    (logger).funcFinishLog((resultName) ? "true" : "false"); \
                                                             \
    return resultName
#else
#define FUNC_START_LOG(loggerName, funcName, ...) void(0)

#define FUNC_FINISH_LOG(logger, ...) void(0)

#define FUNC_RETURN_LOG(logger, resultType, resultName, format, returnVal) \
    return returnVal

#define BOOL_FUNC_RETURN_LOG(logger, resultName, returnVal) result returnVal
#endif //WITHOUT_LOGS

#endif //TESTLIBRARY_LOGGER_H
