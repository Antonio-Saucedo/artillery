#include "statisticsDisplay.h"
#include <string>
#include <regex>

void StatisticsDisplay::updateStats(int altitude, int speed, int distance, double hangTime)
{
	this->altitude = altitude;
	this->speed = speed;
	this->distance = distance;
	int time = static_cast<int>(hangTime);
	this->hangTime = time;
}

void StatisticsDisplay::render()
{
	ogstream gout;
	gout.precision(1);

	int time = static_cast<int>(hangTime);

	Position drawPos = Position();
	drawPos.setPixelsX(550);
	drawPos.setPixelsY(450);

	gout.setPosition(drawPos);

	gout << "Altitude: " << altitude << "m\n";
	gout << "Speed: " << speed << "km/s\n";
	gout << "Distance: " << distance << "km\n";
	gout << "Hang Time: " << hangTime << "s\n";
}