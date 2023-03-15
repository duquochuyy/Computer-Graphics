#pragma once

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong hinh chu nhat
class Rectangle1 : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Rectangle1() {
	};
	Rectangle1(const Rectangle1& p) {
		mPoint.resize(4);
		for (int i = 0; i < 4; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].first = p.mPoint[i].second;
		}
	}
	virtual ~Rectangle1() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 4;
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
	// ve duong vien
	void draw() {
		for (int i = 0; i < 3; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[3].first, mPoint[3].second, mPoint[0].first, mPoint[0].second).draw();
	}
	// tao hinh luc ve
	void create() {
		mPoint.resize(4);
		mPoint[0].first = X1;
		mPoint[0].second = Y1;
		mPoint[1].first = X2;
		mPoint[1].second = Y1;
		mPoint[2].first = X2;
		mPoint[2].second = Y2;
		mPoint[3].first = X1;
		mPoint[3].second = Y2;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[0].first + mPoint[2].first) / 2;
		int YT = (mPoint[0].second + mPoint[2].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
