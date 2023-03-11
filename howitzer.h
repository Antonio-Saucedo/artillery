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
#include "uiDraw.h"

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

    void draw(ogstream o, float age) { o.drawHowitzer(point, angle, age); };
    bool isLoaded() { return loaded; };
    float getMuzzleVelocity() { return muzzleVelocity; };
    void fire(); //create a new projectile here and set loaded to false
    void rotate(bool clockwise, bool isFastRotation);



private:
    float muzzleVelocity;
    int angle;
    bool loaded;
    float slowRotateSpeed;
    float fastRotateSpeed;
    Position point;
};