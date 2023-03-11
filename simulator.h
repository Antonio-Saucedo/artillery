///***********************************************************************
// * Header File:
// *    Simulator : The main simulation engine
// * Author:
// *    Antonio Saucedo, Thomas Vargas
// * Summary:
// *    This simulator will follow the input -> update -> output procedure
// ************************************************************************/
//#pragma once
//
//#include "howitzer.h"
//#include "projectile.h"
//#include "ground.h"
//#include "statisticsDisplay.h"
//#include "position.h"
//#include "uiInteract.h"
//
//#include <chrono>
//
//class Simulator {
//private:
//	Howitzer howitzer;
//	Projectile projectile;
//	Ground ground;
//	Position ptUpperRight;
//	float interval;
//	StatisticsDisplay sd;
//	const std::chrono::time_point<std::chrono::steady_clock> timeOfFire;
//	bool hitTarget;
//	bool hitGround;
//
//	void reset();
//	void generate_stats();
//	void isHitOnTarget();
//
//public:
//	Simulator(Position ptUpperRight) :
//		howitzer(ptUpperRight),
//		projectile(howitzer.getPosition()),
//		ground(ptUpperRight),
//		ptUpperRight(ptUpperRight),
//		interval(1.0),
//		sd(),
//		timeOfFire(std::chrono::steady_clock::now()),
//		hitTarget(false),
//		hitGround(false)
//	{
//		ptUpperRight.setPixelsX(Position(ptUpperRight).getPixelsX());
//
//		ground.reset(ptUpperRight);
//	};
//
//	void input(const Interface* pUI);
//	void update(const Interface* pUI);
//	void renderFrame(ogstream& gout);
//};