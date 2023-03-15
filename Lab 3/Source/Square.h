#pragma once

#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// doi tuong hinh vuong
class Square : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Square() {
	}
	Square(const Square& p) {
		mPoint.resize(4);
		for (int i = 0; i < 4; i++) {
			mPoint[i].first = p.mPoint[i].second;
			mPoint[i].second = p.mPoint[i].second;
		}
	}
	virtual ~Square() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 5;
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
	// draw vien 
	void draw() {
		for (int i = 0; i < 3; i++) {
			//cout << mPoint[0].first << " hhuy" << mPoint[0].second << endl;
			Line(mPoint[i].first, mPoint[i].second, mPoint[i + 1].first, mPoint[i + 1].second).draw();
		}
		Line(mPoint[3].first, mPoint[3].second, mPoint[0].first, mPoint[0].second).draw();
	}
	// create hinh luc ve
	void create() {
		int dx = X2 - X1;
		int dy = Y2 - Y1;
		int canh;
		mPoint.resize(4);
		mPoint[0].first = X1;
		mPoint[0].second = Y1;
		// dua ve hinh vuong
		// xac dinh toa do cac dinh
		if (abs(dx) > abs(dy)) {
			canh = abs(dy);
			mPoint[1].first = X1 + ((dx > 0) ? canh : -canh);
			mPoint[1].second = Y1;
			mPoint[2].first = mPoint[1].first;
			mPoint[2].second = Y2;
			mPoint[3].first = X1;
			mPoint[3].second = Y2;
		}
		else {
			canh = abs(dx);
			mPoint[1].first = X1;
			mPoint[1].second = Y1 + ((dy > 0) ? canh : -canh);
			mPoint[2].first = X2;
			mPoint[2].second = mPoint[1].second;
			mPoint[3].first = X2;
			mPoint[3].second = Y1;
		}
	}
	// update points inside shape
	void updatePoint() {
		int XT = (mPoint[0].first + mPoint[2].first) / 2;
		int YT = (mPoint[0].second + mPoint[2].second) / 2;

		UpdatePoint(XT, YT);
	}
 };

#endif
