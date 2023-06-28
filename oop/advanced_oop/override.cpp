#include <assert.h>
#include <cmath>

// http://www.cs.cmu.edu/~motionplanning/reading/PlanningforDynamicVeh-1.pdf

// TODO: Define PI
#define PI 3.1415

// TODO: Declare abstract class VehicleModel
class VehicleModel {
    // TODO: Declare virtual function Move()
    public:
        virtual void Move(double v, double phi) = 0;
};

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : VehicleModel {
    // TODO: Override the Move() function
    public:
        void Move(double v, double phi) override {
            theta += phi;
            x += sin(theta) * v;
            y += cos(theta) * v;
        }

        // TODO: Define x, y, and theta
        double x = 0;
        double y = 0;
        double theta = 0;
};

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel {
    public:
        // TODO: Override the Move() function
        void Move(double v, double phi) override {
            theta += v / l * tan(phi);
            x += v * cos(theta);
            y += v * cos(theta);
        }

        // TODO: Define L
        double l;
};


// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}