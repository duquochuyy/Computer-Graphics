#pragma once
#ifndef _LINEBRESENHAM_H_
#define _LINEBRESENHAM_H_

#include "Header.h"
#include "SupportDraw.h"

// ve duong thang bang Bresenham
void lineBresenham(int x1, int y1, int x2, int y2) {
	glColor3ub(255, 0, 0);

	int Dx = abs(x2 - x1);
	int Dy = abs(y2 - y1);
	// ve theo dx hoac dy
	int p = (Dx > Dy) ? (2 * Dy - Dx) : (2 * Dx - Dy);
	int c1 = (Dx > Dy) ? (2 * Dy) : (2 * Dx);
	int c2 = (Dx > Dy) ? (2 * (Dy - Dx)) : (2 * (Dx - Dy));
	int x = x1;
	int y = y1;
	// truong hop ve tu tren xuong
	int x_inc = (x1 < x2) ? 1 : -1;
	int y_inc = (y1 < y2) ? 1 : -1;
	setPixel(x, y);

	// ve theo x
	if (Dx > Dy) {
		while (x != x2) {
			if (p < 0) p += c1;
			else {
				p += c2;
				y += y_inc;
			}
			x += x_inc;
			setPixel(x, y);
		}
	}
	// ve theo y
	else {
		while (y != y2) {

			if (p < 0) p += c1;
			else {
				p += c2;
				x += x_inc;
			}
			y += y_inc;
			setPixel(x, y);
		}
	}
	glFlush();
}

#endif