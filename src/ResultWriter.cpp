#include "../include/ResultWriter.h"

namespace tl
{
    void ResultWriter::vOKResultWr(const char* format,
                                   std::va_list& ap)
    {
        printMessage("ok ", format, ap);
    }

    void ResultWriter::vWAResultWr(const char* format,
                                   std::va_list& ap)
    {
        printMessage("wa ", format, ap);
    }

    void ResultWriter::vPEResultWr(const char* format,
                                   std::va_list& ap)
    {
        printMessage("pe ", format, ap);
    }

    void ResultWriter::OKResultWr(const char *format, ...)
    {
        std::va_list ap;
        va_start(ap, format);
        vOKResultWr(format, ap);
        va_end(ap);
    }

    void ResultWriter::WAResultWr(const char *format, ...)
    {
        std::va_list ap;
        va_start(ap, format);
        vWAResultWr(format, ap);
        va_end(ap);
    }

    void ResultWriter::PEResultWr(const char *format, ...)
    {
        std::va_list ap;
        va_start(ap, format);
        vPEResultWr(format, ap);
        va_end(ap);
    }

    void ResultWriter::printMessage(const char *result,
                                    const char *format,
                                    std::va_list& ap)
    {
        ::write(1, static_cast<const void*>(result), 3);

        std::vprintf(format, ap);

        Logger::resultLog(format, ap);

        std::exit(0);
    }
}
