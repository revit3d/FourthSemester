#include <iostream>
#include <string>

int main() 
{
    bool is_cf = true;
    bool is_cfp = true;
    bool S_found_left = false;
    bool S_found_right = false;
    bool empty_ex = false;
    bool full_terminal_left = false;

    std::string left;
    std::string right;

    while (std::cin >> left >> right)
    {
        bool full_terminal = true;
        for (auto ch: left)
            if (!(isdigit(ch) || islower(ch)))
                full_terminal = false;

        if (full_terminal)
            full_terminal_left = true;
        if (left == "S")
            S_found_left = true;
        if (right == "_")
        {
            if (left == "S")
                empty_ex = true;
            else
                is_cfp = false;
        }
        if (full_terminal || left.size() != 1)
            is_cf = false;
        if (right.find('S') != std::string::npos)
            S_found_right = true;
        if (left.size() > right.size())
            is_cfp = false;
    }
    if (empty_ex && S_found_right)
        is_cfp = false;

    if (!S_found_left || full_terminal_left)
        std::cout << "-1\n";
    else if (is_cf && is_cfp)
            std::cout << "23\n";
    else if (is_cf)
        std::cout << "2\n";
    else
        std::cout << "10\n";

    return 0;
}