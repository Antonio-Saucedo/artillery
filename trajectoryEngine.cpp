#include "trajectoryEngine.h"
#include "position.h"
#include "velocity.h"

#include <utility>
#include <cmath>
#include <vector>

TrajectoryEngine::TrajectoryEngine()
{
	dragCoefficients = {
			{0.300, 0.1629},
			{0.500, 0.1659},
			{0.700, 0.2031},
			{0.890, 0.2597},
			{0.920, 0.3010},
			{0.960, 0.3287},
			{0.980, 0.4002},
			{1.000, 0.4258},
			{1.020, 0.4335},
			{1.060, 0.4483},
			{1.240, 0.4064},
			{1.530, 0.3663},
			{1.990, 0.2897},
			{2.870, 0.2297},
			{2.890, 0.2306},
			{5.000, 0.2656}
	};

	airDensities = {
		{0, 1.225},
		{1000, 1.112},
		{2000, 1.007},
		{3000, 0.9093},
		{4000, 0.8194},
		{5000, 0.7364},
		{6000, 0.6601},
		{7000, 0.59},
		{8000, 0.5258},
		{9000, 0.4671},
		{10000, 0.4135},
		{15000, 0.1948},
		{20000, 0.08891},
		{25000, 0.04008},
		{30000, 0.01841},
		{40000, 0.003996},
		{50000, 0.001027},
		{60000, 0.0003097},
		{70000, 0.0000828}
	};

	soundSpeeds = {
		{0, 340},
		{1000, 336},
		{2000, 332},
		{3000, 328},
		{4000, 324},
		{5000, 320},
		{6000, 316},
		{7000, 312},
		{8000, 308},
		{9000, 303},
		{10000, 299},
		{15000, 295},
		{20000, 295},
		{25000, 295},
		{30000, 305},
		{40000, 324}
	};

	gravityForces = {
		{0.0, 9.807},
		{1000.0, 9.804},
		{2000.0, 9.801},
		{3000.0, 9.797},
		{4000.0, 9.794},
		{5000.0, 9.791},
		{6000.0, 9.788},
		{7000.0, 9.785},
		{8000.0, 9.782},
		{9000.0, 9.779},
		{10000.0, 9.776},
		{15000.0, 9.761},
		{20000.0, 9.745},
		{25000.0, 9.730},
		{30000.0, 9.715},
		{40000.0, 9.684},
		{50000.0, 9.654},
		{60000.0, 9.625},
		{70000.0, 9.596},
		{80000.0, 9.568}
	};

	numDragCoefficients = 16;
	numAirDensities = 19;
	numSoundSpeeds = 16;
	numGravity = 20;
};


void TrajectoryEngine::nextPosition(Position& position, 
									Velocity& velocity, 
									float time, 
									float weight, 
									float diameter,
									float mass,
									float angle) {

	float radius = diameter / 2;
	float area = 3.14159f * radius * radius;
	float altitude = (float) position.getMetersY();
	float airDenisty = get_linear_interpolated_result(airDensities, altitude);
	float soundSpeed = get_linear_interpolated_result(soundSpeeds, altitude);
	float mach = (float) velocity.getSpeed() / soundSpeed;
	float dragCoefficient = get_linear_interpolated_result(dragCoefficients, mach);
	float dragForce = (float) (dragCoefficient * airDenisty * velocity.getSpeed() * velocity.getSpeed() * area);
	float gravity = -get_linear_interpolated_result(gravityForces, altitude);

	float newtons = dragForce / mass;
	float ddx = -(sin(angle) * newtons);
	float ddy = gravity - sin(angle) * newtons;

	position.setMetersX(position.getMetersX() + (velocity.getDx() * time) + (0.5 * ddx * (time * time)));
	position.setMetersY(position.getMetersY() + (velocity.getDy() * time) + (0.5 * ddy * (time * time)));

	velocity.setDx(((float) velocity.getDx()) + (ddx * time));
	velocity.setDy(((float) velocity.getDy()) + (ddy * time));

}

float TrajectoryEngine::get_linear_interpolated_result(std::vector<std::pair<float, float>> data, float target) {

	if ((target < data[0].first) || (target > data[data.size() - 1].first)) {
		throw std::invalid_argument("Target is past minimum or maximum range");
	}

	for (auto& x : data) {
		if (target == x.first) {
			return x.second;
		}

		// initialize previous pair to the first pair in the vector
		std::pair<float, float> prevPair = data.front();

		if (!(target > x.first)) {
			float y1 = prevPair.second;
			float x3 = x.first;
			float x1 = prevPair.first;
			float y3 = x.second;
			return applyLI(x1, target, x3, y1, y3);
		}
		prevPair = x;
	}

	throw std::logic_error("Should not have reached here");
}



float TrajectoryEngine::applyLI(float x1, float x2, float x3, float y1, float y3) {
	float y2 = (((x2 - x3) * (y3 - y1)) / (x1 - x3)) + y1;
	return y2;
}



