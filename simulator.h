/***********************************************************************
 * Header File:
 *    Simulator : The main simulation engine
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    This simulator will follow the input -> update -> output procedure
 ************************************************************************/
#pragma once

#include "howitzer.h"
#include "projectile.h"
#include "ground.h"
#include "statisticsDisplay.h"
#include "position.h"
#include "uiInteract.h"

#include <cstdlib>
#include <chrono>

class Simulator {
private:
	Howitzer howitzer;
	Projectile* projectile;
	Ground ground;
	Position ptUpperRight;
	double interval;
	//StatisticsDisplay sd;
	double elapsedTime;
	bool hitTarget;
	bool hitGround;

	void reset();
	void generate_stats();
	void isHitOnTarget();
	bool isPositionOnScreen(const Position& p);
	bool didProjectileHit();

public:
	Simulator(Position ptUpperRight) :
		projectile(NULL),
		ptUpperRight(ptUpperRight),
		ground(ptUpperRight),
		interval(1.0),
		//sd(),
		hitTarget(false),
		hitGround(false)
	{
		// Create the position for the howitzer
		Position ptHowitzer;
		// Set the x position to a random witdth in the screen width
		int width = (int)ptUpperRight.getPixelsX();
		ptHowitzer.setPixelsX(random((int)0, width - 1));
		// Reset the ground and give it the howitzers position
		// This will set the y position automatically
		ground.reset(ptHowitzer);
		// Create a howitzer with the position we made
		howitzer = Howitzer(ptHowitzer);
	};

	void input(const Interface* pUI);
	void update();
	void renderFrame();
};