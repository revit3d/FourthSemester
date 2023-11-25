#include <iostream>
#include <cstdint>
#include <string>
#include <map>


int main()
{
    int32_t grade;
    std::string name;
    std::map < std::string, std::pair < int32_t, int32_t > > gpa;

    while (std::cin >> name >> grade)
    {
        if (gpa.count(name) == 0)
            gpa[name] = std::make_pair(grade, 1);
        else  
            gpa[name] = std::make_pair(gpa[name].first + grade, gpa[name].second + 1);
    }

    for (auto pr : gpa)
        std::cout << pr.first << " " << pr.second.first / (double)pr.second.second << "\n";

    return 0;
}