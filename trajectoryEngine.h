#pragma once
#include <iostream>
#include "position.h"
#include "velocity.h"

using namespace std;

class TrajectoryEngine {
private:
	float numDragCoefficients;
	float numAirDensities;
	float numSoundSpeeds;
	float numGravity;
	float dragCoefficients[numDragCoefficients];
	float airDensities[numAirDensities];
	float soundSpeeds[numSoundSpeeds];
	float gravity[numGravity];

public:
	// Constructor
	TrajectoryEngine();

	float get_linear_interpolated_result(float constants, float num_constants, float target, float result);
	float applyLI(float x1, float x2, float x3, float y1, float y3);
	float nextPosition(Position position, Velocity velocity, float time, float weight, float diameter);
};