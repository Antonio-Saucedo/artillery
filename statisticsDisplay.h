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
	float altitude;
	float speed;
	float distance;
	long long hangTime;
	Position point;

public:
	StatisticsDisplay() {
		altitude = 0.0f;
		speed = 0.0f;
		distance = 0.0f;
		hangTime = (long long) 0.0;
		point = Position();
	}
	void updateStats(float altitude, float speed, float distance, long long hangTime);
	//void render();
};