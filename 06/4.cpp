#include <algorithm>
#include <vector>

template < typename T1 , typename T2 >
T2 myremove(T1 begin_idx, T1 end_idx, T2 begin, T2 end)
{
    std::vector < int > copy_idx(begin_idx, end_idx);
    std::sort(copy_idx.begin(), copy_idx.end());
    auto last = std::unique(copy_idx.begin(), copy_idx.end());
    copy_idx.erase(last, copy_idx.end());

    bool flag;
    int count = 0;
    auto res = begin;

    while (begin != end) {
        flag = 1;
        auto next_erase = copy_idx.begin();

        while (next_erase != copy_idx.end())
        {
            if (*next_erase == count) 
            {
                flag = 0;
                break;
            }
            ++next_erase;
        }

        if (flag) 
        {
            *res = std::move(*begin);
            ++res;
        }
        count++;
        ++begin;
    }
    return res;
}