#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    bool lights = false;
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels! ";
        if (lights) {
            std::cout << "and no lights";
        }
        else {
            std::cout << "and lights!\n";
        }
    }
};

class Car : public Vehicle {
    public:
        bool sunroof = false;
};

class Bicycle : public Vehicle {
    public:
        bool kickstand = true;
};

class Helicopter : public Vehicle {
    public:
        int rotor_blades = 4;

        void Print() const {
            Vehicle::Print();
            std::cout << "This helicopter has " << rotor_blades << " rotor blades";
        }
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";
    Helicopter heli;
    heli.Print();
};