#include <iostream>
#include <cstdint>
#include <map>

constexpr uint64_t mod = 4294967161ll;

int main()
{
    uint32_t row, col;
    uint64_t val;
    std::map < std::pair < uint32_t, uint32_t >, uint64_t > matrix;
    bool is_adding = false;

    while (std::cin >> row >> col >> val)
    {
        //0 0 4294967161
        if (row == 0 && col == 0 && val == mod)
        {
            is_adding = true;
            continue;
        }
        if (!is_adding)
            matrix[std::make_pair(row, col)] = val % mod;
        else
        {
            auto pr = std::make_pair(row, col);
            if (matrix.count(pr))
                matrix[pr] = (matrix[pr] + (val % mod)) % mod;
            else
                matrix[pr] = val % mod;
        }
    }

    for (auto& elem : matrix)
        if (elem.second)
            std::cout << elem.first.first << " " << elem.first.second << " " << elem.second << "\n";

    return 0;
}