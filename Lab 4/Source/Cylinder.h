#pragma once

#ifndef _CYLINDER_H_
#define _CYLINDER_H_

#include "Shape.h"

class Cylinder : public Shape
{
private:
	double mRadius = 1;
	double mHeight = 2;
	int mSlices = 50;
	int mStacks = 50;
	Point mCenter;
public:
	Cylinder();
	Cylinder(int textureIndex);
	~Cylinder();
	void draw();

};

Cylinder::Cylinder()
{
}

Cylinder::Cylinder(int textureIndex) : Shape(textureIndex) {}

Cylinder::~Cylinder()
{
}

void Cylinder::draw()
{
	// setup
	glLoadIdentity(); // Reset the model-view matrix
	glTranslatef(1.0f, 1.0f, -7.0f); // Move right and into the screen
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(angle, 1.0f, 0.0f, 1.0f);

	//glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
	glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

	// around
	//glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < mStacks; i++) {
		double y1 = mHeight / mStacks * i;
		double y2 = mHeight / mStacks * (i + 1);
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= mSlices; j++) {
			double theta = (2 * PI) / mSlices * j;
			double sinTheta = sin(theta);
			double cosTheta = cos(theta);

			double x = cosTheta;
			double z = sinTheta;

			//glNormal3d(x, 0, z);
			glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * (i + 1));
			glVertex3f(mRadius * x, y2, mRadius * z);

			glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * i);
			glVertex3f(mRadius * x, y1, mRadius * z);
		}
		glEnd();
	}


	// top
	//glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	//glNormal3d(0, 0, -1);
	glTexCoord2d(0.5, 0.5);
	glVertex3f(0, mHeight, 0);
	for (int i = 0; i <= mSlices; i++) {
		double theta = (2 * PI) / mSlices * i;
		double sinTheta = sin(theta);
		double cosTheta = cos(theta);

		double x = cosTheta;
		double z = sinTheta;

		//glNormal3d(0, 0, -1);
		glTexCoord2d(0.5 * (1 + x * mRadius), 0.5 * (1 + z * mRadius));
		glVertex3f(mRadius * x, mHeight, mRadius * z);
	}
	glEnd();

	// bottom
	glBegin(GL_TRIANGLE_FAN);
	//glNormal3d(0, 0, -1);
	glTexCoord2d(0.5, 0.5);
	glVertex3f(0, 0, 0);
	for (int i = 0; i <= mSlices; i++) {
		double theta = (2 * PI) / mSlices * i;
		double sinTheta = sin(theta);
		double cosTheta = cos(theta);

		double x = cosTheta;
		double z = sinTheta;

		//glNormal3d(0, 0, -1);
		glTexCoord2d(0.5 * (1 + x * mRadius), 0.5 * (1 + z * mRadius));
		glVertex3f(mRadius * x, 0, mRadius * z);
	}
	glEnd();
}

#endif