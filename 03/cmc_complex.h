#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <functional>

#pragma once

namespace numbers
{
    class complex
    {
        double x, y;

        public:
        complex(double _x = 0, double _y = 0);

        explicit complex(const std::string& str);

        double re() const;

        double im() const;

        double abs2() const;

        double abs() const;

        std::string to_string() const;

        const complex& operator+= (const complex& right);

        const complex& operator-= (const complex& right);

        const complex& operator*= (const complex& right);

        const complex& operator/= (const complex& right);

        friend complex operator+ (const complex& left, const complex& right);
        
        friend complex operator- (const complex& left, const complex& right);

        friend complex operator* (const complex& left, const complex& right);

        friend complex operator/ (const complex& left, const complex& right);

        complex operator~() const;

        complex operator-() const;
    };

    complex eval(const std::vector<std::string> &args, const complex &z);
}