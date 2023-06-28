/*
This file shows how Friend classes work in C++. Note that the main distinguishing factor b/w
Friend inheritance and Classic Inheritance is that Friends can access Private members of 
eachother, whereas Classic Inheritance only allows Public and Protected member access. 
*/

#include <assert.h>

class Square {
    private:
        int side_;
        friend class Rectangle; // Must declare Friend Class

    public:
        Square(int side) {
            side_ = side;
        }

};

class Rectangle {
    private:
        int width_;
        int height_;
        friend class Square; // Base class must declare Friend

    public: 
        Rectangle(Square a) {
            width_ = a.side_; // since the classes are friends, Rectangle can access
            height_ = a.side_; // private member data of Square
        }

        int Area() {
            return width_ * height_;
        }
};

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}