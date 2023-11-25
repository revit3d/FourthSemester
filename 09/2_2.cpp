#include <string>
#include <iostream>

int main() 
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    
    char sym;
    while (!std::cin.eof()) {
        size_t k{}, m{};
        bool lg_flag{true};
        std::cin.get(sym);
        while (isspace(sym) && !std::cin.eof())
            std::cin.get(sym);
        if (std::cin.eof())
            break;
        while (sym == '0' && !isspace(sym)) 
        {
            ++k;
            std::cin.get(sym);
        }
        while (sym == '1' && !isspace(sym)) 
        {
            ++m;
            std::cin.get(sym);
        }
        if ((sym != '1' && sym != '0' && !isspace(sym) && !std::cin.eof()) || k == 0 || m == 0) 
        {
            lg_flag = false;
            while (!isspace(sym) && !std::cin.eof())
                std::cin.get(sym);
        }
        while (!isspace(sym) && !std::cin.eof()) 
        {
            size_t k_cur = 0, m_cur = 0;
            while (sym == '0') 
            {
                ++k_cur;
                std::cin.get(sym);
            }
            while (sym == '1') 
            {
                ++m_cur;
                std::cin.get(sym);
            }
            if (k_cur != k || m_cur != m) 
            {
                lg_flag = false;
                while (!isspace(sym) && !std::cin.eof())
                    std::cin.get(sym);
            }
        }
        std::cout << (int) lg_flag << std::endl;
    }

    return 0;
}