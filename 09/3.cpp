#include <iostream>

/*
S = AQBX
AQ = aAQb | aQb
Qb = 0Qb1 | 0b1
*/

int main()
{
    std::string str;
    while (std::cin >> str) 
    {
        size_t pos = 0;
        bool ok = true;
        size_t a_cnt = 0, zeros_cnt = 0, b_cnt = 0, ones_cnt = 0;

        while (pos < str.size() && str[pos] == 'a')
            ++pos, ++a_cnt;
        while (pos < str.size() && str[pos] == '0')
            ++pos, ++zeros_cnt;
        while (pos < str.size() && str[pos] == 'b')
            ++pos, ++b_cnt;
        while (pos < str.size() && str[pos] == '1')
            ++pos, ++ones_cnt;

        if (pos < str.size() || a_cnt != b_cnt || zeros_cnt != ones_cnt || a_cnt == 0 || zeros_cnt == 0)
            ok = false;

        std::cout << ok << std::endl;
    }

    return 0;
}