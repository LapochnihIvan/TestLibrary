#ifndef TESTLIBRARY_STANDARDREADERS_H
#define TESTLIBRARY_STANDARDREADERS_H

#ifdef PART_OF_FILE_STD_READERS
#   include "PartOfFileReader.h"
#elif defined(FILE_STD_READERS)
#   include "FileReader.h"
#else
#   include "PartOfStdinReader.h"
#endif

namespace tl
{
    struct StandardReaders
    {
#ifdef PART_OF_FILE_STD_READERS
        static PartOfFileReader input;
        static PartOfFileReader output;
        static PartOfFileReader ans;
#elif defined(FILE_STD_READERS)
        static FileReader input;
        static FileReader output;
        static FileReader ans;
#else
        static PartOfStdinReader input;
        static PartOfStdinReader output;
        static PartOfStdinReader ans;
#endif
    };
}

#endif //TESTLIBRARY_STANDARDREADERS_H
