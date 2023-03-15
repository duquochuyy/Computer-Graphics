#pragma once

#ifndef _PARABOLOID_H_
#define _PARABOLOID_H_

#include "Shape.h"

class Paraboloid : public Shape
{
private:
    double a = 1, b = 1;
    double mHeight = 1;
    int mSlices = 50;
    int mStacks = 50;
    Point mCenter;
public:
    Paraboloid();
    Paraboloid(int textureIndex);
    ~Paraboloid();
    void draw();

};

Paraboloid::Paraboloid()
{
}

Paraboloid::Paraboloid(int textureIndex) : Shape(textureIndex) {}

Paraboloid::~Paraboloid()
{
}

void Paraboloid::draw() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(3.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 1.0f, 0.0f, 1.0f);

    //glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
    glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

    // draw Paraboloid
    for (int i = 0; i < mStacks; ++i) {
        double y1 = (mHeight / mStacks * i);
        double y2 = (mHeight / mStacks * (i + 1));

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= mSlices; ++j) {
            double theta = (2 * PI) / mSlices * j;
            double sinTheta = sin(theta);
            double cosTheta = cos(theta);

            double x = a * cosTheta;
            double z = b * sinTheta;

            glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * i);
            glVertex3f(y1 * x, y1 * y1, y1 * z);

            glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * (i + 1));
            glVertex3f(y2 * x, y2 * y2, y2 * z);

        }
        glEnd();
    }

    // draw bottom side
    //glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    //glNormal3d(0, 0, 1);
    glTexCoord2d(0.5, 0.5);
    glVertex3f(0, mHeight, 0);
    for (int i = 0; i <= mSlices; ++i)
    {
        double theta = (2 * PI) / mSlices * i;
        double sinTheta = sin(theta);
        double cosTheta = cos(theta);

        double x = a * cosTheta;
        double z = b * sinTheta;

        glVertex3f(mHeight * x, mHeight, mHeight * z);
        glTexCoord2d(0.5 * (1 + cosTheta), 0.5 * (1 + sinTheta));
    }
    glEnd();
}

#endif