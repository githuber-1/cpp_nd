#include <iostream>

using namespace std;

// Define base class Animal
class Animal {

};

// Declare derived class Snake
class Snake : public Animal {
    public:
        int length{1};
        void MakeSound() { cout << "hiss\n"; }
};

// Declare derived class Cat
class Cat : public Animal {
    public:
        int height{1};
        void MakeSound() { cout << "meow\n "; }
};

// Test in main()
int main() {
    Snake snake;
    Cat cat;

    snake.MakeSound();
    cat.MakeSound();

    return 0;
}