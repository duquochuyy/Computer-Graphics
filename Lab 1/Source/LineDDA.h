#pragma once
#ifndef _LINEDDA_H_
#define _LINEDDA_H_

#include "Header.h"
#include "SupportDraw.h"
#define height 480
#define width 640
#define max(a,b) ((a) > (b) ? (a) : (b))

// ve duong thang bang DDA
void lineDDA(int x1, int y1, int x2, int y2) {       
	// glColor3ub(255, 0, 0);

	int  dx = x2 - x1, dy = y2 - y1;
	float x_inc, y_inc;
	float step = max(abs(dx), abs(dy));
	x_inc = dx / step;
	y_inc = dy / step;
	float x = x1, y = y1; // Khoi tao cac gia tri ban dau	
	setPixel(x, y);

	int k = 1;
	while (k <= step) {
		k++;
		x += x_inc;
		y += y_inc;
		setPixel(round(x), round(y));
	}

	glFlush();
}

#endif