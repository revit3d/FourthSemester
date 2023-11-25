#include <iostream>
#include <string>

int main() {
    char c, last{0};
    int count{0};
    std::string s;
    while (!std::cin.eof()) 
    {
        c = std::cin.get();
        if (c == last) {
            s += c;
            last = c;
            count++;
        } 
        else 
        {    
            if (count > 4) 
            {
                std::cout << '#' << last << std::hex << count << '#';
                s = "";
                s += c;
                count = 1;
                last = c;
            } 
            else 
            {
                if (last == '#')
                    std::cout << "#" << last << std::hex << count << '#';
                else
                    std::cout << s;
                s = std::string("") + c;
                last = c;
                count = 1; 
            }
        }
    }
    return 0;
}