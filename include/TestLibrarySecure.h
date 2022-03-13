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
#   define TESTLIBRARY_ASSERT(expression, message) void(0)
#   define TESTLIBRARY_NONNULL_ASSERT(ptr) void(0)
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
