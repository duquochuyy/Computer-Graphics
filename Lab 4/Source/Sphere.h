#pragma once

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Shape.h"

class Sphere : public Shape
{
private:
    double mRadius = 1;
    double mHeight = 2;
    int mSlices = 50;
    int mStacks = 50;
    Point mCenter;
public:
    Sphere();
    Sphere(int textureIndex);
    ~Sphere();
    void draw();

};

Sphere::Sphere()
{
}

Sphere::Sphere(int textureIndex) : Shape(textureIndex) {}

Sphere::~Sphere()
{
}

void Sphere::draw() {
    glLoadIdentity(); // Reset the model-view matrix
    glTranslatef(-1.0f, 1.0f, -7.0f); // Move into the screen
    glScalef(0.5f, 0.5f, 0.5f);
    glRotatef(angle, 1.0f, 0.0f, 1.0f);

    //glBindTexture(GL_TEXTURE_2D, Texture::listTexture[textureIndex]);
    glBindTexture(GL_TEXTURE_2D, listTexture[textureIndex]);

    // lat: latitude, lon: longitude
    for (int i = 0; i < mStacks; i++) {
        double lat1 = (PI / mStacks) * i - PI / 2.0;
        double lat2 = (PI / mStacks) * (i + 1) - PI / 2.0;
        double sinlat1 = sin(lat1);
        double coslat1 = cos(lat1);
        double sinlat2 = sin(lat2);
        double coslat2 = cos(lat2);
        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= mSlices; j++) {
            double lon = (2 * PI / mSlices) * j;
            double sinlon = sin(lon);
            double coslon = cos(lon);
            double x1 = coslon * coslat1;
            double y1 = sinlon * coslat1;
            double z1 = sinlat1;
            double x2 = coslon * coslat2;
            double y2 = sinlon * coslat2;
            double z2 = sinlat2;

            //glNormal3d(x1, y1, z1);
            glTexCoord2d(1.0 / mSlices * j, 1.0 / mStacks * i);
            glVertex3d(mRadius * x1, mRadius * y1, mRadius * z1);

            //glNormal3d(x2, y2, z2);
            glTexCoord2d(1.0 / mSlices * j, 1.0 / mSlices * (i + 1));
            glVertex3d(mRadius * x2, mRadius * y2, mRadius * z2);
        }
        glEnd();
    }
}

#endif