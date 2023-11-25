#include <array>

class Matrix
{
    std::array < std::array < int, 3 >, 3 > matrix;

    public:
    Matrix()
    {
        for (int i = 0; i < 3; i++)
            matrix[i].fill(0);
    }

    int& operator[](int i, int j) { return matrix[i][j]; }

    auto begin() const { return matrix.begin(); }

    auto end() const { return matrix.end(); }
};