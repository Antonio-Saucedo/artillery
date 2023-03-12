/***********************************************************************
 * Header File:
 *    Test Position : Test the Howitzer class
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/

#pragma once

#include <iostream>
#include "howitzer.h"
#include "position.h"
#include <cassert>

using namespace std;

class TestHowitzer
{
public:
	void run()
	{
		void test_isLoaded_functional();
		void test_getMuzzleVelocity_functional();
		void test_fire_notLoaded();
		void test_fire_loaded();
		void test_rotate_slow();
		void test_rotate_fast();
		void test_rotate_counterClockwise();
		void test_getPosition();

		cout << "Howitzer Tests Passed\n";
	}

private:
	void test_isLoaded_functional()
	{
		// setup
		Howitzer h;
		h.loaded = true;
		// exercise
		assert(h.isLoaded() == true);
	}

	void test_getMuzzleVelocity_functional()
	{
		// setup
		Howitzer h;
		h.muzzleVelocity = 847;
		// exercise
		assert(h.getMuzzleVelocity() == 847);
	}

	void test_fire_notLoaded()
	{
		// setup
		Howitzer h;
		h.loaded = false;
		// exercise
		h.fire();
		// verify
		assert(h.isLoaded() == false);
	}

	void test_fire_loaded()
	{
		// setup
		Howitzer h;
		h.loaded = true;
		// exercise
		h.fire();
		// verify
		assert(h.isLoaded() == false);
	}

	void test_rotate_slow()
	{
		// setup
		Howitzer h;
		h.slowRotateSpeed = 5;
		h.angle = 0;
		// exercise
		h.rotate(true, false);
		// verify
		assert(h.angle == 5);
	}

	void test_rotate_fast()
	{
		// setup
		Howitzer h;
		h.fastRotateSpeed = 15;
		h.angle = 0;
		// exercise
		h.rotate(true, true);
		// verify
		assert(h.angle == 15);
	}

	void test_rotate_counterClockwise()
	{
		// setup
		Howitzer h;
		h.fastRotateSpeed = 15;
		h.angle = 0;
		// exercise
		h.rotate(true, true);
		// verify
		assert(h.angle == -15);
	}

	void test_getPosition()
	{
		// setup
		Howitzer h;
		// exercise
		h.location = Position(0,0);
		// verify
		assert(h.location.getMetersX() == 0);
		assert(h.location.getMetersY() == 0);
	}
};