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
    Howitzer(Position p) : location(p) {
        slowRotateSpeed = 0.17;
        fastRotateSpeed = 2.86;
    }

    void draw(ogstream o, float age) { o.drawHowitzer(location, angle, age); };
    bool isLoaded() { return loaded; };
    float getMuzzleVelocity() { return muzzleVelocity; };
    Projectile fire(); //create a new projectile here and set loaded to false
    void rotate(bool clockwise, bool isFastRotation);



private:
    static int muzzleVelocity;
    float angle;
    bool loaded;
    float slowRotateSpeed;
    float fastRotateSpeed;
    Position location;
};