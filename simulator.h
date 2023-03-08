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

#include <chrono>

class Simulator {
private:
	Howitzer howitzer;
	Projectile projectile;
	Ground ground;
	float interval;
	StatisticsDisplay sd;
	std::chrono::high_resolution_clock::time_point timeOfFire;
	
	void reset();
	void generate_stats();
	void isHitonTarget();

public:
	Simulator(const Position& ptUpperRight) {}
	void input(const Interface* pUI);
	void update();
	void renderFrame();


};