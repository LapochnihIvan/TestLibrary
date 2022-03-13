#ifndef TESTLIBRARY_TESTLIBGLOBALS_H
#define TESTLIBRARY_TESTLIBGLOBALS_H

#include "InStream.h"
#include "../include/StandardReaders.h"

#if __cplusplus >= 201703L
namespace tl::bc
#else
namespace tl { namespace bc
#endif //__cplusplus >= 201703L
{
    InStream inf(tl::StandardReaders::input);

    InStream ouf(tl::StandardReaders::output);

    InStream ans(tl::StandardReaders::ans);
#if __cplusplus >= 201703L
}
#else
}}
#endif //__cplusplus >= 201703L

#endif //TESTLIBRARY_TESTLIBGLOBALS_H
