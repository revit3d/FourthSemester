#include <iostream>
#include <string>

int oct_to_num(const std::string num_str) 
{
    enum { 
        hex = 16,
        dec = 10,
    };
    uint8_t num = 0;
    for (auto ch : num_str)
    {
        if ('0' <= ch && ch <= '9') 
            num = num * hex + ch - '0';
        else
            num = num * hex + ch - 'a' + dec;
    }
    return num;
}

int main() 
{
    enum
    {
        hex = 16,
        quat = 4,
    };
    std::string num_str;
    uint32_t num = 0;
    int oct_cnt;
    while (std::cin >> num_str)
    {
        oct_cnt = 0;
        while (oct_cnt < hex && !std::cin.eof())
        {
            std::cin >> num_str;
            num = num * hex * hex + oct_to_num(num_str);
            oct_cnt++;
            if (oct_cnt % quat == 0)
            { 
                std::cout << num << std::endl;
                num = 0;
            }
        }
    }

    return 0;
}