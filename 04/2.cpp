#include <vector>
#include <cstdint>
#include <algorithm>

void process(std::vector < int64_t >& v, int64_t threshold)
{
    std::vector < int64_t > append;
    for (auto it = v.rbegin(); it < v.rend(); it++)
        if (it[0] >= threshold)
            append.push_back(it[0]);
    for (auto it = append.begin(); it < append.end(); it++)
        v.push_back(it[0]);
}