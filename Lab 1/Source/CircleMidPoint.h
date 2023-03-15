#pragma once
#ifndef _CIRCLEMIDPOINT_H_
#define _CIRCLEMIDPOINT_H_

#include "Header.h"
#include "SupportDraw.h"

void circleMidPoint(int xT, int yT, int r)
{
	glColor3ub(255, 0, 0);
	int x = 0, y = r;
	int p = 1 - r;

	put8pixel(xT, yT, x, y);

	// ve tu 90do -> 45do
	while (x < y)
	{
		if (p < 0)
			p += (x * 2) + 3;
		else {
			y--;
			p += ((x - y) * 2) + 5;
		}
		x++;
		put8pixel(xT, yT, x, y);
	}

	glFlush();
}

#endif