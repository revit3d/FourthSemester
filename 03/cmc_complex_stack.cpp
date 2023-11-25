#include "cmc_complex_stack.h"

numbers::complex_stack::complex_stack(): size_(0), stack(nullptr) {}

numbers::complex_stack::complex_stack(size_t new_size) : size_(new_size) { stack = new complex[size_]; }

numbers::complex_stack::complex_stack(const complex_stack &new_stack) : size_{new_stack.size()} 
{
    stack = new complex[size_];
    for (size_t i = 0; i < size(); i++)
        stack[i] = new_stack.stack[i];
}

numbers::complex_stack::~complex_stack() { delete [] stack; }

size_t numbers::complex_stack::size() const { return this->size_; }

numbers::complex numbers::complex_stack::operator [](size_t i) const { return this->stack[i]; }

numbers::complex numbers::complex_stack::operator +() const { return stack[this->size_ - 1]; }

numbers::complex_stack numbers::complex_stack::operator ~() const
{
    complex_stack tmp(size() - 1);
    for (size_t i = 0; i < tmp.size(); i++)
        tmp.stack[i] = stack[i];
    return tmp;
}

const numbers::complex_stack& numbers::complex_stack::operator =(const complex_stack &cs) 
{
    if (this != &cs) 
    {
        size_ = cs.size();
        delete [] stack;
        stack = new complex[size_];
        for (size_t i = 0; i < size(); i++)
            stack[i] = cs.stack[i];
    }
    return *this;
}

numbers::complex_stack numbers::operator <<(const complex_stack &cs, complex c) 
{
    complex_stack tmp(cs.size() + 1);
    for (size_t i = 0; i < cs.size(); i++)
        tmp.stack[i] = cs.stack[i];
    tmp.stack[cs.size()] = c;
    return tmp;
}