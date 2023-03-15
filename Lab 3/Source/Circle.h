#pragma once

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong hinh tron
class Circle : public Shape {
private:
	vector<pair<int, int>> mPoint;
	int mR;
public:
	Circle() {
	}
	Circle(int xT, int yT, int r) {
		mPoint.resize(1);
		mPoint[0].first = xT;
		mPoint[0].second = yT;
		mR = r;
	}
	Circle(const Circle& p) {
		mPoint.resize(1);
		mPoint[0].first = p.mPoint[0].first;
		mPoint[0].second = p.mPoint[0].second;
		mR = p.mR;
	}
	virtual ~Circle() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return mR; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 6;
	}
	//setter
	//setter
	void setPoint(vector<pair<int, int>> points) {
		for (int i = 0; i < mPoint.size(); i++) {
			mPoint[i].first = points[i].first;
			mPoint[i].second = points[i].second;
		}
	}
	void setR(int r) { mR = r; }
	void setA(int a) { return; }
	void setB(int b) { return; }
	void put8pixel(int xCenter, int yCenter, int x, int y)
	{
		Point(x + xCenter, y + yCenter).setPixel();
		Point(-x + xCenter, y + yCenter).setPixel();
		Point(x + xCenter, -y + yCenter).setPixel();
		Point(-x + xCenter, -y + yCenter).setPixel();
		Point(y + xCenter, x + yCenter).setPixel();
		Point(-y + xCenter, x + yCenter).setPixel();
		Point(y + xCenter, -x + yCenter).setPixel();
		Point(-y + xCenter, -x + yCenter).setPixel();
	}
	// ve duong tron bang midpoint
	void circleMidPoint(int xT, int yT, int r)
	{
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
	}
	void draw() {
		circleMidPoint(mPoint[0].first, mPoint[0].second, mR);
	}
	void create() {
		mPoint.resize(1);
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		// dua ve hinh vuong
		// xac dinh tam va ban kinh
		if (abs(dx) > abs(dy)) {
			mPoint[0].first = X1 + ((dx > 0) ? abs(dy) / 2 : -abs(dy) / 2);
			mPoint[0].second = Y1 + ((dy > 0) ? abs(dy) / 2 : -abs(dy) / 2);
			mR = abs(dy) / 2;
		}
		else {
			mPoint[0].first = X1 + ((dx > 0) ? abs(dx) / 2 : -abs(dx) / 2);
			mPoint[0].second = Y1 + ((dy > 0) ? abs(dx) / 2 : -abs(dx) / 2);
			mR = abs(dx) / 2;
		}
	}
	// update points inside shape
	void updatePoint() {
		int XT = mPoint[0].first;
		int YT = mPoint[0].second;

		UpdatePoint(XT, YT);

	}
};

#endif
