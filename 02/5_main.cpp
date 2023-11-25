#include "5.cpp"
#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    BinaryNumber num(s);
    std::cout << std::string(num) << std::endl;
    ++num;
    std::cout << std::string(num) << std::endl;

    return 0;
}