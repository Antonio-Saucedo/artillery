#include "projectile.h"

#include "position.h"
#include "velocity.h"
#include "trajectoryEngine.h"
#include "uiDraw.h"

#include <iostream>
#include <list>

void Projectile::updatePoint(float interval)
{
	previous.push_back(current);
	te.nextPosition(current, velocity, interval, weight, diameter, weight, angle);

	if (previous.size() > 10) {
		previous.pop_front(); // Remove the first element from the list
	}
}

void Projectile::draw(ogstream o, double age) {
	o.drawProjectile(current, age);
}