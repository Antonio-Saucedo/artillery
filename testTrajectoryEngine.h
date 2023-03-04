/***********************************************************************
 * Header File:
 *    Test Position : Test the TrajectoryEngine class
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    All the unit tests for TrajectoryEngine
 ************************************************************************/

#pragma once
#include "trajectoryEngine.h"
#include <cassert>

using namespace std;

class TestTrajectoryEngine
{
public:
	void run()
	{
		test_linearInterpolation_valid();
		test_linearInterpolation_outOfRange(); // Error: Out of range
		test_linearInterpolation_exactMatch();
	}

private:
	void test_linearInterpolation_valid()
	{
		// setup

		// exercise
		float y2 = TrajectoryEngine.applyLI(10, 15, 20, 1, 5);

		// verify
		assert(y2 == 3);

		// teardown
	}

	void test_linearInterpolation_outOfRange()
	{
		// setup

		// exercise
		float y2 = TrajectoryEngine.applyLI(10, 0, 20, 1, 5);

		// verify
		assert(y2 == nan);

		// teardown
	}

	void test_linearInterpolation_exactMatch()
	{
		// setup

		// exercise
		float y2 = TrajectoryEngine.applyLI(10, 10, 20, 1, 5);

		// verify
		assert(y2 == 1);

		// teardown
	}
};