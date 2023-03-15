#pragma once

#ifndef _POINT_H_
#define _POINT_H_

#include "Header.h"

class Point
{
private:
	GLfloat mX;
	GLfloat mY;
	GLfloat mZ;
public:
	Point() {}
	~Point();
	Point(GLfloat x, GLfloat y, GLfloat z);
	GLfloat getX();
	GLfloat getY();
	GLfloat getZ();
	void setPixel();
};

Point::~Point()
{
}

Point::Point(GLfloat x, GLfloat y, GLfloat z) {
	this->mX = x;
	this->mY = y;
	this->mZ = z;
}

GLfloat Point::getX()
{
	return mX;
}

GLfloat Point::getY()
{
	return mY;
}

GLfloat Point::getZ()
{
	return mX;
}

void Point::setPixel()
{
	//glBegin(GL_POINT);
	cout << this->mX << " " << this->mY << " " << this->mZ << "\n";
	glVertex3f(this->mX, this->mY, this->mZ);
	//glEnd();
}
#endif
