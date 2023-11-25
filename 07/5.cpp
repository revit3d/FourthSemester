class Figure
{
public:
    virtual ~Figure() = default;

    virtual bool equals(const Figure* other) const = 0;
};

class Rectangle: public Figure
{
    int width_{}, height_{};

public:
    Rectangle(int width, int height): width_(width), height_(height) { };

    bool equals(const Figure* other) const override
    {
        if (other == nullptr)
            return false;
        const Rectangle* other_rect = dynamic_cast < const Rectangle* >(other);
        if (other_rect == nullptr)
            return false;
        return this->width_ == other_rect->width_ && this->height_ == other_rect->height_;
    }
};

class Triangle: public Figure
{
    int a_{}, b_{}, c_{};

public:
    Triangle(int a, int b, int c): a_(a), b_(b), c_(c) { }

    bool equals(const Figure* other) const override
    {
        if (other == nullptr)
            return false;
        const Triangle* other_trng = dynamic_cast < const Triangle* >(other);
        if (other_trng == nullptr)
            return false;
        return this->a_ == other_trng->a_ && this->b_ == other_trng->b_ && this->c_ == other_trng->c_;
    }
};