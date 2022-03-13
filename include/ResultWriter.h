#ifndef TESTLIBRARY_RESULTWRITER_H
#define TESTLIBRARY_RESULTWRITER_H

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

#include "TestLibraryIOSettings.h"
#include "Logger.h"

namespace tl
{
    class ResultWriter
            {
    public:
        static void vOKResultWr(const char* format,
                                std::va_list& ap);

        static void vWAResultWr(const char* format,
                                std::va_list& ap);

        static void vPEResultWr(const char* format,
                                std::va_list& ap);

        static void OKResultWr(const char* format, ...);

        static void WAResultWr(const char* format, ...);

        static void PEResultWr(const char* format, ...);

    private:
        static void printMessage(const char* result,
                                 const char* format,
                                 std::va_list& ap);
    };
}

#endif //TESTLIBRARY_RESULTWRITER_H
