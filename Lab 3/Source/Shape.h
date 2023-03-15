#pragma once

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "Point.h"
#include "Header.h"

// ham thuan ao chua shape
class Shape {
public:
public:
	Shape(){}
	Shape(const Shape& p) {}
	virtual ~Shape() {}
	// getter
	virtual int getIDShape() = 0;
	virtual vector<pair<int, int>> getPoint() = 0;
	virtual int getR() = 0;
	virtual int getA() = 0;
	virtual int getB() = 0;
	// setter
	virtual void setPoint(vector<pair<int, int>> points) = 0;
	virtual void setR(int r) = 0;
	virtual void setA(int a) = 0;
	virtual void setB(int b) = 0;
	// ve duong vien
	virtual void draw() = 0;
	// tao hinh luc ve
	virtual void create() = 0;
	// update points inside shape
	virtual void updatePoint() = 0;

};

#endif
