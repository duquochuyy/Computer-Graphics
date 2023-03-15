#pragma once

#ifndef _MULTIPLY_H_
#define _MULTIPLY_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong dau nhan
class Multiply : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Multiply() {
	}
	Multiply(const Multiply& p) {
		mPoint.resize(12);
		for (int i = 0; i < 12; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Multiply() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 14;
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
	// ve duong vien hinh
	void draw() {
		for (int i = 0; i < 11; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[11].first, mPoint[11].second, mPoint[0].first, mPoint[0].second).draw();
	}
	// tao hinh luc ve
	void create() {
		mPoint.resize(12);

		// tuong tu nhu dau cong
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
		// canh hinh vuong
		int canh = abs(X3 - X1);

		// xac dinh toa do cac dinh cua dau nhan
		// (X4, Y4) (X5, Y5) thay doi/ gan lien tuc de luu gia tri dinh
		mPoint[0].first = X1 + ((dx > 0) ? canh / 4 : -canh / 4);
		mPoint[0].second = Y1;
		mPoint[1].first = X1 + ((dx > 0) ? canh / 2 : -canh / 2);
		mPoint[1].second = Y1 + ((dy > 0) ? canh / 4 : -canh / 4);

		mPoint[2].first = mPoint[0].first + ((dx > 0) ? canh / 2 : -canh / 2);
		mPoint[2].second = mPoint[0].second;

		mPoint[3].first = X3;
		mPoint[3].second = mPoint[1].second;

		mPoint[4].first = mPoint[2].first;
		mPoint[4].second = mPoint[2].second + ((dy > 0) ? canh / 2 : -canh / 2);

		mPoint[5].first = X3;
		mPoint[5].second = mPoint[3].second + ((dy > 0) ? canh / 2 : -canh / 2);

		mPoint[6].first = mPoint[4].first;
		mPoint[6].second = mPoint[4].second + ((dy > 0) ? canh / 2 : -canh / 2);

		mPoint[7].first = mPoint[1].first;
		mPoint[7].second = mPoint[5].second;

		mPoint[8].first = mPoint[0].first;
		mPoint[8].second = mPoint[6].second;

		mPoint[9].first = mPoint[7].first + ((dx > 0) ? -canh / 2 : canh / 2);
		mPoint[9].second = mPoint[7].second;

		mPoint[10].first = mPoint[0].first;
		mPoint[10].second = mPoint[8].second + ((dy > 0) ? -canh / 2 : canh / 2);

		mPoint[11].first = mPoint[9].first;
		mPoint[11].second = mPoint[1].second;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[4].first + mPoint[10].first) / 2;
		int YT = (mPoint[1].second + mPoint[7].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
