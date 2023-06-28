/*
This file shows composition. The Circle class is composed of a Line class, the length of which 
defines the radius of the Circle. I.e. The Circle "has a" Line.
*/

#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
#define PI 3.1415

using namespace std;

// Define Line Class
class LineSegment {
    public:
        double length;
        double GetLength() {
            return length;
        }
};
    
// Define Circle subclass
class Circle {
    private:
        LineSegment radius_;
    // Define public setRadius() and Area()
    public:
        Circle(LineSegment radius) {
            radius_ = radius;
        }

        double Area() { return PI * pow(radius_.length, 2); }
};
// Test in main()
int main() 
{
    LineSegment radius {3}; // default constructor initializes public member variables in order given this initializer list
    cout << radius.GetLength() << endl;
    Circle circle(radius);
    assert(int(circle.Area()) == 28);
}