#include <vector>
#include <cstdint>
#include <algorithm>

void process(const std::vector < int32_t >& v1, std::vector < int32_t >& v2)
{
    std::vector < int32_t > copy = v1;
    std::sort(copy.begin(), copy.end());
    auto last = std::unique(copy.begin(), copy.end());
    copy.erase(last, copy.end());
    for (auto it = copy.rbegin(); it < copy.rend(); it++)
        if ((int32_t)v2.size() > it[0] && it[0] >= 0)
            v2.erase(v2.begin() + it[0]);
}