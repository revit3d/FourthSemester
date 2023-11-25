#include <iostream>
#include <sstream>
#include <cmath>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char *argv[])
{
    enum
    {
        complex_num = 1,
        real_num = 2,
        integer = 3,
        stack_args = 4,
    };
    numbers::complex w1(argv[complex_num]), sum;
    double r;
    int n;
    char **w2 = argv + stack_args;

    std::stringstream ss1(argv[real_num]);
    ss1 >> r;
    std::stringstream ss2(argv[integer]);
    ss2 >> n;

    std::vector < std::string > stack(w2, w2 + argc - stack_args);

    for (int i = 0; i < n; i++) 
    {
        double arg = (i * 2 + 1) * M_PI / n;
        numbers::complex z = numbers::complex(r * cos(arg), r * sin(arg));
        sum += numbers::eval(stack, w1 + z) * numbers::complex(-sin(arg), cos(arg));
    }

    sum *= numbers::complex(2 * M_PI * r / n);
    std::cout << sum.to_string() << std::endl;

    return 0;
}