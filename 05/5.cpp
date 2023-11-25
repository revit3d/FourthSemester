#include <iostream>
#include <cstdint>
#include <map>

constexpr uint64_t mod = 4294967161ull;

int main()
{
    uint64_t val;
    uint32_t row, col;
    std::map < uint32_t, std::map <  uint32_t, uint64_t > > matrix1, res;
    bool is_first = true;

    while (std::cin >> row >> col >> val)
    {
        if (is_first)
        {
            if (row == 0 && col == 0 && val == mod)
                is_first = false;
            else
                matrix1[col][row] = val % mod;
        }
        else
        {
            auto it = matrix1[row].begin();
            for (; it != matrix1[row].end(); ++it)
                res[it->first][col] = (((val * it->second) % mod) + res[it->first][col]) % mod;
        }
    }

    for (auto& column: res)
        for (auto& elem: column.second)
            if (elem.second)
                std::cout << column.first << " " << elem.first << " " << elem.second << "\n";

    return 0;
}