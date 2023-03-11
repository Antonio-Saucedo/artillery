//#include "simulator.h"
//
//#include <chrono>
//
//void Simulator::reset()
//{
//}
//
//void Simulator::generate_stats()
//{
//	const std::chrono::time_point<std::chrono::steady_clock> elapsedTime = std::chrono::steady_clock::now() - timeOfFire;
//
//	StatisticsDisplay.updateStats(ground.getElevationMeters(projectile.getCurrentPoint(),
//		projectile.getSpeed(), abs(howitzer.getPoint().getX()) - projectile.getCurrentPoint().getX()),
//		elapsedTime;
//}
//
//void Simulator::isHitOnTarget()
//{
//    if (ground.getTarget() == projectile.getCurrentPoint()) {
//        hitTarget = true;
//    } else {
//        hitGround = true;
//    }
//}
//
//void Simulator::input(const Interface* pUI)
//{
//    howitzer.rotate(true, true);
//
//    if (pUI->isSpace()) {
//        howitzer.fire();
//    }
//}
//
//void Simulator::update(const Interface* pUI)
//{
//    ogstream gout(Position(10.0, ptUpperRight.getPixelsY()));
//
//    input(pUI);
//
//    renderFrame(gout);
//
//    isHitOnTarget();
//}
//
//void Simulator::renderFrame(ogstream& gout)
//{
//    gout.setf(ios::fixed | ios::showpoint);
//    gout.precision(1);
//}