#include <iostream>
#include <string>
#include <vector>
#include <set>

void add_symbol(const std::vector < std::pair < char, std::string > >& gram, std::set < char >& used, char symbol)
{
    for (auto elem: gram)
    {
        if (elem.first == symbol)
            for (auto& sym: elem.second)
                if (std::isupper(sym) && !used.count(sym))
                {
                    used.insert(sym);
                    add_symbol(gram, used, sym);
                }
    }
}

int main()
{
    char ch;
    std::string str;
    std::vector < std::pair < char, std::string > > gram;
    std::set < char > used{'S'};

    while (std::cin >> ch >> str)
        gram.push_back(std::make_pair(ch, str));

    add_symbol(gram, used, 'S');

    for (auto& elem: gram)
        if (used.count(elem.first))
            std::cout << elem.first << " " << elem.second << std::endl;

    return 0;
}