#pragma once

#ifndef _LINE_H_
#define _LINE_H_

#include "Shape.h"
#include "Point.h"

class Line : public Shape {
private:
	vector<pair<int, int>> mPoint;
public:
	Line() {
	}
	Line(int x1, int y1, int x2, int y2) {
		mPoint.resize(2);
		mPoint[0].first = x1;
		mPoint[0].second = y1;
		mPoint[1].first = x2;
		mPoint[1].second = y2;
	}
	Line(const Line& p) {
		mPoint.resize(2);
		mPoint[0].first = p.mPoint[0].first;
		mPoint[0].second = p.mPoint[0].second;
		mPoint[1].first = p.mPoint[1].first;
		mPoint[1].second = p.mPoint[1].second;
	}
	virtual ~Line() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() { return 0; }
	int getB() { return 0; }
	int getIDShape() {
		return 1;
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
	// ve duong thang bang DDA
	void lineDDA(int X1, int Y1, int X2, int Y2) {
		int  dx = X2 - X1, dy = Y2 - Y1;
		float x_inc, y_inc;
		float step = max(abs(dx), abs(dy));
		x_inc = dx / step;
		y_inc = dy / step;
		float x = X1, y = Y1; // Khoi tao cac gia tri ban dau	
		Point(x, y).setPixel();

		int k = 1;
		while (k <= step) {
			k++;
			x += x_inc;
			y += y_inc;
			Point(round(x), round(y)).setPixel();
		}
	}
	// ve duong vien
	void draw() {
		lineDDA(mPoint[0].first, mPoint[0].second, mPoint[1].first, mPoint[1].second);
	}
	// tao hinh luc ve
	void create() {
		mPoint.resize(2);
		mPoint[0].first = X1;
		mPoint[1].first = X2;
		mPoint[0].second = Y1;
		mPoint[1].second = Y2;
	}
	void updatePoint() {
		return;
	}
};

#endif
