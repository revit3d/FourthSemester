#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>

int main()
{
    int32_t input;
    std::vector < int32_t > nums;
    while (std::cin >> input)
        nums.push_back(input);
    
    std::stable_sort(nums.begin(), nums.end(), [](int32_t left, int32_t right)
    {
        int8_t lcount = 0, rcount = 0;
        while (left > 0 || right > 0)
        {
            lcount += (left & 1);
            rcount += (right & 1);
            left >>= 1;
            right >>= 1;
        }
        return lcount < rcount;
    });
    for (int32_t out : nums)
        std::cout << out << "\n";

    return 0;
}