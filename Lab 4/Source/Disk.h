#pragma once

#ifndef _DISK_H_
#define _DISK_H_

#include "Shape.h"

class Disk : public Shape
{
private:
    double mRadius = 1;
    double mHeight = 2;
    int mSlices = 50;
    int mStacks = 50;
    Point mCenter;
public:
    Disk();
    Disk(int textureIndex);
    ~Disk();
    void draw();

};

Disk::Disk()
{
}

Disk::Disk(int textureIndex) : Shape(textureIndex) {}

Disk::~Disk()
{
}

void Disk::draw() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-3.0f, -1.0f, -7.0f); // Move right and into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 0.0f, 1.0f, 1.0f);

    //glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
    glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

    // draw upper face disk
    //glNormal3d(0, 0, 1);
    for (int i = 0; i < mStacks; i++) {
        double radius1 = ((double)i / mStacks) * mRadius;
        double radius2 = ((double)(i + 1) / mStacks) * mRadius;

        glBegin(GL_QUAD_STRIP);
        for (int i = 0; i <= mSlices; ++i) {
            double theta = (2 * PI) / mSlices * i;
            double sinTheta = sin(theta);
            double cosTheta = cos(theta);

            double x = cosTheta;
            double y = sinTheta;

            glNormal3d(0, 0, -1);
            glTexCoord2d(0.5 * (1 + x * radius1), 0.5 * (1 + y * radius1));
            glVertex3f(radius1 * x, radius1 * y, 0);

            glTexCoord2d(0.5 * (1 + x * radius2), 0.5 * (1 + y * radius2));
            glVertex3f(radius2 * x, radius2 * y, 0);

        }
        glEnd();
    }
}

#endif