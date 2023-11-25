class C
{
    public:
    C(const C, const C) {}

    C(double value) {}

    C() {}

    C operator~() const
    {
        return 0;
    }
    
    C operator++() const
    {
        return *this;
    }

    int operator*(const C arr[2])
    {
        return 0;
    }

    operator int()
    {
        return 0;
    }

    C operator&() const
    {
        return *this;
    }
};

C operator+(int left, const C& right)
{
    return right;
}