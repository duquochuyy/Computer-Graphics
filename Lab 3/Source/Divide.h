#pragma once

#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Circle.h"

// doi tuong dau chia
class Divide : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Divide() {
	}
	Divide(const Divide& p) {
		mPoint.resize(4);
		for (int i = 0; i < 4; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].first = p.mPoint[i].second;
		}
	}
	virtual ~Divide() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 15;
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

		// ve 2 hinh tron va 1 hinh chu nhat
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		mPoint[1].first = (dx < 0) ? X1 : X2;
		mPoint[1].second = (dy < 0) ? Y1 : Y2;
		mPoint[3].first = (dx < 0) ? X2 : X1;
		mPoint[3].second = (dy < 0) ? Y2 : Y1;
		mPoint[0].first = mPoint[1].first - abs(dx) / 3;
		mPoint[0].second = mPoint[1].second;
		mPoint[2].first = mPoint[3].first + abs(dx) / 3;
		mPoint[2].second = mPoint[3].second;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[1].first + mPoint[3].first) / 2;
		int YT = (mPoint[0].second + mPoint[2].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
