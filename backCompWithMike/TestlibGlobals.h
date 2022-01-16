#ifndef TESTLIBRARY_TESTLIBGLOBALS_H
#define TESTLIBRARY_TESTLIBGLOBALS_H

#include "InStream.h"
#include "../include/StandardReaders.h"

namespace tl::bc
{
    InStream inf(tl::StandardReaders::input);

    InStream ouf(tl::StandardReaders::output);

    InStream ans(tl::StandardReaders::ans);
}

#endif //TESTLIBRARY_TESTLIBGLOBALS_H
