
class TestProjectile;

class Velocity {
    friend TestProjectile;
public:
    // Class fields and methods go here
    Velocity(double x, double y) : y{ y }, x{x} {}

private:
    double x;
    double y;
};