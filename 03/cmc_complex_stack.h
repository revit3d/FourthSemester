#include "cmc_complex.h"

#pragma once

namespace numbers 
{
    class complex_stack 
    {
        size_t size_;
        complex *stack;

    public:
        complex_stack();

        complex_stack(size_t new_size);

        complex_stack(const complex_stack &new_stack);

        ~complex_stack();

        size_t size() const;

        complex operator [](size_t i) const;

        friend complex_stack operator <<(const complex_stack &cs, complex c);
        
        complex operator +() const;

        complex_stack operator ~() const;
        
        const complex_stack& operator =(const complex_stack &cs);
    };
}