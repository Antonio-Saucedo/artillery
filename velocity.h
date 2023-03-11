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
    Velocity() { dx = 0; dy = 0; }
    Velocity(float dx, float dy) : dy{ dy }, dx{ dx } {};
    float getSpeed() { return std::sqrt(dx * dx + dy * dy);};
    float getDx() { return dx; }
    float getDy() { return dy; }
    void setDx(float dx) { this->dx = dx; }
    void setDy(float dy) { this->dy = dy; }

private:
    float dx;
    float dy;
};