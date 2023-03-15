#pragma once

#ifndef _PENTAGON_H_
#define _PENTAGON_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong hinh ngu giac
class Pentagon : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Pentagon() {
	}
	Pentagon(const Pentagon& p) {
		mPoint.resize(5);
		for (int i = 0; i < 5; i++) {
			mPoint[i].first = p.mPoint[i].second;
			mPoint[i].first = p.mPoint[i].second;
		}
	}
	virtual ~Pentagon() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 8;
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
		for (int i = 0; i < 4; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[4].first, mPoint[4].second, mPoint[0].first, mPoint[0].second).draw();
	}
	void create() {
		mPoint.resize(5);
		int X3, Y3;
		// dua ve hinh vuong
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		int canh;
		if (abs(dx) > abs(dy)) {
			canh = abs(dy);
			Y3 = Y2;
			X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
		}
		else {
			canh = abs(dx);
			X3 = X2;
			Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
		}
		// xac dinh tam doi xung
		int xT = (X1 + X3) / 2;
		int yT = (Y1 + Y3) / 2;

		// ban kinh hinh tron ngoai tiep ngu giac deu
		int r = canh / 2;

		// su dung 2 toa do (X4, Y4) va (X5, Y5) de gan/ thay doi lien tuc ve cac duong thang
		mPoint[0].first = xT;
		mPoint[0].second = Y1;
		// dinh tren cung
		int d1 = r * cos(72 * PI / 180);
		int d2 = r * sin(72 * PI / 180);
		mPoint[4].first = xT + ((dx > 0) ? -d2 : d2);
		mPoint[4].second = yT + ((dy > 0) ? -d1 : d1);

		// lay doi xung qua xT
		mPoint[1].first = mPoint[4].first + ((dx > 0) ? 2 * abs(xT - mPoint[4].first) : -2 * abs(xT - mPoint[4].first));
		mPoint[1].second = mPoint[4].second;

		d1 = r * sin(54 * PI / 180);
		d2 = r * cos(54 * PI / 180);
		mPoint[2].first = xT + ((dx > 0) ? d2 : -d2);
		mPoint[2].second = yT + ((dy > 0) ? d1 : -d1);

		mPoint[3].first = mPoint[2].first + ((dx > 0) ? -2 * abs(xT - mPoint[2].first) : +2 * abs(xT - mPoint[2].first));
		mPoint[3].second = mPoint[2].second;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[2].first + mPoint[3].first) / 2;
		int YT = (mPoint[0].second + mPoint[2].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
