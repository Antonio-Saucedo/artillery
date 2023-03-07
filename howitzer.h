#pragma once
/***********************************************************************
 * Header File:
 *    Point : The representation of a howitzer
 * Author:
 *    Nolan Thomas Vargas
 * Summary:
 *    
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include "projectile.h"

class TestHowitzer;

/*********************************************

 *********************************************/
class Howitzer
{
    friend TestHowitzer;
public:

    // constructors
    Howitzer();
    Howitzer(Position p) : point(p) {}

    void draw();
    bool isLoaded();
    float getMuzzleVelocity();
    void fire();
    void reload(Projectile p);
    void rotate(bool clockwise, bool isFastRotation);



private:
    float muzzleVelocity;
    int angle;
    bool loaded;
    float slowRotateSpeed;
    float fastRotateSpeed;
    Position point;
};