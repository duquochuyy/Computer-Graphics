#pragma once
#ifndef _PARABOLMIDPOINT_H_
#define _PARABOLMIDPOINT_H_

#include "Header.h"
#include "SupportDraw.h"


void parabolMidPoint(int xT, int yT, int p)
{
	glColor3ub(255, 0, 0);
	int x = 0, y = 0;
	// truong hop parabol up nguoc
	int y_inc = (p > 0) ? 1 : -1;
	float p1 = 1 - 2 * p;
	int p_abs = abs(p);
	put2pixel(xT, yT, x, y);

	// y theo x
	// x^2 - 4py = 0
	while (x <= 2 * p_abs)
	{
		if (p1 < 0)
			p1 += x * 2 + 3;
		else
		{
			y += y_inc;
			p1 += x * 2 + 3 - 4 * p_abs;
		}
		x++;
		put2pixel(xT, yT, x, y);
	}

	// x theo y
	// 4py - x^2 = 0
	float p2 = 4 * p * (y + 1) - (x + 0.5) * (x + 0.5);
	while ((y > -yT) && (y < (height - yT))) {
		if (p2 < 0)
			p2 += 4 * p_abs;
		else {
			x++;
			p2 += -2 * x - 3 + 4 * p_abs;
		}
		y += y_inc;
		put2pixel(xT, yT, x, y);
	}

	glFlush();
}

#endif