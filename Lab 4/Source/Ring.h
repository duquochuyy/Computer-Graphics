#pragma once

#ifndef _RING_H_
#define _RING_H_

#include "Shape.h"

class Ring : public Shape
{
private:
    double insideRadius = 0.5;
    double outsideRadius = 1;
    double mHeight = 2;
    int mSlices = 50;
    int mStacks = 50;
    Point mCenter;
public:
    Ring();
    Ring(int textureIndex);
    ~Ring();
    void draw();

};

Ring::Ring()
{
}

Ring::Ring(int textureIndex) : Shape(textureIndex) {}

Ring::~Ring()
{
}

void Ring::draw() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-1.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 1.0f, 0.0f, 1.0f);

    //glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
    glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

    // set radius
    double centerRadius = (insideRadius + outsideRadius) / 2.0;
    double tubeRadius = outsideRadius - centerRadius;

    //glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < mStacks; ++i) {
        double s1 = (double)i / mStacks;
        double s2 = (double)(i + 1) / mStacks;
        double theta1 = (2 * PI) * s1;
        double theta2 = (2 * PI) * s2;
        double centerSin1 = sin(theta1);
        double centerCos1 = cos(theta1);
        double centerSin2 = sin(theta2);
        double centerCos2 = cos(theta2);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= mSlices; ++j)
        {
            double t = (double)j / mSlices;
            double alpha = (2 * PI) * t;
            double cosAlpha = cos(alpha);
            double sinAlpha = sin(alpha);

            double x1 = centerCos1 * (centerRadius + tubeRadius * cosAlpha);
            double y1 = sinAlpha * tubeRadius;
            double z1 = centerSin1 * (centerRadius + tubeRadius * cosAlpha);

            //glNormal3d(centerCos1 * cosAlpha, centerSin1 * cosAlpha, sinAlpha);
            glTexCoord2d(s1, t);
            glVertex3d(x1, y1, z1);

            double x2 = centerCos2 * (centerRadius + tubeRadius * cosAlpha);
            double y2 = sinAlpha * tubeRadius;
            double z2 = centerSin2 * (centerRadius + tubeRadius * cosAlpha);

            //glNormal3d(centerCos2 * cosAlpha, centerSin2 * cosAlpha, sinAlpha);
            glTexCoord2d(s2, t);
            glVertex3d(x2, y2, z2);
        }
        glEnd();
    }
}

#endif