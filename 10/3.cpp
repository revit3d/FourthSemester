#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
    bool ok = true, found_term = false;
    size_t pos = 0;
    char cur_char;
    std::string cur_state, new_state, input_str;
    std::map < std::string, std::map < char, std::string > > machine;

    while (std::cin >> cur_state && cur_state != "END")
    {
        std::cin >> cur_char >> new_state;
        machine[cur_state][cur_char] = new_state;
    }

    std::vector < std::string > term_states;
    while (std::cin >> cur_state && cur_state != "END")
        term_states.push_back(cur_state);

    std::cin >> cur_state >> input_str;
    while (pos < input_str.size())
    {
        auto it = machine.find(cur_state);
        if (it != machine.end())
        {
            auto it2 = it->second.find(input_str[pos]);
            if (it2 != it->second.end())
            {
                ++pos;
                cur_state = it2->second;
            }
            else  
            {
                ok = false;
                break;
            }
        }
        else  
        {
            ok = false;
            break;
        }
    }

    for (auto& state: term_states)
        if (state == cur_state)
            found_term = true;

    ok &= found_term;
    std::cout << ok << "\n" << pos << "\n" << cur_state << std::endl;

    return 0;
}