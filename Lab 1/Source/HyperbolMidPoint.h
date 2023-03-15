#pragma once
#ifndef _HYPERBOLMIDPOINT_H_
#define _HYPERBOLMIDPOINT_H_

#include "Header.h"
#include "SupportDraw.h"

void hyperbolMidPoint(int xT, int yT, int a, int b)
{
	glColor3ub(255, 0, 0);
	int x = a, y = 0;

	if (a >= b) {
		// x^2*b^2 - y^2*a^2 - a^2*b^2 = 0
		// x theo y
		float p1 = a * b * b + b * b / 4 - a * a;
		put4pixel(xT, yT, x, y);
		while (y <= (b * b * x / (a * a))) {
			if (p1 > 0)
				p1 -= a * a * (2 * y + 3);
			else {
				x++;
				p1 += b * b * (2 * x + 2) - a * a * (2 * y + 3);
			}
			y++;
			put4pixel(xT, yT, x, y);
		}

		// y theo x
		float p2 = (x + 1) * (x + 1) * b * b - (y + 0.5) * (y + 0.5) * a * a - a * a * b * b;
		while (y + yT < height) {
			if (p2 < 0)
				p2 += b * b * (2 * x + 3);
			else {
				y++;
				p2 += b * b * (2 * x + 3) - a * a * (2 * y + 2);
			}
			x++;
			put4pixel(xT, yT, x, y);
		}
	}
	else {
		// y theo x
		int p2 = 2 * a * b * b + b * b - 0.25 * a * a;
		while (x < (a * a * y / (b * b))) {
			if (p2 < 0)
				p2 += b * b * (2 * x + 3);
			else {
				y++;
				p2 += b * b * (2 * x + 3) - 2 * a * a * (y + 1);
			}      
			x++;
			put4pixel(xT, yT, x, y);
		}

		// x^2*b^2 - y^2*a^2 - a^2*b^2 = 0
		// x theo y
		int p1 = (x + 0.5) * (x + 0.5) * b * b - (y + 1) * (y + 1) * a * a - a * a * b * b;
		put4pixel(xT, yT, x, y);
		while (y + yT < height) {
			if (p1 > 0)
				p1 -= a * a * (2 * y + 3);
			else {
				x++;
				p1 += b * b * (2 * x + 2) - a * a * (2 * y + 3);
			}
			y++;
			put4pixel(xT, yT, x, y);
		}
	}
	glFlush();
}

#endif