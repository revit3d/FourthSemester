#include <iostream>
#include <cstdint>
#include <list>

int main()
{
    int32_t input;
    int32_t x, y;
    std::list < int32_t > lst;

    while (std::cin >> input && input != 0)
        lst.push_back(input);
    
    while (std::cin >> x)
    {
        if (x < 0)
        {
            auto it = lst.begin();
            while (x < -1 && it != lst.end())
            {
                x++;
                it++;
            }
            if (it != lst.end())
                it = lst.erase(it);
        }
        else
        {
            std::cin >> y;
            auto it = lst.begin();
            while (x > 1 && it != lst.end())
            {
                x--;
                it++;
            }
            lst.insert(it, y);
        }
    }

    for (const int32_t& elem: lst)
        std::cout << elem << "\n";
    lst.clear();

    return 0;
}