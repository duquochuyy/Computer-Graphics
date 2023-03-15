#pragma once
#ifndef _ELLIPSEMIDPOINT_H_
#define _ELLIPSEMIDPOINT_H_

#include "Header.h"
#include "SupportDraw.h"

void ellipseMidPoint(int xT, int yT, int a, int b)
{
	glColor3ub(255, 0, 0);
	int x = 0, y = b;
	float p1 = b * b - a * a * b + a * a * 0.25;
	put4pixel(xT, yT, x, y);
	while (x * b * b <= y * a * a) {
		if (p1 < 0)
			p1 += b * b * (2 * x + 3);
		else {
			y--;
			p1 += b * b * (2 * x + 3) - a * a * (2 * y - 2);
		}
		x++;
		put4pixel(xT, yT, x, y);
	}


	float p2 = (x + 0.5) * (x + 0.5) * b * b + (y - 1) * (y - 1) * a * a - a * a * b * b;
	put4pixel(xT, yT, x, y);
	while (y >= 0) {
		if (p2 > 0) 
			p2 -= a * a * (2 * y - 3);
		else {
			x++;
			p2 += b * b * (2 * x + 2) - a * a * (2 * y - 3);
		}
		y--;
		put4pixel(xT, yT, x, y);
	}

	glFlush();
}

#endif