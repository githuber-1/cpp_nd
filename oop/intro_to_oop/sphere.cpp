#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere {
    public:
    // Constructor
    Sphere(int r) {
        SetRadius(r);
    }

    // Accessors
    float Radius() {
        return radius_;
    }

    float Volume() {
        float volume =  (4.0 / 3.0) * M_PI * std::pow(radius_, 3);
        std::cout << volume << std::endl;
        return volume;
    }

    // Mutator
    void SetRadius(int r) {
        if (r < 0) {
            throw std::invalid_argument("Radius must be >= 0");
        }
        radius_ = r;
    }

    private:
    // Private members
    int radius_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
}