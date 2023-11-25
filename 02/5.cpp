#include <string>
#include <iostream>

class BinaryNumber
{
    std::string number;

public:
    BinaryNumber(const std::string &s)
    {
        this->number = s;
    }

    operator std::string() const
    {
        return this->number;
    }

    const BinaryNumber &operator++()
    {
        int carry = 1;
        int pos = this->number.size() - 1;
        //std::cout << pos << std::endl;
        while(carry > 0 && pos >= 0) 
        {
            if (this->number[pos] == '0') 
            {
                carry = 0;
                this->number[pos] = '1';
            }
            else 
            {
                this->number[pos] = '0';
            }
            pos--;
            //std::cout << pos << std::endl;
            //std::cout << this->number << std::endl;
        }
        if (carry) 
        {
            this->number = std::string("1") + this->number;
            //std::cout << this->number << std::endl;
        }
        return *this;
    }
};