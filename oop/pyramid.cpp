#include <cassert>
#include <stdexcept>
#include <iostream>

using namespace std;

class Pyramid {
    int length_{1};
    int width_{1};
    int height_{1};
    void Validate() {
        if (length_ <= 0 || width_ <= 0 || height_ <= 0) {
            throw std::invalid_argument("negative dimension");
        }
    }

    public:
        // constructor
        Pyramid(int l, int w, int h) {
            Length(l);
            Width(w);
            Height(h);
        }

        // accessors
        int Length() const {
            return length_;
        }
        int Width() const {
            return width_;
        }
        int Height() const {
            return height_;
        }

        // mutators
        void Length(int l) {
            length_ = l;
            Validate();
        }
        void Width(int w) {
            width_ = w;
            Validate();
        }
        void Height(int h) {
            height_ = h;
            Validate();
        }

        float Volume() const {
            return ( Length() * Width() * Height() ) / 3;
        }


};

// Test
int main() {
  Pyramid pyramid(4, 5, 6);
  assert(pyramid.Length() == 4);
  assert(pyramid.Width() == 5);
  assert(pyramid.Height() == 6);
  assert(pyramid.Volume() == 40);

  bool caught{false};
  try {
    Pyramid invalid(-1, 2, 3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}