class Sum 
{
    long long a;
    long long b;

    public:
    Sum(const long long _a, const long long _b): a(_a), b(_b) { }
    Sum(Sum _a, const long long _b): a(_a.get()), b(_b) { }
    const long long get() const {
        return a + b;
    }
};