#include "simulator.h"
#include "statisticsDisplay.h"
#include "howitzer.h"


#include <chrono>

void Simulator::reset()
{
}

//void Simulator::generate_stats()
//{
//	const std::chrono::time_point<std::chrono::steady_clock> elapsedTime = std::chrono::steady_clock::now() - timeOfFire;
//
//	StatisticsDisplay.updateStats(ground.getElevationMeters(projectile.getCurrentPoint(),
//		projectile.getSpeed(), abs(howitzer.getPoint().getX()) - projectile.getCurrentPoint().getX()),
//		elapsedTime;
//}

//void Simulator::isHitOnTarget()
//{
//    if (ground.getTarget() == projectile.getCurrentPoint()) {
//        hitTarget = true;
//    } else {
//        hitGround = true;
//    }
//}

void Simulator::input(const Interface* pUI)
{
    // move a large amount
    if (pUI->isRight())
        howitzer.rotate(true, true);
    if (pUI->isLeft())
        howitzer.rotate(false, true);

    // move by a little
    if (pUI->isUp())
        if (howitzer.getAngle() > 0)
            howitzer.rotate(false, false);
        else
            howitzer.rotate(true, false);
    if (pUI->isDown())
        if (howitzer.getAngle() > 0)
            howitzer.rotate(true, false);
        else
            howitzer.rotate(false, false);

    // fire that gun
    if (pUI->isSpace()) {
        projectile = howitzer.fire();
        elapsedTime = -1;
    }

}

void Simulator::update()
{
    //projectile.updatePoint(interval);
    elapsedTime += 1;
}

void Simulator::renderFrame()
{
    ogstream gout;
    ground.draw(gout);
    howitzer.draw(gout, elapsedTime);
    
}