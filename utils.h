#pragma once
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

double applyLI(double x1, double x2, double x3, double y1, double y3) {
	double y2 = (((x2 - x3) * (y3 - y1)) / (x1 - x3)) + y1;
	return y2;
}

#endif