#include <iostream>

enum PRIORITY_LEVELS
{ 
    MAX_PRIOR = 1,
    MULT_PRIOR,
    SUM_PRIOR,
    AND_PRIOR,
    XOR_PRIOR,
    OR_PRIOR,
    MIN_PRIOR,
};

using priority_t = int;
using state = std::pair < std::string, priority_t >;

state A(char& ch);

priority_t get_priority(const char& op)
{
    if (op == '*' || op == '/')
        return PRIORITY_LEVELS::MULT_PRIOR;
    if (op == '+' || op == '-')
        return PRIORITY_LEVELS::SUM_PRIOR;
    if (op == '&')
        return PRIORITY_LEVELS::AND_PRIOR;
    if (op == '^')
        return PRIORITY_LEVELS::XOR_PRIOR;
    if (op == '|')
        return PRIORITY_LEVELS::OR_PRIOR;
    return PRIORITY_LEVELS::MIN_PRIOR;
}

state F(priority_t pos, char& ch)
{
    priority_t priority = PRIORITY_LEVELS::MAX_PRIOR;
    std::string s;
    if (ch == '(') 
    {
        std::cin >> ch;
        auto tmp = A(ch);
        std::cin >> ch;
        if (pos <= tmp.second || tmp.second > get_priority(ch))
            s += "(" + tmp.first + ")";
        else 
        {
            s += tmp.first;
            priority = tmp.second;
        }
    } 
    else 
    {
        s += ch;
        std::cin >> ch;
    }
    return std::make_pair(s, priority);
}

state E(priority_t pos, char& ch)
{
    priority_t priority = PRIORITY_LEVELS::MULT_PRIOR;
    std::string s;
    auto tmp = F(pos, ch);
    s += tmp.first;
    priority_t val = tmp.second;
    while (ch == '*' || ch == '/') 
    {
        s += ch;
        std::cin >> ch;
        tmp = F(priority, ch);
        s += tmp.first;
        val = priority;
    }
    return std::make_pair(s, val);
}

state D(priority_t pos, char& ch)
{
    priority_t priority = PRIORITY_LEVELS::SUM_PRIOR;
    std::string s;
    auto tmp = E(pos, ch);
    s += tmp.first;
    priority_t val = tmp.second;
    while (ch == '+' || ch == '-') {
        s += ch;
        std::cin >> ch;
        tmp = E(priority, ch);
        s += tmp.first;
        val = priority;
    }
    return state(s, val);
}

state C(priority_t pos, char& ch)
{
    priority_t priority = PRIORITY_LEVELS::AND_PRIOR;
    std::string s;
    auto tmp = D(pos, ch);
    s += tmp.first;
    priority_t val = tmp.second;
    while (ch == '&') 
    {
        s += ch;
        std::cin >> ch;
        tmp = D(priority, ch);
        s += tmp.first;
        val = priority;
    }
    return state(s, val);
}

state B(priority_t pos, char& ch)
{
    priority_t priority = PRIORITY_LEVELS::XOR_PRIOR;
    std::string s;
    auto tmp = C(pos, ch);
    s += tmp.first;
    priority_t val = tmp.second;
    while (ch == '^') 
    {
        s += ch;
        std::cin >> ch;
        tmp = C(priority, ch);
        s += tmp.first;
        val = priority;
    }
    return state(s, val);
}

state A(char& ch)
{
    priority_t priority = PRIORITY_LEVELS::OR_PRIOR;
    std::string s;
    auto tmp = B(PRIORITY_LEVELS::MIN_PRIOR, ch);
    s += tmp.first;
    priority_t val = tmp.second;
    while (ch == '|') 
    {
        s += ch;
        std::cin >> ch;
        tmp = B(priority, ch);
        s += tmp.first;
        val = priority;
    }
    return state(s, val);
}


int main()
{
    char ch;
    std::cin >> ch;
    std::cout << A(ch).first << std::endl;

    return 0;
}