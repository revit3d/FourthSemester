#include "cmc_complex.h"
#include "cmc_complex_stack.h"

numbers::complex numbers::eval(const std::vector<std::string> &args, const complex &z) 
{
    complex_stack stack;

    std::function < complex(complex_stack&) > stack_pop = [](complex_stack& stack)
    {
        complex z = +stack;
        stack = ~stack;
        return z;
    };

    std::map < char, std::function < void(complex_stack&, const complex&) > > op_map 
    {
        {'+', [stack_pop](complex_stack& stack, const complex& z) 
        {
            complex z1 = stack_pop(stack);
            complex z2 = stack_pop(stack);
            stack = stack << (z1 + z2);   
        } },
        {'-', [stack_pop](complex_stack& stack, const complex& z) 
        {
            complex z1 = stack_pop(stack);
            complex z2 = stack_pop(stack);
            stack = stack << (z2 - z1);
        } },
        {'*', [stack_pop](complex_stack& stack, const complex& z) 
        {
            complex z1 = stack_pop(stack);
            complex z2 = stack_pop(stack);
            stack = stack << (z1 * z2);
        } },
        {'/', [stack_pop](complex_stack& stack, const complex& z) 
        {
            complex z1 = stack_pop(stack);
            complex z2 = stack_pop(stack);
            stack = stack << (z2 / z1);   
        } },
        {'!', [](complex_stack& stack, const complex& z) { stack = (stack << +stack); } },
        {';', [](complex_stack& stack, const complex& z) { stack = ~stack; } },
        {'~', [stack_pop](complex_stack& stack, const complex& z) 
        {
            complex z1 = stack_pop(stack);
            stack = (stack << ~z1);
        } },
        {'#', [stack_pop](complex_stack& stack, const complex& z) 
        {
            complex z1 = stack_pop(stack);
            stack = (stack << -z1);
        } },
        {'z', [](complex_stack& stack, const complex& z) { stack = (stack << z); } }
    };

    for (auto& item : args) 
    {
        if (item.size() == 1)
            op_map[item[0]](stack, z);
        else
            stack = (stack << complex(item));
    }
    return +stack; 
}