template < typename T >
auto process(const T& container)
{
    typename T::value_type result{};
    auto it = container.rbegin();
    int i = 0;
    while (i != 5 && it != container.rend())
    {
        if (i % 2 == 0)
            result += *it;
        ++it;
        i++;
    }
    return result;
}