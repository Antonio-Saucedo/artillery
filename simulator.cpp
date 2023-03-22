#include "simulator.h"
#include "statisticsDisplay.h"
#include "howitzer.h"


#include <memory>
#include <chrono>

void Simulator::reset()
{
}

void Simulator::generate_stats()
{
    if (projectile != NULL) {
        std::chrono::time_point<std::chrono::steady_clock> endTime = std::chrono::steady_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - timeOfFire).count();

        sd.updateStats(ground.getElevationMeters(projectile->getCurrentPoint()), projectile->getSpeed(),
            howitzer.getPosition().getMetersX() - projectile->getCurrentPoint().getMetersX(), elapsedTime);
    }
    else {
        sd.updateStats(0.0f, 0.0f, 0.0f, (long long)0.0);
    }
}

//void Simulator::isHitOnTarget()
//{
//    if (ground.getTarget() == projectile.getCurrentPoint()) {
//        hitTarget = true;
//    } else {
//        hitGround = true;
//    }
//}

bool Simulator::isPositionOnScreen(const Position& p) {
    double x = p.getPixelsX();
    double y = p.getPixelsY();

    if (y <= ptUpperRight.getPixelsY() && y >= 0 && x >= 0 && x <= ptUpperRight.getPixelsX()) {
        return true;
    }
    else return false;
}

bool Simulator::didProjectileHit() {
    Position projectileLocation = projectile->getCurrentPoint();
    double projectileY = projectileLocation.getMetersY();
    double elevationAtProjectileX = ground.getElevationMeters(projectileLocation);

    if (elevationAtProjectileX > projectileY) {
        return true;
    }
    else return false;
}

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
        timeOfFire = std::chrono::steady_clock::now();
        projectile = howitzer.fire();
        elapsedTime = -1;
    }

}

void Simulator::update()
{
    generate_stats();
    // If we have a projectile in the air
    if (projectile != NULL) {
        projectile->updatePoint(interval);
        // If it hit the ground or went out of the screen
        if (didProjectileHit() || !isPositionOnScreen(projectile->getCurrentPoint())) {
            // Delete the projectile object
            delete projectile;
            // Set the pointer to null to prevent memory leaks
            projectile = NULL;
        }
    }
    elapsedTime += 1;
}

void Simulator::renderFrame()
{
    ogstream gout;
    ground.draw(gout);
    howitzer.draw(gout, elapsedTime);
    if (projectile != NULL) {
        if (isPositionOnScreen(projectile->getCurrentPoint())) {
            projectile->draw(gout, elapsedTime);
            projectile->drawTrail(gout);
        }
    }
}