#pragma once

#ifndef _LISTSHAPE_H_
#define _LISTSHAPE_H_

#include "Cylinder.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cone.h"
#include "Disk.h"
#include "Ring.h"
#include "Hyperboloid.h"
#include "Paraboloid.h"

class ListShape
{
public:
	vector<Shape*> shapes;
	ListShape();
	~ListShape();
	void insertShape(Shape* shape);
	void createListShape();
	void drawListShape(GLfloat angle);
};

ListShape::ListShape()
{
}

ListShape::~ListShape()
{
}

void ListShape::insertShape(Shape* shape)
{
	shapes.push_back(shape);
}

void ListShape::createListShape()
{
	shapes.push_back(new Cube(0));
	shapes.push_back(new Sphere(1));
	shapes.push_back(new Cylinder(0));
	shapes.push_back(new Cone(1));
	shapes.push_back(new Disk(0));
	shapes.push_back(new Ring(1));
	shapes.push_back(new Hyperboloid(0));
	shapes.push_back(new Paraboloid(1));
}

void ListShape::drawListShape(GLfloat angle)
{
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i]->setAngle(angle);
		shapes[i]->draw();
	}
}

#endif
