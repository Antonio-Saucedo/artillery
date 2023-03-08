/***********************************************************************
 * Header File:
 *   Velocity
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    A velocity vector
 ************************************************************************/
#pragma once

#include <cmath>


class Velocity {
public:
    // Class fields and methods go here
    Velocity() {};
    Velocity(double dx, double dy) : dy{ dy }, dx{ dx } {};
    double getSpeed() { return std::sqrt(dx * dx + dy * dy);};

private:
    double dx;
    double dy;
};