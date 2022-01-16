#include "../include/StandardReaders.h"

namespace tl
{
#ifdef PART_OF_FILE_STD_READERS
    PartOfFileReader StandardReaders::input(true);
    PartOfFileReader StandardReaders::output(true);
    PartOfFileReader StandardReaders::ans(true);
#elif defined(FILE_STD_READERS)
    FileReader StandardReaders::input(true);
    FileReader StandardReaders::output(true);
    FileReader StandardReaders::ans(true);
#else
    PartOfStdinReader StandardReaders::input(true);
    PartOfStdinReader StandardReaders::output(true);
    PartOfStdinReader StandardReaders::ans(true);
#endif
}
