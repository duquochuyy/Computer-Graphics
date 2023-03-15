#pragma once

#ifndef _PLUS_H_
#define _PLUS_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong dau nhan
class Plus : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Plus() {
	}
	Plus(const Plus& p) {
		mPoint.resize(12);
		for (int i = 0; i < 12; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Plus() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 12;
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
		for (int i = 0; i < 11; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[11].first, mPoint[11].second, mPoint[0].first, mPoint[0].second).draw();
	}
	void create() {
		mPoint.resize(12);

		// xac dinh kich thuoc 4 canh xung quanh
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		int xT = (X2 + X1) / 2;
		int yT = (Y2 + Y1) / 2;
		int X3, Y3;
		// X1, Y1
		// X3, Y3 la toa do dung cho hinh vuong
		if (abs(dx) > abs(dy)) {
			X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
			Y3 = Y2;
		}
		else {
			X3 = X2;
			Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
		}
		// canh hinh xuong
		int canh = abs(X3 - X1);

		mPoint[0].first = X1 + ((dx > 0) ? canh / 3 : -canh / 3);
		mPoint[0].second = Y1;
		mPoint[1].first = mPoint[0].first + ((dx > 0) ? canh / 3 : -canh / 3);
		mPoint[1].second = mPoint[0].second;

		mPoint[11].first = mPoint[0].first;
		mPoint[11].second = mPoint[0].second + ((dy > 0) ? canh / 3 : -canh / 3);

		mPoint[2].first = mPoint[11].first + ((dx > 0) ? canh / 3 : -canh / 3);
		mPoint[2].second = mPoint[11].second;

		mPoint[3].first = X3;
		mPoint[3].second = mPoint[2].second;

		mPoint[4].second = mPoint[3].second + ((dy > 0) ? canh / 3 : -canh / 3);
		mPoint[4].first = mPoint[3].first;

		mPoint[5].first = mPoint[4].first + ((dx > 0) ? -canh / 3 : +canh / 3);
		mPoint[5].second = mPoint[4].second;

		mPoint[6].first = mPoint[5].first;
		mPoint[6].second = Y3;

		mPoint[7].first = X1 + ((dx > 0) ? canh / 3 : -canh / 3);
		mPoint[7].second = Y3;

		mPoint[8].first = mPoint[7].first;
		mPoint[8].second = mPoint[7].second + ((dy > 0) ? -canh / 3 : canh / 3);

		mPoint[9].first = X1;
		mPoint[9].second = mPoint[8].second;

		mPoint[10].first = mPoint[9].first;
		mPoint[10].second = Y1 + ((dy > 0) ? canh / 3 : -canh / 3);
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[3].first + mPoint[10].first) / 2;
		int YT = (mPoint[0].second + mPoint[6].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
