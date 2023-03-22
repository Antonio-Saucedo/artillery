#include "statisticsDisplay.h"

void StatisticsDisplay::updateStats(int altitude, int speed, int distance, long long hangTime)
{
	ogstream gout;
	gout.precision(1);

	Position drawPos = Position();
	drawPos.setPixelsX(550);
	drawPos.setPixelsY(450);

	gout.setPosition(drawPos);

	gout << "Altitude: " << altitude << "m\n";
	gout << "Speed: " << speed << "km/s\n";
	gout << "Distance: " << distance << "km\n";
	gout << "Hang Time: " << hangTime << "ms\n";
}

//void StatisticsDisplay::render()
//{
//}