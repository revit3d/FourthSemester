template < typename T, typename F >
T myfilter(const T& container, F predicate)
{
    T result{};
    for (auto elem : container)
        if (predicate(elem))
            result.insert(result.end(), elem);
    return result;
}