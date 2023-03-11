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
    double getDx() { return dx; }
    double getDy() { return dy; }
    void setDx(float dx) { this->dx = dx; }
    void setDy(float dy) { this->dy = dy; }

private:
    double dx;
    double dy;
};