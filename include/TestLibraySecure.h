#ifndef TESTLIBRARY_TESTLIBRAYSECURE_H
#define TESTLIBRARY_TESTLIBRAYSECURE_H

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
#   ifdef __GNUC__
#       define TESTLIBRARY_ASSERT(expression, message)						\
        if (!(expression))                                                  \
            __assert_fail(message, __FILE__, __LINE__, __ASSERT_FUNCTION)
#       define TESTLIBRARY_NONNULL_ASSERT(ptr)				                \
        if (ptr == nullptr)                                                 \
            __assert_fail(#ptr " can't be null",                            \
                    __FILE__, __LINE__, __ASSERT_FUNCTION)
#   elif _MSC_VER
#       define TESTLIBRARY_ASSERT(expression, message)						\
        if (!expression)                                                    \
            _wassert(L ## (message), __FILEW__,                             \
                    static_cast<unsigned>(__LINE__))
#       define TESTLIBRARY_NONNULL_ASSERT(ptr)				                \
        if (ptr == nullptr)                                                 \
            _wassert(L ## #ptr " can't be null",                            \
                    __FILEW__, static_cast<unsigned>(__LINE__)
#   endif
#endif

#endif //TESTLIBRARY_TESTLIBRAYSECURE_H
