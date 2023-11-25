#include "cmc_complex.h"

numbers::complex::complex(double _x, double _y): x(_x), y(_y) { }

numbers::complex::complex(const std::string& str) 
{
    std::istringstream ss(str);
    char _;
    ss >> _ >> x >> _ >> y >> _;
}

double numbers::complex::re() const { return this->x; }

double numbers::complex::im() const { return this->y; }

double numbers::complex::abs2() const { return x * x + y * y; }

double numbers::complex::abs() const { return sqrt(abs2()); }

std::string numbers::complex::to_string() const 
{
    std::ostringstream ss;
    ss.precision(10);
    ss << '(' << x << ',' << y << ')';
    return ss.str();
}

const numbers::complex& numbers::complex::operator+= (const numbers::complex& right) 
{ 
    this->x += right.re();
    this->y += right.im();
    return *this; 
}

const numbers::complex& numbers::complex::operator-= (const numbers::complex& right) 
{ 
    this->x -= right.re();
    this->y -= right.im();
    return *this;
}

const numbers::complex& numbers::complex::operator*= (const numbers::complex& right) 
{
    double _x = this->x * right.re() - this->y * right.im();
    double _y = this->y * right.re() + this->x * right.im();
    x = _x;
    y = _y;
    return *this;
}

const numbers::complex& numbers::complex::operator/= (const numbers::complex& right) 
{
    double _x = (this->x * right.re() + this->y * right.im()) / right.abs2();
    double _y = (this->y * right.re() - this->x * right.im()) / right.abs2();
    x = _x;
    y = _y;
    return *this;
}

numbers::complex numbers::complex::operator~() const { return numbers::complex(this->x, -this->y); }

numbers::complex numbers::complex::operator-() const { return numbers::complex(-this->x, -this->y); }

numbers::complex numbers::operator+ (const numbers::complex& left, const numbers::complex& right) { return numbers::complex(left) += right; }

numbers::complex numbers::operator- (const numbers::complex& left, const numbers::complex& right) { return numbers::complex(left) -= right; }

numbers::complex numbers::operator* (const numbers::complex& left, const numbers::complex& right) { return numbers::complex(left) *= right; }

numbers::complex numbers::operator/ (const numbers::complex& left, const numbers::complex& right) { return numbers::complex(left) /= right; }