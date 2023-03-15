#pragma once

#ifndef _ARROW_H_
#define _ARROW_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong mui ten
class Arrow : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Arrow() {}
	Arrow(const Arrow& p) {
		mPoint.resize(7);
		for (int i = 0; i < 7; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Arrow() {}
	// getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 10;
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
		for (int i = 0; i < 6; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[6].first, mPoint[6].second, mPoint[0].first, mPoint[0].second).draw();
	}
	// tao hinh luc ve
	void create() {
		mPoint.resize(7);
		int dx = X2 - X1;
		int dy = Y2 - Y1;

		// ve than tren
		mPoint[0].first = X1;
		mPoint[0].second = Y1 + ((dy > 0) ? abs(dy) / 4 : -abs(dy) / 4);
		mPoint[1].first = X1 + ((dx > 0) ? abs(dx) / 2 : -abs(dx) / 2);
		mPoint[1].second = mPoint[0].second;

		mPoint[2].first = mPoint[1].first;
		mPoint[2].second = Y1;

		// ve phan tren cua mui nhon
		mPoint[3].first = X2;
		mPoint[3].second = Y1 + ((dy > 0) ? abs(dy) / 2 : -abs(dy) / 2);

		// ve phan duoi cua mui nhon
		mPoint[4].second = Y2;
		mPoint[4].first = mPoint[2].first;

		// ve phan duoi cho thanh mui ten
		mPoint[5].first = mPoint[4].first;
		mPoint[5].second = Y1 + ((dy > 0) ? 3 * abs(dy) / 4 : -3 * abs(dy) / 4);

		mPoint[6].first = X1;
		mPoint[6].second = mPoint[5].second;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[0].first + mPoint[3].first) / 2;
		int YT = (mPoint[2].second + mPoint[4].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
