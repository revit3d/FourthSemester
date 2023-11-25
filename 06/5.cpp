#include <iterator>

template < typename T, typename Comp >
void selection_sort(T begin, T end, Comp comp)
{
    for (; begin != end; ++begin)
    {
        auto cur_min = begin;
        for (auto cur = begin + 1; cur != end; cur++)
        {
            if (comp(*cur, *cur_min))
                cur_min = cur;
        }
        std::iter_swap(begin, cur_min);
    }
}

template < typename T >
void selection_sort(T begin, T end)
{
    for (; begin != end; ++begin)
    {
        auto cur_min = begin;
        for (auto cur = begin + 1; cur != end; cur++)
        {
            if (*cur < *cur_min)
                cur_min = cur;
        }
        std::iter_swap(begin, cur_min);
    }
}