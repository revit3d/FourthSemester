#include <iostream>
#include <cstdint>

class Result 
{
public:
    int64_t data;
    Result(int64_t x): data(x) { }
};

void func(int64_t a, int64_t b, int64_t k)
{
    //function calculating Ackermann function value
    if (k == 0)
        throw Result(a + b);
    else if (k > 0 && b == 1)
        throw Result(a);
    else if (k > 0 && b > 1)
    {
        try { func(a, b - 1, k); }
        catch (const Result& res_b) 
        { 
            try { func(a, res_b.data, k - 1); }
            catch (const Result& ret) { throw ret; }
        }
    }
}

int main()
{
    int64_t a, b, k;
    while (std::cin >> a >> b >> k)
    {
        try { func(a, b, k); }
        catch (const Result& res) { std::cout << res.data << std::endl; }
    }

    return 0;
}