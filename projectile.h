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
#include <iostream>
#include <list>
#include "position.h"
#include "velocity.h"
#include "trajectoryEngine.h"

using namespace std;

class TestProjectile;

class Projectile {
	friend TestProjectile;
private:
	Position current;
	list<Position> previous;
	float weight;
	float radious;
	float diameter;
	Velocity velocity;
	bool airborne;
	TrajectoryEngine te;

public:
	// Constructor
	Projectile();

	list<Position> getPreviousPoints();
	void updatePoint(float interval);
	Position getCurrentPoint();
	bool isAirborne();
	bool hit();
	float getSpeed();
};