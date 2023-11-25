#include "1.cpp"
#include <string>
#include <sstream>
#include <cmath>

class Rectangle: public Figure
{
    double width_, height_;

public:
    Rectangle(const double width, const double height): width_(width), height_(height) { }

    double get_square() const override
    {
        return width_ * height_;
    }

    static Rectangle* make(const std::string& params)
    {
        double width, height;
        std::stringstream ss(params);
        ss >> width >> height;
        return new Rectangle(width, height);
    }
};

class Square: public Figure
{
    double side_;

public:
    Square(const double side): side_(side) { }

    double get_square() const override
    {
        return side_ * side_;
    }

    static Square* make(const std::string& params)
    {
        double side;
        std::stringstream ss(params);
        ss >> side;
        return new Square(side);
    }
};

class Circle: public Figure
{
    double r_;

public:
    Circle(const double r): r_(r) { }

    double get_square() const override
    {
        return M_PI * r_ * r_;
    }

    static Circle* make(const std::string& params)
    {
        double r;
        std::stringstream ss(params);
        ss >> r;
        return new Circle(r);
    }
};