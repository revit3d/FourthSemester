#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include <set>
#include <map>

class Date
{
public:
    int16_t day, month, year;

    bool operator< (const Date& right) const
    {
        return this->year < right.year || 
            (this->year == right.year && this->month < right.month) ||
            (this->year == right.year && this->month == right.month && this->day < right.day);
    }
};

int main()
{
    int32_t grade;
    char ign;
    Date dt;
    std::string name;
    std::map < std::string, std::map < Date, int32_t > > grades;
    std::set < std::string > names;
    std::set < Date > dates;

    while (std::cin >> name >> dt.year >> ign >> dt.month >> ign >> dt.day >> grade)
    {
        names.insert(name);
        dates.insert(dt);
        //std::cout << grade << "\n";
        grades[name][dt] = grade;
    }

    std::cout << ".\t";
    for (auto& dt : dates)
        std::cout << std::setfill('0') << dt.year << "/" 
            << std::setw(2) << dt.month << "/" 
            << std::setw(2) << dt.day << "\t";
    std::cout << "\n";

    for (auto& student_record : grades)
    {
        std::cout << student_record.first << "\t";
        for (auto& dt : dates)
        {
            if (student_record.second.count(dt))
                std::cout << student_record.second[dt] << "\t\t";
            else 
                std::cout << ".\t\t";
        }
        std::cout << "\n";
    }

    return 0;
}