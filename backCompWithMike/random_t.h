#ifndef TESTLIBRARY_RANDOM_T_H
#define TESTLIBRARY_RANDOM_T_H

class pattern;

#if __cplusplus >= 201703L
namespace tl::bc
#else
namespace tl { namespace bc
#endif //__cplusplus >= 201703L
{
    class random_t
    {
    public:
    };
#if __cplusplus >= 201703L
}
#else
}}
#endif //__cplusplus >= 201703L

#endif //TESTLIBRARY_RANDOM_T_H
