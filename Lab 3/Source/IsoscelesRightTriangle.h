#pragma once

#ifndef _ISOSCELESRIGHTTRIANGLE_H_
#define _ISOSCELESRIGHTTRIANGLE_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong tam giac can
class IsoscelesRightTriangle : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	IsoscelesRightTriangle() {
	}/*
	IsoscelesRightTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		mX.push_back(x1);
		mX.push_back(x2);
		mX.push_back(x3);
		mY.push_back(x1);
		mY.push_back(x2);
		mY.push_back(x3);
	}*/
	IsoscelesRightTriangle(const IsoscelesRightTriangle& p) {
		mPoint.resize(3);
		for (int i = 0; i < 3; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~IsoscelesRightTriangle() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 2;
	}
	//setter
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
		for (int i = 0; i < 2; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[2].first, mPoint[2].second, mPoint[0].first, mPoint[0].second).draw();
	}
	void create() {
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		mPoint.resize(3);
		mPoint[0].first = X1;
		mPoint[0].second = Y1;
		// duong ve hinh vuong de xac dinh toa do cac dinh
		if (abs(dx) > abs(dy)) {
			mPoint[1].second = Y1 + ((dy > 0) ? abs(dy) : -abs(dy));
			mPoint[1].first = X1;
			mPoint[2].second = mPoint[1].second;
			mPoint[2].first = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
		}
		else {
			mPoint[1].second = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
			mPoint[1].first = X1;
			mPoint[2].second = mPoint[1].second;
			mPoint[2].first = X1 + ((dx > 0) ? abs(dx) : -abs(dx));
		}
	}
	// update points inside shape
	void updatePoint() {
		int XT = 3 * mPoint[1].first / 4 + mPoint[2].first / 4;
		int YT = 3 * mPoint[1].second / 4 + mPoint[0].second / 4;

		UpdatePoint(XT, YT);
	}
};

#endif
