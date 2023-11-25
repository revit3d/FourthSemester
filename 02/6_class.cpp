#include <stdexcept>
#include <string>

class StringView
{
    size_t begin_;
    size_t count_;
    std::string& string_;

    public:
    StringView(std::string& _str, size_t _begin = 0, size_t _count = std::string::npos) : string_(_str)
    {
        this->begin_ = std::min(_begin, this->string_.size());
        this->count_ = std::min(_count, this->string_.size() - this->begin_);
    }

    StringView(const StringView& _sv, size_t _begin = 0, size_t _count = std::string::npos) : string_(_sv.get_str_ref())
    {
        size_t shifted_begin = _begin + _sv.get_begin_idx();

        this->begin_ = std::min(shifted_begin, this->string_.size());
        this->count_ = std::min(_count, _sv.size() - _begin);
    }

    size_t get_begin_idx() const { return this->begin_; }

    size_t size() const { return this->count_; }

    size_t length() const { return this->size(); }

    std::string& get_str_ref() const { return this->string_; }

    char& operator[] (size_t pos) { return this->string_[this->begin_ + pos]; }

    const char& operator[] (size_t pos) const { return this->string_[this->begin_ + pos]; }

    char& at(size_t pos) 
    {
        if (pos >= count_)
            throw std::out_of_range("StringView index out of range");
        return this->string_[this->begin_ + pos];
    }

    const char& at(size_t pos) const
    {
        if (pos >= count_)
            throw std::out_of_range("StringView index out of range");
        return this->string_[this->begin_ + pos];
    }

    std::string str(size_t _begin = 0, size_t _count = std::string::npos) const
    {
        size_t shifted_begin = std::min(this->begin_ + _begin, this->string_.size());
        size_t shifted_count = std::min(_count, this->count_ - _begin);
        return this->string_.substr(shifted_begin, shifted_count);
    }

    using iterator = std::string::iterator;
    using const_iterator = std::string::const_iterator;
    using reverse_iterator = std::string::reverse_iterator;
    using const_reverse_iterator = std::string::const_reverse_iterator;

    iterator begin() { return this->string_.begin() + this->begin_; }
    const_iterator cbegin() const { return this->string_.cbegin() + this->begin_; }

    iterator end() { return this->begin() + this->count_; }
    const_iterator cend() const { return this->cbegin() + this->count_; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator crbegin() const { return const_reverse_iterator(cend()); }

    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator crend() const { return const_reverse_iterator(cbegin()); }

    bool operator==(const StringView& other) const 
    {
        return this->size() == other.size() && this->string_.compare(this->begin_, this->size(), other.get_str_ref(), other.get_begin_idx(), other.size()) == 0;
    }
    bool operator!=(const StringView& other) const 
    {
        return !(*this == other);
    }
    bool operator<(const StringView& other) const 
    {
        return this->string_.compare(this->begin_, this->size(), other.get_str_ref(), other.get_begin_idx(), other.size()) < 0;
    }
    bool operator<=(const StringView& other) const 
    {
        return *this < other || *this == other;
    }
    bool operator>(const StringView& other) const 
    {
        return other < *this;
    }
    bool operator>=(const StringView& other) const 
    {
        return other < *this || other == *this;
    }

    // Disable assignment operator
    StringView& operator=(const StringView&) = delete;
};