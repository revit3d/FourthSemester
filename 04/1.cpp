#include <vector>
#include <cstdint>
#include <algorithm>

void process(const std::vector < uint64_t >& v1, std::vector < uint64_t >& v2, std::size_t step)
{
    auto it1 = v1.begin();
    auto it2 = v2.rbegin();
    while (it1 < v1.end() && it2 < v2.rend())
    {
        it2[0] += it1[0];
        it1 += step;
        it2++; 
    }
}