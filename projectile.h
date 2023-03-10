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
	float weight;
	float radious;
	float diameter;
	Velocity velocity;
	bool airborne;
	TrajectoryEngine te;
	float angle;

public:
	// Constructor
	Projectile() {
		diameter = 0.15489f;
		weight = 46.7;
	};
	Projectile(Position p, Velocity v, float a, float d, float m) : current{ p }, velocity{ v }, angle{ a }, diameter{ d }, weight{m} {};

	const list<Position>& getPreviousPoints() const {return previous;}	
	void updatePoint(float interval);
	Position getCurrentPoint() { return current; };
	bool isAirborne() { return airborne; };
	void hit() { airborne = false; };
	float getSpeed() { return velocity.getSpeed(); };
	void draw(ogstream o, double age);
};