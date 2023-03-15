
#ifndef _ELIP_H_
#define _ELIP_H_

#include "Shape.h"
#include "Point.h"
#include "Line.h"

// ve doi tuong elip
class Elip : public Shape {
private:
	vector<pair<int, int>> mPoint;
	int mA;
	int mB;
public:
	Elip() {
	}
	Elip(int xT, int yT, int a, int b) {
		mPoint.resize(1);
		mPoint[0].first = xT;
		mPoint[0].second = yT;
		mA = a;
		mB = b;
	}
	Elip(const Elip& p) {
		mPoint.resize(1);
		mPoint[0].first = p.mPoint[0].first;
		mPoint[0].second = p.mPoint[0].second;
		mA = p.mA;
		mB = p.mB;
	}
	virtual ~Elip() {}
	//getter
	vector<pair<int, int>> getPoint() {
		return mPoint;
	}
	int getR() { return 0; }
	int getA() {
		return mA;
	}
	int getB() {
		return mA;
	}
	int getIDShape() {
		return 7;
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
	void setA(int a) { mA = a; }
	void setB(int b) { mB = b; }
	void put4pixel(int xCenter, int yCenter, int x, int y)
	{
		Point(xCenter + x, yCenter + y).setPixel();
		Point(xCenter - x, yCenter + y).setPixel();
		Point(xCenter + x, yCenter - y).setPixel();
		Point(xCenter - x, yCenter - y).setPixel();
	}
	// ve hinh Elip bang midpoint
	void ElipMidPoint(int xT, int yT, int a, int b)
	{
		int x = 0, y = b;
		float p1 = b * b - a * a * b + a * a * 0.25;
		put4pixel(xT, yT, x, y);
		while (x * b * b <= y * a * a) {
			if (p1 < 0)
				p1 += b * b * (2 * x + 3);
			else {
				y--;
				p1 += b * b * (2 * x + 3) - a * a * (2 * y - 2);
			}
			x++;
			put4pixel(xT, yT, x, y);
		}


		float p2 = (x + 0.5) * (x + 0.5) * b * b + (y - 1) * (y - 1) * a * a - a * a * b * b;
		put4pixel(xT, yT, x, y);
		while (y >= 0) {
			if (p2 > 0)
				p2 -= a * a * (2 * y - 3);
			else {
				x++;
				p2 += b * b * (2 * x + 2) - a * a * (2 * y - 3);
			}
			y--;
			put4pixel(xT, yT, x, y);
		}
	}
	// ve duong vien
	void draw() {
		if (mA > 0 && mB > 0)
			ElipMidPoint(mPoint[0].first, mPoint[0].second, mA, mB);
	}
	// tao hinh luc ve
	void create() {
		mPoint.resize(1);
		// xac dinh tam, 1/2 truc lon, 1/2 truc nho
		mPoint[0].first = (X1 + X2) / 2;
		mPoint[0].second = (Y1 + Y2) / 2;
		mA = abs(mPoint[0].first - X1);
		mB = abs(mPoint[0].second - Y1);
	}
	// update points inside shape
	void updatePoint() {
		int XT = mPoint[0].first;
		int YT = mPoint[0].second;

		UpdatePoint(XT, YT);

	}
};

#endif
