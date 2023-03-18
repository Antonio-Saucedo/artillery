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
    Howitzer() {location = Position( 100,100 ); }; //bandaid code
    Howitzer(Position p) {
        slowRotateSpeed = 0.0017;
        fastRotateSpeed = 0.0286;
        location = p;
    }

    void draw(ogstream& o, double age) { o.drawHowitzer(location, angle, age); };
    bool isLoaded() { return loaded; };
    double getMuzzleVelocity() { return muzzleVelocity; };
    Projectile fire(); //create a new projectile here and set loaded to false
    void rotate(bool clockwise, bool isFastRotation);
    Position getPosition() { return location; };
    double getAngle() { return angle; }



private:
    static double muzzleVelocity;
    double angle;
    bool loaded;
    double slowRotateSpeed;
    double fastRotateSpeed;
    Position location;
};