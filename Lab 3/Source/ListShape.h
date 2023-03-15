#pragma once

#ifndef _LISTSHAPE_H_
#define _LISTSHAPE_H_

#include "Line.h"
#include "IsoscelesRightTriangle.h"
#include "EquilateralTriangle.h"
#include "Rectangle1.h"
#include "Square.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Arrow.h"
#include "Star.h"
#include "Plus.h"
#include "Minus.h"
#include "Multiply.h"
#include "Divide.h"

// doi luong ListShape chua cac hinh duoc ve
class ListShape {
private:
	// index shape tinh tu 0
	vector<Shape*> listShape;
public:
	ListShape() {}
	~ListShape() {
		for (int i = 0; i < listShape.size(); i++)
			delete listShape[i];
	}
	Shape* getShape(int index) {
		return listShape[index];
	}
	int getIDShape(int index) {
		return listShape[index]->getIDShape();
	}
	int getSize() {
		return listShape.size();
	}
	void putShape(Shape* shape) {
		listShape.push_back(shape);
	}
};

#endif
