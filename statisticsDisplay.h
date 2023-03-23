/***********************************************************************
 * Header File:
 *    Statistics Display : Displays projectile statistics
 * Author:
 *    Antonio Saucedo, Thomas Vargas
 * Summary:
 *    Statistics Display will display the projectile statistics
 ************************************************************************/
#pragma once

#include "position.h"
#include "uiDraw.h"

#include <chrono>

class StatisticsDisplay {
private:
	int altitude;
	int speed;
	int distance;
	long long hangTime;
	Position point;

public:
	StatisticsDisplay() {
		altitude = 0;
		speed = 0;
		distance = 0;
		hangTime = (long long) 0.0;
		point = Position();
	}
	void updateStats(int altitude, int speed, int distance, long long hangTime);
	//void render();
};