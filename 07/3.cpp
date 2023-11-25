#include "2.cpp"
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <map>

class Factory
{
    std::map < char, std::function < std::unique_ptr < Figure > (const std::string&) > > create 
    {
        { 'R', [](const std::string& params) { return std::unique_ptr < Rectangle > (Rectangle::make(params)); } },
        { 'S', [](const std::string& params) { return std::unique_ptr < Square > (Square::make(params)); } },
        { 'C', [](const std::string& params) { return std::unique_ptr < Circle > (Circle::make(params)); } }
    };

    Factory() { } 
public:
    static Factory& factory_instance() 
    {
        static Factory p_instance;
        return p_instance;
    }

    std::unique_ptr < Figure > create_figure(const std::string& figure_state)
    {
        char figure_type;
        std::string params;
        std::stringstream ss(figure_state);
        ss >> figure_type;
        std::getline(ss, params);
        return create[figure_type](params);
    }
};

int main()
{
    std::vector < std::unique_ptr < Figure > > figures;
    Factory fact_instance = Factory::factory_instance();
    std::string figure_state;

    while (std::getline(std::cin, figure_state))
        figures.push_back(fact_instance.create_figure(figure_state));

    std::stable_sort(figures.begin(), figures.end(), [](const std::unique_ptr < Figure >& left, const std::unique_ptr < Figure >& right)
    {
        return left->get_square() < right->get_square();
    });

    for (auto& figure: figures)
        std::cout << figure->to_string() << "\n";

    return 0;
}