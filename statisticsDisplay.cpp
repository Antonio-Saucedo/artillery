#include "statisticsDisplay.h"

void StatisticsDisplay::updateStats(float altitude, float speed, float distance, long long hangTime)
{
	ogstream gout;
	gout.precision(1);

	Position drawPos = Position();
	drawPos.setPixelsX(550);
	drawPos.setPixelsY(450);

	gout.setPosition(drawPos);

	gout << "Altitude: " << altitude << "\n";
	gout << "Speed: " << speed << "\n";
	gout << "Distance: " << distance << "\n";
	gout << "Hang Time: " << hangTime << "\n";
}

//void StatisticsDisplay::render()
//{
//}