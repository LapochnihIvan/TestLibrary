#ifndef TESTLIBRARY_STANDARDREADERS_H
#define TESTLIBRARY_STANDARDREADERS_H

#include "PartOfStdinReader.h"

namespace tl
{
    struct StandardReaders
    {
        static PartOfStdinReader input;
        static PartOfStdinReader output;
        static PartOfStdinReader ans;
    };
}

#endif //TESTLIBRARY_STANDARDREADERS_H
