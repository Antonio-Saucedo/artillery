#pragma once
#include <iostream>
#include <vector>
#include "position.h"
#include "velocity.h"
#include "trajectoryEngine.h"

using namespace std;

class Projectile {
private:
	Position current;
	Position previous[10];
	float weight;
	float radious;
	float diameter;
	Velocity velocity;
	bool airborne;
	TrajectoryEngine te;

public:
	// Constructor
	Projectile();

	Point getPreviousPoints();
	void updatePoint(float interval);
	Point getCurrentPoint();
	bool isAirborne();
	bool hit();
	float getSpeed();
};