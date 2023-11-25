#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>

class funct
{
    double sum;

public:
    funct(): sum(0.0) { }

    void operator()(double x) { sum += x; }

    double get_sum() { return this->sum; }
};

double process(std::vector < double >& v)
{
    size_t margin = v.size() / 10;
    auto left_bound = v.begin() + margin;
    auto right_bound = v.end() - margin;
    std::sort(left_bound, right_bound);
    margin = (v.size() - 2 * margin) / 10;
    left_bound += margin;
    right_bound -= margin;
    funct f = for_each(left_bound, right_bound, funct());
    return f.get_sum() / (right_bound - left_bound);
}

int main()
{
    double input;
    std::vector < double > results;
    while (std::cin >> input)
        results.push_back(input);
    std::cout << std::fixed << std::setprecision(10) << process(results) << std::endl;

    return 0;
}