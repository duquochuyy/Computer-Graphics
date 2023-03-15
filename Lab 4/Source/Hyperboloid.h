#pragma once

#ifndef _HYPERBOLOID_H_
#define _HYPERBOLOID_H_

#include "Shape.h"

class Hyperboloid : public Shape
{
private:
    double a = 1, b = 1, c = 1;
    double mHeight = 2;
    int mSlices = 50;
    int mStacks = 50;
    Point mCenter;
public:
    Hyperboloid();
    Hyperboloid(int textureIndex);
    ~Hyperboloid();
    void draw();

};

Hyperboloid::Hyperboloid()
{
}

Hyperboloid::Hyperboloid(int textureIndex) : Shape(textureIndex) {}

Hyperboloid::~Hyperboloid()
{
}

void Hyperboloid::draw() {
    int a = 1, b = 1, c = 1;
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(1.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 1.0f, 0.0f, 1.0f);

    //glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
    glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

    // draw Hyperboloid
    //glColor3f(1.0f, 0.0f, 1.0f);
    for (int i = 0; i < mStacks; i++) {
        double y1 = (mHeight / mStacks * i) + (-mHeight / 2.0);
        double y2 = (mHeight / mStacks * (i + 1)) + (-mHeight / 2.0);

        double C1 = 1.0 + (y1 * y1) / (c * c);
        double C2 = 1.0 + (y2 * y2) / (c * c);
        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= mSlices; j++) {
            double theta = (2 * PI) / mSlices * j;
            double sinTheta = sin(theta);
            double cosTheta = cos(theta);

            double x = a * cosTheta;
            double z = b * sinTheta;

            //glNormal3d(x, y, 0);

            glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * i);
            glVertex3f(C1 * x, y1, C1 * z);

            glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * (i + 1));
            glVertex3f(C2 * x, y2, C2 * z);
        }
        glEnd();
    }

    // draw top side
    //glColor3f(0.0f, 1.0f, 0.0f); // Green
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0, 0, 1);
    glTexCoord2d(0.5, 0.5);
    glVertex3f(0, mHeight / 2, 0);
    for (int i = 0; i <= mSlices; ++i) {
        double C = 1.0 + (mHeight / 2) * (mHeight / 2) / (c * c);

        double theta = (2 * PI) / mSlices * i;
        double sinTheta = sin(theta);
        double cosTheta = cos(theta);

        double x = a * cosTheta;
        double z = b * sinTheta;

        glVertex3f(C * x, mHeight / 2, C * z);
        glTexCoord2d(0.5 * (1 + cosTheta), 0.5 * (1 + sinTheta));
    }
    glEnd();

    // draw bottom side
    glBegin(GL_TRIANGLE_FAN);
    glNormal3d(0, 0, -1);
    glTexCoord2d(0.5, 0.5);
    glVertex3f(0, -mHeight / 2, 0);
    for (int i = 0; i <= mSlices; ++i)
    {
        double C = 1.0 + (-mHeight / 2) * (-mHeight / 2) / (c * c);

        double theta = (2 * PI) / mSlices * i;
        double sinTheta = sin(theta);
        double cosTheta = cos(theta);

        double x = a * cosTheta;
        double z = b * sinTheta;

        glVertex3f(C * x, -mHeight / 2, C * z);
        glTexCoord2d(0.5 * (1 + cosTheta), 0.5 * (1 + sinTheta));
    }
    glEnd();
}

#endif