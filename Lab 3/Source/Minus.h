#pragma once

#ifndef _MINUS_H_
#define _MINUS_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong dau tru
class Minus : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Minus() {
	}
	Minus(const Minus& p) {
		mPoint.resize(4);
		for (int i = 0; i < 4; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Minus() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 13;
	}
	//setter
	void setPoint(vector<pair<int, int>> points) {
		for (int i = 0; i < mPoint.size(); i++) {
			mPoint[i].first = points[i].first;
			mPoint[i].second = points[i].second;
		}
	}
	void setR(int r) { return; }
	void setA(int a) { return; }
	void setB(int b) { return; }
	void draw() {
		for (int i = 0; i < 3; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[3].first, mPoint[3].second, mPoint[0].first, mPoint[0].second).draw();
	}
	void create() {
		mPoint.resize(4);

		// ve tuong tu hinh chu nhat
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		int X3 = X2;
		int Y3 = Y2;
		// cho no dep hon mot chut xiu
		if (abs(dy) > (abs(dx) / 3)) {
			Y3 = Y1 + ((dy > 0) ? abs(dx) / 3 : -abs(dx) / 3);
		}
		mPoint[0].first = X1;
		mPoint[0].second = Y1;
		mPoint[1].first = X3;
		mPoint[1].second = Y1;
		mPoint[2].first = X3;
		mPoint[2].second = Y3;
		mPoint[3].first = X1;
		mPoint[3].second = Y3;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[0].first + mPoint[2].first) / 2;
		int YT = (mPoint[0].second + mPoint[2].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
