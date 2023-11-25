#include <cmath>
#include <algorithm>

namespace Game
{
    template < typename T >
    class Coord
    {
    public:
        using value_type = T;
        T row{}, col{};

        Coord(const T& _row = 0, const T& _col = 0): row(_row), col(_col) { }
    };

    template < typename T >
    auto dist(const Coord < T >& size, const Coord < T >& from, const Coord < T >& to)
    {
        long long res;
        long long dr = (long long)to.row - from.row;
        long long dc = (long long)to.col - from.col;
        long long r = ::std::abs(dr);
        long long c = ::std::abs(dc);
        res = c;
        if (r > c / 2)
        {
            res += r - c / 2;
            if (c % 2 == 1 && ((to.col % 2 == 0 && dr < 0) || (to.col % 2 == 1 && dr > 0)))
                res--;
        }
        return res;
    }
}