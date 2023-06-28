#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Point {
    public:
        int x;
        int y;
        Point(int x, int y) : x(x), y(y) {}

        Point operator+(Point p2) {
            Point p3(x + p2.x, y + p2.y);
            return p3;
        }
};


// Test in main()
int main() {
  Point p1(10, 5), p2(2, 4);
  Point p3 = p1 + p2; // An example call to "operator +";
  assert(p3.x == p1.x + p2.x);
  assert(p3.y == p1.y + p2.y);
}