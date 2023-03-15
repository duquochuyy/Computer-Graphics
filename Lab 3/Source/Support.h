#pragma once

#ifndef _SUPPORT_H_
#define _SUPPORT_H_

#include "Header.h"
#include "ListShape.h"
#include "Matrix.h"
#include "Timer.h"

// danh sach cac hinh ve
ListShape listShape;
// ma tran bien doi
Matrix myMatrix;
// thoi gian
Timer timer;

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

// dua cac pixel khac mau trang len man hinh
void pulPixelNotWhite()
{
    glBegin(GL_POINTS);
    map<pair<int, int>, RGBColor>::iterator i;
    for (i = pixelNotWhite.begin(); i != pixelNotWhite.end(); i++) {
            Point(i->first.first, i->first.second).putPixel(i->second);
    }
    glEnd();
    glutSwapBuffers();
}

// to mau hinh
void PaintShape(RGBColor F_Color)
{
    int currentX;
    int currentY;
    timer.getTime();
    map<pair<int, int>, vector<pair<int, RGBColor>>>::iterator i;
    int checkPaint = 0;
    for (i = checkPointInShape.begin(); i != checkPointInShape.end(); i++) {
        // toa do 1 pixel da duoc ve hinh
        currentX = i->first.first;
        currentY = i->first.second;
        // xac dinh vung pixel duoc chon
        if (pixelNotWhite[{currentX, currentY}].code == Selected_Color.code) {
            checkPaint = 1;
            // thay doi mau cua doi tuong tren man hinh glut
            pixelNotWhite[{currentX, currentY}] = F_Color;
            // thay doi mau cua doi tuong hinh duoc chon
            checkPointInShape[{currentX, currentY}].back().second = F_Color;
        }
    }
    if (checkPaint == 1)
        cout << "Thoi gian to mau: " << 1000.0 * timer.stopTime() << " (ms)" << endl;
    pulPixelNotWhite();
}

// to mau trong qua trinh transform
void PaintToTransform()
{
    int currentX;
    int currentY;
    map<pair<int, int>, vector<pair<int, RGBColor>>>::iterator i;
    for (i = checkPointInShape.begin(); i != checkPointInShape.end(); i++) {
        // toa do 1 pixel da duoc ve hinh
        currentX = i->first.first;
        currentY = i->first.second;
        // xac dinh vung pixel duoc chon
        if (((i->second).back().first == indexShape)
            && ((i->second).back().second.code != 1)) {
            if (colorShapeSelected.code != 0) 
                pixelNotWhite[{currentX, currentY}] = colorShapeSelected;
            (i->second).back().second = colorShapeSelected;
        }
        else
            pixelNotWhite[{currentX, currentY}] = checkPointInShape[{currentX, currentY}].back().second;
    }
    pulPixelNotWhite();
}

// chon hinh de to mau/ transform
void SelectShape(int x, int y)
{
    // lay hinh tai vi tri click chuot
    int currentX;
    int currentY;    // vi tri click chua co hinh
    if (checkPointInShape[{x, y}].empty()) {
        map<pair<int, int>, vector<pair<int, RGBColor>>>::iterator i;
        for (i = checkPointInShape.begin(); i != checkPointInShape.end(); i++) {
            currentX = i->first.first;
            currentY = i->first.second;
            if (!(i->second).empty())
                pixelNotWhite[{currentX, currentY}] = (i->second).back().second;
        }
        return;
    }
    int indexShapeCurrent = checkPointInShape[{x, y}].back().first;
    RGBColor currentColor = checkPointInShape[{x, y}].back().second;
    indexShape = indexShapeCurrent;
    colorShapeSelected = currentColor;
    map<pair<int, int>, vector<pair<int, RGBColor>>>::iterator i;
    for (i = checkPointInShape.begin(); i != checkPointInShape.end(); i++) {
        // toa do 1 pixel da duoc ve hinh
        currentX = i->first.first;
        currentY = i->first.second;
        // cap nhap hinh duoc chon la hinh tren cung
        for (int j = 0; j < (i->second).size(); j++) {
            if ((i->second)[j].first == indexShapeCurrent) {
                if ((i->second)[j].second.code == 1) {
                    (i->second).erase(i->second.begin() + j);
                    (i->second).push_back({ indexShapeCurrent, B_Color });
                }
                else {
                    (i->second).erase(i->second.begin() + j);
                    (i->second).push_back({ indexShapeCurrent, currentColor });
                }
                break;
            }
        }
        // pixel nay can to mau
        // reset ma mau cua pixel do
        if (!(i->second).empty()) {
            if (((i->second).back().first == indexShapeCurrent)
                && ((i->second).back().second.code != 1)) {
                pixelNotWhite[{currentX, currentY}] = Selected_Color;
            }
            else {
                pixelNotWhite[{currentX, currentY}] = (i->second).back().second;
            }
        }
    }
}

// clear man hinh luc transform
void ClearShapeSelected()
{
    //cout << pixelNotWhite.size() << endl;
    map<pair<int, int>, vector<pair<int, RGBColor>>>::iterator i;
    vector<pair<int, int>> emptyShape;
    for (i = checkPointInShape.begin(); i != checkPointInShape.end(); i++) {
        if ((i->second).back().first == indexShape) {
            (i->second).pop_back();
            if ((i->second).size() > 0) {
                pixelNotWhite[{i->first.first, i->first.second}] = (i->second).back().second;
            }
            else {
                emptyShape.push_back({ i->first.first, i->first.second });
                pixelNotWhite.erase({ i->first.first, i->first.second });
            }
        }
    }
    for (int j = 0; j < emptyShape.size(); j++)
        checkPointInShape.erase(emptyShape[j]);
}

#endif