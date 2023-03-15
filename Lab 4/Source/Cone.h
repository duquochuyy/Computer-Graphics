#pragma once

#ifndef _CONE_H_
#define _CONE_H_

#include "Shape.h"

class Cone : public Shape
{
private:
    double mRadius = 1;
    double mHeight = 2;
    int mSlices = 50;
    int mStacks = 50;
    Point mCenter;
public:
    Cone();
    Cone(int textureIndex);
    ~Cone();
    void draw();

};

Cone::Cone()
{
}

Cone::Cone(int textureIndex) : Shape(textureIndex) {}

Cone::~Cone()
{
}

void Cone::draw() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(3.0f, 1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 1.0f, 0.0f, 1.0f);

    //glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
    glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

    // draw cone around 
    //glColor3f(1.0f, 0.5f, 0.0f); // Orange
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
            double ny = mRadius / mHeight;
            // length edge around 
            double length = sqrt(x * x + ny * ny + z * z);

            double radius1 = (1 - ((double)i / mStacks)) * mRadius;
            double radius2 = (1 - ((double)(i + 1) / mStacks)) * mRadius;

            //glNormal3d(x / length, ny / length, z / length);

            glTexCoord2d(1.0 / mSlices * j, 1.0 / mSlices * i);
            glVertex3f(radius1 * x, y2, radius1 * z);

            glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * (i + 1));
            glVertex3f(radius2 * x, y1, radius2 * z);

        }
        glEnd();
    }

    // draw bottom 
    //glColor3f(0.0f, 1.0f, 0.0f); // Green
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