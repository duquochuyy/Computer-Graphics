#pragma once

#ifndef _POINT_H_
#define _POINT_H_

#include "Header.h"

// doi tuong hinh tron
class Point {
private:
	int mX;
	int mY;
public:
	Point() {
		this->mX = 0;
		this->mY = 0;
	}
	Point(int x, int y) {
		this->mX = x;
		this->mY = y;
	}
	Point(const Point& p) {
		this->mX = p.mX;
		this->mY = p.mY;
	}
	~Point() {}
	// set pixel
	void setPixel() {
		glBegin(GL_POINTS);
		glVertex2i(this->mX, this->mY);
		if (check == 2) {
			pixelNotWhite[{this->mX, this->mY}] = B_Color;
			if (((!checkPointInShape[{this->mX, this->mY}].empty()) && (checkPointInShape[{this->mX, this->mY}].back().first != indexShape)) || (checkPointInShape[{this->mX, this->mY}].empty()))
				checkPointInShape[{this->mX, this->mY}].push_back({ indexShape, B_Color });
		}
		glEnd();
	}
	// put pixel len man hinh
	void putPixel(RGBColor color) {
		//glColor3f(color.r, color.g, color.b);
		glColor3f(color.r / 255.0, color.g / 255.0, color.b / 255.0);
		glVertex2i(mX, mY);
	}
};

// cap nhap nhung diem nao thuoc hinh
void UpdatePoint(int XT, int YT)
{
	RGBColor currentColor;
	vector<pair<int, int>> ToaDo;
	pair<int, int> currentToaDo;
	int indexCurrent;
	ToaDo.push_back({ XT, YT });
	int codeColor;
	// khi Toa Do rong -> da check xong cac point thuoc shape
	while (!ToaDo.empty()) {
		currentToaDo = ToaDo.back();
		ToaDo.pop_back();
		if (((!checkPointInShape[currentToaDo].empty()) && (checkPointInShape[currentToaDo].back().first != indexShape)) || (checkPointInShape[currentToaDo].empty())) {
			checkPointInShape[currentToaDo].push_back({ indexShape, W_Color });
			for (int i = 0; i < 4; i++) {
				if (currentToaDo.first + dr[i] >= 0 && currentToaDo.first + dr[i] < width && currentToaDo.second + dc[i] >= 0 && currentToaDo.second + dc[i] < height) {
					ToaDo.push_back({ currentToaDo.first + dr[i], currentToaDo.second + dc[i] });
				}
			}
		}
	}
}

#endif