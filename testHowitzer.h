/***********************************************************************
 * Header File:
 *    Test Position : Test the Howitzer class
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    All the unit tests for Howitzer
 ************************************************************************/

#pragma once
#include <cassert>
#include "howitzer.h"


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
		void test_reload_noAmmo();
		void test_rotate_slow();
		void test_rotate_fast();
		void test_rotate_counterClockwise();
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
		assert(h.loaded = false);
	}

	void test_fire_loaded()
	{
		// setup
		Howitzer h;
		h.loaded = true;
		// exercise
		h.fire();
		// verify
		assert(h.loaded = false);
	}

	void test_reload_noAmmo()
	{
		// setup
		Howitzer h;
		h.loaded = false;
		// exercise
		h.reload(Projectile());
		// verify
		assert(h.loaded = true);
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
		assert(h.angle = 5);
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
		assert(h.angle = 15);
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
		assert(h.angle = -15);
	}
};