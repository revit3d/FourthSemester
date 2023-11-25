#include <iostream>

/*
S -> aSd | aAd
A -> bAc | bc
*/

void A(int m)
{
    std::cout << "b";
    if (m > 1)
        A(m - 1);
    std::cout << "c";
}

void S(int k, int n)
{
    std::cout << "a";
    if (n > 1)
        S(k - 2, n - 1);
    else
        A(k / 2 - 1);
    std::cout << "d";
}

int main()
{
    int k;
    std::cin >> k;
    if (!(k & 1))
        for (int n = k / 2 - 1; n > 0; --n)
        {
            S(k, n);
            std::cout << "\n";
        }
}