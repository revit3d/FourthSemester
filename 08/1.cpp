#include <iostream>
#include <string>

class Input
{
    std::string data;
public:
    Input(const std::string& _data): data(_data) { }
    ~Input() {
        std::cout << data << std::endl;
    }
};

void read_input()
{
    std::string data;
    if (std::cin >> data)
    {
        Input tmp(data);
        try 
        {
            read_input();
        } 
        catch (const int ex) 
        {
            throw ex;
        }
    }
    else  
        throw 1;
}

int main()
{
    try 
    {
        read_input();
    } 
    catch (const int ex) { }

    return 0;
}