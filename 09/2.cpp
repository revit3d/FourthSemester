#include <iostream>

int main() 
{
    //std::cin.tie(NULL);

    char sym;
    while (!std::cin.eof() && std::cin.get(sym))
    {
        size_t k = 0, m = 0;
        bool ok = true;
        while (isspace(sym) && std::cin.get(sym)) { }
        if (std::cin.eof())
            break;
        while(sym == '0' && std::cin.get(sym))
            ++k;
        while(sym == '1' && std::cin.get(sym))
            ++m;

        if ((sym != '1' && sym != '0' && !isspace(sym) && !std::cin.eof()) || k == 0 || m == 0) 
        {
            ok = false;
            while (!isspace(sym) && !std::cin.get(sym)) { }
        }

        while (!isspace(sym) && !std::cin.eof()) 
        {
            size_t k_cur = 0, m_cur = 0;
            while(sym == '0' && std::cin.get(sym))
                ++k_cur;
            while(sym == '1' && std::cin.get(sym))
                ++m_cur;
            if (k_cur != k || m_cur != m) 
            {
                ok = false;
                while (!isspace(sym) && !std::cin.get(sym)) { }
            }
        }
        std::cout << ok << "\n";
    }

    return 0;
}