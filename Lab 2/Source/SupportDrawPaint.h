#pragma once
#ifndef _SUPPORTDRAW_H_
#define _SUPPORTDRAW_H_

#include "Header.h"

std::chrono::high_resolution_clock::time_point timeIs;
std::chrono::duration<double> timeDraw;


// tao ma mau
RGBColor createColor(int code, unsigned char r, unsigned char g, unsigned char b)
{
    RGBColor newColor;
    newColor.code = code; // 0: white, 1: black, 2: green, 3: red, 4: yellow
    newColor.r = r;
    newColor.g = g;
    newColor.b = b;
    return newColor;
}

// put pixel len man hinh
void PutPixel(int x, int y, RGBColor color)
{
    glColor3f(color.r, color.g, color.b);
    glVertex2i(x, y);
}

// set pixel, neu hinh da ve xong thi luu vao pixelNotWhite
void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    // hinh cuoi cung
    if (check == 2) {
        pixelNotWhite[{x, y}] = 1;
    }
    glEnd();
}

// ho tro ve hinh ellipse
void put4pixel(int xCenter, int yCenter, int x, int y)
{
    setPixel(xCenter + x, yCenter + y);
    setPixel(xCenter - x, yCenter + y);
    setPixel(xCenter + x, yCenter - y);
    setPixel(xCenter - x, yCenter - y);
}

// ho tro ve hinh tron
void put8pixel(int xCenter, int yCenter, int x, int y)
{
    setPixel(x + xCenter, y + yCenter);
    setPixel(-x + xCenter, y + yCenter);
    setPixel(x + xCenter, -y + yCenter);
    setPixel(-x + xCenter, -y + yCenter);
    setPixel(y + xCenter, x + yCenter);
    setPixel(-y + xCenter, x + yCenter);
    setPixel(y + xCenter, -x + yCenter);
    setPixel(-y + xCenter, -x + yCenter);
}

// put nhung pixel khong phai mau trang len man hinh glut
void pulPixelNotWhite()
{
    glBegin(GL_POINTS);
    map<pair<int, int>, int>::iterator i;
    for (i = pixelNotWhite.begin(); i != pixelNotWhite.end(); i++) {
        if (i->second == 1)
            PutPixel(i->first.first, i->first.second, B_Color);
        else if (i->second == 2)
            PutPixel(i->first.first, i->first.second, G_Color);
        else if (i->second == 3)
            PutPixel(i->first.first, i->first.second, R_Color);
        else if (i->second == 4)
            PutPixel(i->first.first, i->first.second, Y_Color);
    }
    glEnd();
    glutSwapBuffers();
}

// lay thoi gian hien tai, ho tro tinh thoi gian to mau
void getTime() {
    setPixel(-100, -100);
    timeIs = std::chrono::high_resolution_clock::now();

}

// dung tinh thoi gian, ho tro tinh thoi gian to mau
double stopTime() {
    timeDraw = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - timeIs);
    return 1.0 * timeDraw.count();
}

#endif
