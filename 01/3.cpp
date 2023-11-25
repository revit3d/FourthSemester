#include <iostream>

int main() 
{
    std::cin.tie(nullptr);
    bool flag = true; //leading zeroes
    char cur, last;
    while ((cur = std::cin.get()) != EOF)
    {
        if ((cur >= '1' && cur <= '9') || cur == '0') 
        {
            if (flag && (cur != '0')) 
            {
                last = cur;
                flag = false;
            } 
            else 
                last = cur;
            if (!flag) 
            {
                last = cur;
                std::cout << cur;
            }
        } 
        else 
        {
            if (flag && (last == '0'))
                std::cout << '0';
            last = cur;
            std::cout << cur;
            flag = true;
        }
    }
    if (flag && (last == '0')) 
        std::cout << '0';

    return 0;
}