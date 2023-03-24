#pragma once
#include <iostream>
#include "position.h"
#include "velocity.h"
#include <vector>
#include <utility>

using namespace std;

class TrajectoryEngine {
private:
	double numDragCoefficients;
	double numAirDensities;
	double numSoundSpeeds;
	double numGravity;

	std::vector<std::pair<double, double>> dragCoefficients;
	std::vector<std::pair<double, double>> soundSpeeds;
	std::vector<std::pair<double, double>> airDensities;
	std::vector<std::pair<double, double>> gravityForces;

	double get_linear_interpolated_result(std::vector<std::pair<double, double>> data, double target);
	double applyLI(double x1, double x2, double x3, double y1, double y3);

public:
	// Constructor
	TrajectoryEngine();

	void nextPosition(Position& position, Velocity& velocity, double time, double diameter, double mass, double angle);


};