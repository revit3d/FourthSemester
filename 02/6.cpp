#include <iostream>
#include "6_class.cpp"

using namespace std;

int main()
{
    std::string str("FUCK ASCII");
    StringView st(str, 2, 8);
    st[1] = 'O';
    auto it = st.cbegin();
    while (it != st.end())
    {
        cout << it[0];
        it++;
    }
    cout << endl;
    cout << st.length() << " " << st.get_begin_idx() << endl;
    cout << st.str(10, 6) << endl;
    cout << (st > StringView(str, 2)) << endl;
    cout << st.end()[-1] << endl;

    return 0;
}