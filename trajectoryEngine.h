#pragma once
#include <iostream>
#include "position.h"
#include "velocity.h"
#include <vector>
#include <utility>

using namespace std;

class TrajectoryEngine {
private:
	float numDragCoefficients;
	float numAirDensities;
	float numSoundSpeeds;
	float numGravity;

	std::vector<std::pair<float, float>> dragCoefficients;
	std::vector<std::pair<float, float>> soundSpeeds;
	std::vector<std::pair<float, float>> airDensities;
	std::vector<std::pair<float, float>> gravityForces;

	float get_linear_interpolated_result(std::vector<std::pair<float, float>> data, float target);
	float applyLI(float x1, float x2, float x3, float y1, float y3);

public:
	// Constructor
	TrajectoryEngine();

	float nextPosition(Position& position, Velocity& velocity, float time, float weight, float diameter, float mass, int angle);


};