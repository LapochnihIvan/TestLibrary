#ifndef TESTLIBRARY_TESTLIBRARYIOSETTINGS_H
#define TESTLIBRARY_TESTLIBRARYIOSETTINGS_H

#ifdef __GNUC__
#   include <unistd.h>

#   define CORRECT_VER(funcName) funcName
#elif defined(_MSC_VER)
#   include <io.h>

#   define CORRECT_VER(funcName) _ ## funcName
#endif

#include <fcntl.h>

#endif //TESTLIBRARY_TESTLIBRARYIOSETTINGS_H
