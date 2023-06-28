#include <assert.h>
#include <cmath>

// Define pi
#define PI 3.1415

// Define the abstract class Shape
class Shape {
    // Define public virtual functions Area() and Perimeter()
    public:
        virtual float Area() const = 0;
        virtual float Perimeter() const = 0;

};
  
// Define Rectangle to inherit publicly from Shape
class Rectangle {
    // Declare public constructor
    public:
        Rectangle(float height, float width) : height_(height), width_(width) {}
  // Override virtual base class functions Area() and Perimeter()
        float Area() { return height_ * width_; }
        float Perimeter() { return (height_ * 2) + (width_ * 2); } 
  // Declare private attributes width and height
    private:
        float height_;
        float width_;
};

class Circle {
    // Declare public constructor
    public:
        Circle(float radius) : radius_(radius) {}
  // Override virtual base class functions Area() and Perimeter()
        float Area() { return PI * pow(radius_, 2); }
        float Perimeter() { return 2 * PI * radius_; } 
  // Declare private attribute radius
    private:
        float radius_;
}; 

// Test in main()
int main() {
  float epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}