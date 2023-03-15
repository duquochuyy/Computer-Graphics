#pragma once

#ifndef _HEXAGON_H_
#define _HEXAGON_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong hinh luc giac
class Hexagon : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Hexagon() {
	}
	Hexagon(const Hexagon& p) {
		mPoint.resize(6);
		for (int i = 0; i < 6; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Hexagon() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 9;
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
		for (int i = 0; i < 5; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[5].first, mPoint[5].second, mPoint[0].first, mPoint[0].second).draw();
	}
	void create() {
		mPoint.resize(6);
		// dua ve hinh vuong
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		int canh, X3, Y3;
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
		// ban kinh duong tron ngoai tiep luc giac deu
		int r = canh / 2;
		// xac dinh dinh tren dung
		mPoint[0].first = xT;
		mPoint[0].second = Y1;
		int d1 = r * cos(60 * PI / 180);
		int d2 = r * sin(60 * PI / 180);
		mPoint[1].first = xT + ((dx > 0) ? d2 : -d2);
		mPoint[1].second = yT + ((dy > 0) ? -d1 : d1);

		// xu dung phep doi xung tam de xac dinh cac dinh khac
		// dung cong thuc luong giac de tim toa do canh
		mPoint[5].first = mPoint[1].first + ((dx > 0) ? -2 * abs(xT - mPoint[1].first) : 2 * abs(xT - mPoint[1].first));
		mPoint[5].second = mPoint[1].second;

		mPoint[4].first = mPoint[5].first;
		mPoint[4].second = mPoint[5].second + ((dy > 0) ? 2 * abs(yT - mPoint[5].second) : -2 * abs(yT - mPoint[5].second));

		mPoint[2].first = mPoint[4].first + ((dx > 0) ? 2 * abs(xT - mPoint[4].first) : -2 * abs(xT - mPoint[4].first));
		mPoint[2].second = mPoint[4].second;

		mPoint[3].first = xT;
		mPoint[3].second = Y3;
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[1].first + mPoint[3].first) / 2;
		int YT = (mPoint[1].second + mPoint[4].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
