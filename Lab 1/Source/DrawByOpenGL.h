#pragma once
#ifndef _DRAWBYOPENGL_H_
#define _DRAWBYOPENGL_H_

#include "Header.h"
#include "SupportDraw.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#define PI 3.1415926
#define num_segments 360
#define height 480
#define width 640

void lineOpenGL(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void circleOpenGL(float xT, float yT, float r) {
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * PI * float(ii) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x + xT, y + yT);
	}
	glEnd();
}

void ellipseOpenGL(float xT, float yT, float rx, float ry)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);
	float s = sinf(theta);
	float t;

	float x = 1;
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x * rx + xT, y * ry + yT);
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

void parabolOpenGL(float xT, float yT, float p)
{
	float y = 0;
	float x = 0;
	glBegin(GL_POINTS);
	while ((x + xT) < width && (y + yT) < height) {
		y = x * x / (4 * p);
		glVertex2f(xT + x, yT + y);
		glVertex2f(xT - x, yT + y);
		x += 0.05;
	}
	glEnd();
}

void hyperbolOpenGL(float xT, float yT, float a, float b)
{
	float x = a;
	float y = 0;
	glBegin(GL_POINTS);
	while ((x + xT) < width && (y + yT) < height) {
		y = sqrt(b * b * (x * x / (a * a) - 1));
		glVertex2f(xT + x, yT + y);
		glVertex2f(xT - x, yT - y);
		glVertex2f(xT + x, yT - y);
		glVertex2f(xT - x, yT + y);
		x += 0.05;
	}
	glEnd();
}

void drawObjectByOpenGL() {
	ifstream fileIn("input.txt", ios::in);
	int code, x1, y1, x2, y2, xT, yT, r, p, a, b;

	if (fileIn.good()) {
		string str;
		while (getline(fileIn, str)) {
			istringstream ss(str);
			int code;
			ss >> code;
			switch (code)
			{
			case 0:
				ss >> x1 >> y1 >> x2 >> y2;
				getTime();
				// ve duong thang bang DDA
				lineOpenGL(x1, y1, x2, y2);

				cout << "Time draw Line " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") with OpenGL : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 1:
				ss >> x1 >> y1 >> x2 >> y2;
				getTime();
				// ve duong thang bang Bresenham
				lineOpenGL(x1, y1, x2, y2);

				cout << "Time draw Line " << "(" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ") with OpenGL: " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 2:
				ss >> xT >> yT >> r;
				getTime();
				// ve hinh tron bang MidPoint
				circleOpenGL(xT, yT, r);

				cout << "Time draw Circle " << "(" << xT << ", " << yT << "), r = " << r << " with OpenGL : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 3:
				ss >> xT >> yT >> a >> b;
				getTime();
				// ve hinh ellipse bang MidPoint
				ellipseOpenGL(xT, yT, a, b);

				cout << "Time draw Ellipse " << "(" << xT << ", " << yT << "), a = " << a << ", b = " << b << " with OpenGL : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 4:
				ss >> xT >> yT >> p;
				getTime();
				// ve parabol bang MidPoint
				parabolOpenGL(xT, yT, p);

				cout << "Time draw Parabol " << "(" << xT << ", " << yT << "), p = " << p << " with OpenGL : " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			case 5:
				ss >> xT >> yT >> a >> b;
				getTime();
				// ve hyperbol bang MidPoint
				hyperbolOpenGL(xT, yT, a, b);

				cout << "Time draw Hyperbol " << "(" << xT << ", " << yT << "), a = " << a << ", b = " << b << " with OpenGL: " << 1000.0 * stopTime() << " (ms)" << endl;
				break;
			default:
				break;
			}
			glFlush();
		}
	}

	fileIn.close();
}

#endif