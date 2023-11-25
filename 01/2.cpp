#include <iostream>

class A 
{
    public:
    int a;
    A() 
    { 
        flag = false;
        std::cin >> a;
    }
    A(const A& _a) {
        flag = true;
        std::cin >> a;
        a += _a.a;
    }
    ~A() {
        if (flag)
            std::cout << a << std::endl;
    }

    private:
    bool flag;
};

/*int main() {
    A a, b(a);
}*/