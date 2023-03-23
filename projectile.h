/***********************************************************************
 * Header File:
 *    Projectile : The representation of a projectile
 * Author:
 *    Antonio Saucedo Godinez, Nolan Thomas Vargas
 * Summary:
 *    A Projectile class represents an object launched into the air, 
 *    moving along a parabolic trajectory. It includes properties like 
 *    initial velocity and mass
 ************************************************************************/
#pragma once

#include "position.h"
#include "velocity.h"
#include "trajectoryEngine.h"
#include "uiDraw.h"
#include "angle.h"

#include <iostream>
#include <list>

using namespace std;

class TestProjectile;

class Projectile {
	friend TestProjectile;
private:
	Position current;
	list<Position> previous;
	double weight ;
	//double radious;
	double diameter;
	Velocity velocity;
	bool airborne;
	TrajectoryEngine te;
	double angle;

public:
	// Constructor
	Projectile() {};

	Projectile(Position p, Velocity v, double a, double d, double m) : 
		current{ p }, velocity{ v }, angle{ a }, diameter{ d }, weight{ m }, airborne(true) {};

	const list<Position>& getPreviousPoints() const {return previous;}	
	void updatePoint(double interval);
	Position getCurrentPoint() { return current; };
	bool isAirborne() { return airborne; };
	void hit() { airborne = false; };
	double getSpeed() { return velocity.getSpeed(); };
	void draw(ogstream& o, double age);
	void drawTrail(ogstream& o);
	double getAngle() { return angle; };
};