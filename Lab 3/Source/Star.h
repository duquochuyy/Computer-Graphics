#pragma once

#ifndef _STAR_H_
#define _STAR_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// tao doi tuong ngoi sao
class Star : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Star() {
	}
	Star(const Star& p) {
		mPoint.resize(10);
		for (int i = 0; i < 10; i++) {
			mPoint[i].first = p.mPoint[i].first;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Star() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 11;
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
		for (int i = 0; i < 9; i++) {
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[9].first, mPoint[9].second, mPoint[0].first, mPoint[0].second).draw();
	}
	// tao hinh luc ve
	void create() {
		mPoint.resize(10);
		
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
		// ban kinh duong tron lon
		int r = canh / 2;

		// ban kinh duong tron nho
		int r_nho;
		int a, b, c;
		a = r * sin(54 * PI / 180);
		b = r * cos(54 * PI / 180);
		c = b * tan(36 * PI / 180);
		r_nho = a - c;
		int d1 = r_nho * cos(36 * PI / 180);
		int d2 = r_nho * sin(36 * PI / 180);

		// xu dung 2 hinh ngu giac deu noi tiep 2 duong tron dong tam de xac dinh toa do

		// dinh tren cung
		mPoint[0].first = xT;
		mPoint[0].second = Y1;
		mPoint[1].first = xT + ((dx > 0) ? d2 : -d2);
		mPoint[1].second = yT + ((dy > 0) ? -d1 : d1);

		// lay doi xung tam
		mPoint[9].first = mPoint[1].first + ((dx > 0) ? -2 * abs(xT - mPoint[1].first) : 2 * abs(xT - mPoint[1].first));
		mPoint[9].second = mPoint[1].second;

		int d3 = r * cos(72 * PI / 180);
		int d4 = r * sin(72 * PI / 180);
		mPoint[8].first = xT + ((dx > 0) ? -d4 : d4);
		mPoint[8].second = yT + ((dy > 0) ? -d3 : d3);

		mPoint[2].first = mPoint[8].first + ((dx > 0) ? 2 * abs(xT - mPoint[8].first) : -2 * abs(xT - mPoint[8].first));
		mPoint[2].second = mPoint[8].second;

		d1 = r_nho * cos(72 * PI / 180);
		d2 = r_nho * sin(72 * PI / 180);
		mPoint[3].first = xT + ((dx > 0) ? d2 : -d2);
		mPoint[3].second = yT + ((dy > 0) ? d1 : -d1);

		mPoint[7].first = mPoint[3].first + ((dx > 0) ? -2 * abs(xT - mPoint[3].first) : 2 * abs(xT - mPoint[3].first));
		mPoint[7].second = mPoint[3].second;

		d3 = r * sin(54 * PI / 180);
		d4 = r * cos(54 * PI / 180);
		mPoint[6].first = xT + ((dx > 0) ? -d4 : d4);
		mPoint[6].second = yT + ((dy > 0) ? d3 : -d3);

		mPoint[4].first = mPoint[6].first + ((dx > 0) ? 2 * abs(xT - mPoint[6].first) : -2 * abs(xT - mPoint[6].first));
		mPoint[4].second = mPoint[6].second;

		mPoint[5].first = xT;
		mPoint[5].second = yT + ((dy > 0) ? r_nho : -r_nho);
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[2].first + mPoint[8].first) / 2;
		int YT = (mPoint[0].second + mPoint[4].second) / 2;

		UpdatePoint(XT, YT);
	}
};

#endif
