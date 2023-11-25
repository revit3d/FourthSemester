#include <iostream>

class S
{
    int data = 0;
    int flag;

public:
    S() 
    {
        if (std::cin >> data)
            flag = 1;
        else
            flag = 0;
    }

    S(S &&prev)
    {
        if (std::cin >> data)
            flag = 1;
        else
            flag = 2;
        data += prev.data;
        prev.flag = 0;
    }
    
    operator bool() const { return flag == 1; }

    ~S() 
    {
        if (flag == 2)
            std::cout << data << std::endl;
    }
};