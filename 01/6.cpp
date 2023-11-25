#include <iostream>
#include <iomanip>
#include <ostream>
#include <vector>
#include <cmath>

class Point
{
    int x;
    int y;

    public:
    Point(const int _x, const int _y): x(_x), y(_y) { }

    const int get_x() const 
    {
        return this->x;
    }

    const int get_y() const 
    {
        return this->y;
    }
};

class Line
{
    //ax + by = c
    constexpr static double eps = 1e-9;
    double a, b, c;
    
    public:
    Line (const Point& _p1, const Point& _p2)
    {
        a = _p2.get_y() - _p1.get_y();
        b = _p1.get_x() - _p2.get_x();
        c = a * (_p1.get_x()) + b * (_p1.get_y());
        //std::cout << a << " " << b << " " << c << "\n";
    }

    const std::vector < double > get_parameters() const
    {
        return std::vector < double > { a, b, c };
    }

    const bool operator==(const Line& l) const
    {
        auto l_params = l.get_parameters();
        return std::abs(a * l_params[1] - b * l_params[0]) < eps && 
            std::abs(b * l_params[2] - c * l_params[1]) < eps &&
            std::abs(a * l_params[2] - c * l_params[0]) < eps;
    }

    const void get_interception_point(const Line& l) const
    {
        auto l_params = l.get_parameters();
        double det = a * l_params[1] - b * l_params[0];
        if (std::abs(det) < eps) //parallel
        {
            if (*this == l) //parallel and intersecting => same line
                std::cout << "2\n";
            else 
                std::cout << "0\n";
        }
        else
        {
            double x = (l_params[1] * c - l_params[2] * b) / det;
            double y = (l_params[2] * a - l_params[0] * c) / det;
            std::cout << "1\n" << std::setprecision(6) << x << " " << y << std::endl;
        }
    }
};

int main()
{
    std::vector < Point > pts;
    for (int i = 0; i < 4; i++)
    {
        int x, y;
        std::cin >> x >> y;
        pts.push_back(Point(x, y));
    }
    Line l1(pts[0], pts[1]);
    Line l2(pts[2], pts[3]);
    l1.get_interception_point(l2);

    return 0;
}