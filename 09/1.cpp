#include <iostream>
#include <string>

int main()
{
    bool alpha, ok;
    std::string str;
    while (std::cin >> str)
    {
        alpha = true;
        ok = true;
        for (size_t i = 0; i < str.length(); i++)
        {
            if (alpha)
            {
                if (str[i] == '3' || str[i] == '4')
                    continue;
                else if (str[i] == '1' || str[i] == '2')
                    alpha = false;
                else  
                {
                    ok = false;
                    break;
                }
            }
            else  
            {
                if (str[i] == '1' || str[i] == '2')
                    continue;
                else
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            std::cout << "1\n";
        else
            std::cout << "0\n";
    }

    return 0;
}