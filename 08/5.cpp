#include <iostream>
#include <sstream>
#include <chrono>
#include <string>

auto convert(const std::string& date)
{
    std::stringstream ss;
    ss << date;
    int year, mon, day;
    ss >> year;
    ss.ignore();
    ss >> mon;
    ss.ignore();
    ss >> day;
    auto parsed = std::chrono::year{year}/mon/day;
    return parsed;
}

int main()
{
    std::string date;
    long long ans = 0;
    std::getline(std::cin, date);
    auto prev_tp = convert(date);
    
    while (std::getline(std::cin, date))
    {
        auto new_tp = convert(date);
        auto duration = std::chrono::sys_days{new_tp} - std::chrono::sys_days{prev_tp};
        ans += std::abs((std::chrono::duration_cast < std::chrono::days > (duration)).count());
        prev_tp = new_tp;
    }
    std::cout << ans << std::endl;

    return 0;
}