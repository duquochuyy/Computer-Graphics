#pragma once
#ifndef _SUPPORTDRAW_H_
#define _SUPPORTDRAW_H_

#include "Header.h"

// std::chrono::high_resolution_clock::time_point start;
// std::chrono::high_resolution_clock::time_point end;
 std::chrono::high_resolution_clock::time_point timeIs;
 std::chrono::duration<double> timeDraw;

// khoi tao che do do hoa
void myinit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

// ve 1 pixel len
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

// ve 8 pixel, ap dung cho Circle
void put8pixel(int xCenter, int yCenter, int x, int y)
{
	setPixel(x + xCenter, y + yCenter);
	setPixel(-x + xCenter, y + yCenter);
	setPixel(x + xCenter, -y + yCenter);
	setPixel(-x + xCenter, -y + yCenter);
	setPixel(y + xCenter, x + yCenter);
	setPixel(-y + xCenter, x + yCenter);
	setPixel(y + xCenter, -x + yCenter);
	setPixel(-y + xCenter, -x + yCenter);
}

// ve 4 pixel, ap dung cho ellipse, hyperbol
void put4pixel(int xCenter, int yCenter, int x, int y)
{
	setPixel(xCenter + x, yCenter + y);
	setPixel(xCenter - x, yCenter + y);
	setPixel(xCenter + x, yCenter - y);
	setPixel(xCenter - x, yCenter - y);
}

// ve 2 pixel, ap dung cho parabol
void put2pixel(int xCenter, int yCenter, int x, int y)
{
	setPixel(x + xCenter, y + yCenter);
	setPixel(-x + xCenter, y + yCenter);
}

void getTime() {
	setPixel(-100, -100);
	glFlush();
	timeIs = std::chrono::high_resolution_clock::now();
	
}

double stopTime() {
	timeDraw = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - timeIs);
	return 1.0 * timeDraw.count();
}

#endif