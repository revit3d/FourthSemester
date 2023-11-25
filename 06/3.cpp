#include <vector>
#include <cstdlib>

template < typename T, typename F >
void myapply(T begin, T end, F func)
{
    while (begin != end)
    {
        func(*begin);
        ++begin;
    }
}

template < typename T, typename F >
auto myfilter2(T begin, T end, F predicate)
{
    std::vector < std::reference_wrapper < typename T::value_type > > result;
    while (begin != end)
    {
        if (predicate(*begin))
            result.push_back(*begin);
        ++begin;
    }
    return result;
}

template < typename T, typename F >
void myapply(T *begin, T *end, F func)
{
    while (begin != end)
    {
        func(*begin);
        ++begin;
    }
}

template < typename T, typename F >
auto myfilter2(T *begin, T *end, F predicate)
{
    std::vector < std::reference_wrapper < T > > result;
    while (begin != end)
    {
        if (predicate(*begin))
            result.push_back(*begin);
        ++begin;
    }
    return result;
}