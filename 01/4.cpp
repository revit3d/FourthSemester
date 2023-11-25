#include <iostream>
#include <iomanip>
#include <cmath>

int main() 
{
    double avg = 0, rse = 0, sum_2 = 0;
    double input, cnt = 0;
    while (std::cin >> input) 
    {
        avg += input;
        sum_2 += input * input;
        cnt++;
    }
    avg /= cnt;
    rse = sqrt(sum_2 / cnt - avg * avg);
    std::cout << std::setprecision(10) << avg << std::endl << rse << std::endl;

    return 0;
}