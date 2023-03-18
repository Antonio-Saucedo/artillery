#include "howitzer.h"
#include <iostream>
#include "position.h"
#include "projectile.h"
#include "uiDraw.h"
#include <cmath>
#include <chrono>

double Howitzer::muzzleVelocity = 827;

Projectile Howitzer::fire()
{
	Velocity v((sin(angle) * muzzleVelocity), cos(angle) * muzzleVelocity);
	Projectile p(location, v, angle, 0.15489f, 46.7);
	loaded = false;
	return p;
}

void Howitzer::rotate(bool clockwise, bool isFastRotation) {
	if (clockwise) {
		isFastRotation ? angle += fastRotateSpeed : angle += slowRotateSpeed;
	}
	else {
		isFastRotation ? angle -= fastRotateSpeed : angle -= slowRotateSpeed;
	}
}