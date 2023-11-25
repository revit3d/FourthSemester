#include <iostream>
#include <string>
#include <stack>

int main()
{
    char input;
    std::stack < std::string > st;
    std::string var1, var2;

    while (std::cin >> input)
    {
        if (input == '+' || input == '-' || input == '*' || input == '/')
        {
            var1 = st.top();
            st.pop();
            var2 = st.top();
            st.pop();
            st.push('(' + var2 + input + var1 + ')');
        }
        else
            st.push(std::string(1, input));
    }

    std::cout << st.top() << std::endl;

    return 0;
}