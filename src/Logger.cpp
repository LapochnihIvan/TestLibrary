#include "../include/Logger.h"

namespace tl
{
    Logger::Logger(const char* funcName,
                   std::uint8_t funcNameSize) :
            mFuncName(funcName),
            mFuncNameSize(funcNameSize)
    {
        if (mFile == nullptr)
        {
#ifdef LOGS_TO_STDIN
            mFile = stdin;
#else
            mFile = std::fopen("../logs/logs.txt", "w");
#endif
        }
    }

    void
    Logger::funcStartLog(const char* format, ...)
    {
        for (std::uint8_t numTab = 0; numTab < mCountTabs; numTab++)
        {
            putc('\t', mFile);
        }

        write(mFuncName, mFuncNameSize);
        write(" has started", 12);

        if (format != nullptr)
        {
            write(" with args: ", 12);
            std::va_list ap;
            va_start(ap, format);
            std::vfprintf(mFile, format, ap);
            va_end(ap);
        }
        putc('\n', mFile);

        mCountTabs++;

#ifdef TIME_CHECK_IN_LOGS
#endif //TIME_CHECK_IN_LOGS
    }

    void
    Logger::funcFinishLog(const char* format, ...)
    {
        for (std::uint8_t numTab = 0; numTab < mCountTabs; numTab++)
        {
            putc('\t', mFile);
        }

        write(mFuncName, mFuncNameSize);
        write(" has finished", 13);

        if (format != nullptr)
        {
            write(" with return: ", 14);
            std::va_list ap;
            va_start(ap, format);
            std::vfprintf(mFile, format, ap);
            va_end(ap);
        }
        putc('\n', mFile);

        mCountTabs--;

#ifdef TIME_CHECK_IN_LOGS
#endif //TIME_CHECK_IN_LOGS
    }

    void
    Logger::resultLog(const char* messageFormat, std::va_list& ap)
    {
        write("checker has finished with message ", 34);
        std::vfprintf(mFile, messageFormat, ap);
    }

    FILE* Logger::mFile = nullptr;
    std::uint8_t Logger::mCountTabs = 0;

    void
    Logger::write(const char *message, std::size_t messageSize)
    {
        std::fwrite(static_cast<const void*>(message),
                    1, messageSize, mFile);
    }
}