#ifndef TESTLIBRARY_STANDARDREADERS_H
#define TESTLIBRARY_STANDARDREADERS_H

#include "FileReader.h"
#include "StdinReader.h"

namespace tl
{
    struct StandardReaders
    {
        static FileReader input;
        static FileReader output;
        static StdinReader ans;
    };
}

#endif //TESTLIBRARY_STANDARDREADERS_H
