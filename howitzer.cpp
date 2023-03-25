#include "howitzer.h"
#include <iostream>
#include "position.h"
#include "projectile.h"
#include "uiDraw.h"
#include <cmath>
#include <chrono>

double Howitzer::muzzleVelocity = 1227; // 827 default

Projectile* Howitzer::fire()
{
	Velocity v((sin(angle) * muzzleVelocity), cos(angle) * muzzleVelocity);
	Projectile* p = new Projectile(location, v, angle, 0.15489f, 46.7);
	loaded = false;
	return p;
}

void Howitzer::rotate(bool clockwise, bool isFastRotation) {
	if (clockwise) {
		if (!(angle > maxRightAngle)) { //-1.57 
			isFastRotation ? angle += fastRotateSpeed : angle += slowRotateSpeed; }
	}
	else {
		if (!(angle < maxLeftAngle)) {  //1.57
			isFastRotation ? angle -= fastRotateSpeed : angle -= slowRotateSpeed; }
	}
}