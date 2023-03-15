#pragma once

#ifndef _EQUILATERALTRIANGLE_H_
#define _EQUILATERALTRIANGLE_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong tam giac deu
class EquilateralTriangle : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	EquilateralTriangle() {
	}
	EquilateralTriangle(const EquilateralTriangle& p) {
		mPoint.resize(3);
		for (int i = 0; i < 3; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~EquilateralTriangle() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 3;
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
		for (int i = 0; i < 2; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[2].first, mPoint[2].second, mPoint[0].first, mPoint[0].second).draw();
	}
	void create() {
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		int canh;
		mPoint.resize(3);
		mPoint[0].first = X1;
		mPoint[0].second = Y1;
		// xet canh cua hinh tam giac deu
		// xac dinh toa do cac dinh
		if (abs(dx) > (abs(dy) * 2 / sqrt(3))) {
			canh = abs(dy) * 2 / sqrt(3);
			mPoint[1].first = X1 + ((dx > 0) ? canh : -canh);
			mPoint[1].second = Y1;
			mPoint[2].first = X1 + ((dx > 0) ? (canh / 2) : (-canh / 2));
			mPoint[2].second = Y2;
		}
		else {
			canh = abs(dx);
			mPoint[1].first = X2;
			mPoint[1].second = Y1;
			mPoint[2].first = X1 + ((dx > 0) ? (canh / 2) : (-canh / 2));
			mPoint[2].second = Y1 + ((dy > 0) ? (int)(canh * sqrt(3) / 2) : (int)(-canh * sqrt(3) / 2));
		}
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[0].first + mPoint[1].first) / 2;
		int YT = (mPoint[0].second + mPoint[2].second) / 2;

		UpdatePoint(XT, YT);

	}
};

#endif
