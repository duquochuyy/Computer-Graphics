#pragma once

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "Header.h"
#include "Point.h"
#include "Texture.h"

class Shape {
public:
	GLfloat angle = 0;
	GLfloat scale = 1;
	GLuint textureIndex = 0;
	Shape() {}
	Shape(int textureIndex);
	virtual ~Shape() {}
	virtual void draw() = 0;
	void setAngle(GLfloat angle);
};

Shape::Shape(int textureIndex)
{
	this->textureIndex = textureIndex;
}

void Shape::setAngle(GLfloat angle)
{
	this->angle = angle;
}


#endif