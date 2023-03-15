#pragma once

#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "Header.h"
#include "Support.h"

// xu li su kien chuot va ban phim
void XulyMouseVeHinh(int button, int state, int x, int y)
{
    glColor3ub(0, 0, 0);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && check == 0) {
        X1 = x;
        Y1 = height - y;
        check = 1;
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && check == 1) {
        check = 2;
        X2 = x;
        Y2 = height - y;
        glutPostRedisplay();
    }
}

// kiem tra su kien keo chuot
void myMotion(int x, int y)
{
    X2 = x;
    Y2 = height - y;
    glutPostRedisplay();
}

// click de chon hinh 
void XulyMouseChonHinh(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // hien hinh duoc chon len tren cung
        //upShapeToSelect(x, height - y);
        //doi mau hinh duoc chon
        SelectShape(x, height - y);
        pulPixelNotWhite();
        glFlush();
    }
}

// nhan phim de bien doi hinh
void XulyNhanNormal(unsigned char key, int x, int y)
{
    // lay thong tin hinh duoc chon
    vector<pair<int, int>> pointShape;
    int rCircle, aElip, bElip;
    Shape* shape = listShape.getShape(indexShape);
    pointShape = shape->getPoint();

    if (key == 'l') {
        // quay sang trai
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Rotate(1);
    }
    if (key == 'r') {
        // quay sang phai
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Rotate(359);
    }
    if (key == '-') {
        // quay sang trai
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Scale(0.9, 0.9);
    }
    if (key == '+' || key == '=') {
        // quay sang trai
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Scale(1.1, 1.1);
    }
    // thay doi toa do cac dinh
    pointShape = myMatrix.TransformPoints(pointShape);
    // thay doi diem cua shape
    shape->setPoint(pointShape);
    // cho phep luu hinh
    check = 2;
    // ve duong vien
    shape->draw();
    // update cac pixel thuoc shape
    shape->updatePoint();
    // update lai mau
    PaintToTransform();
    glFlush();
}

void XulyNhanSpecial(int key, int x, int y)
{
    // lay thong tin hinh duoc chon
    vector<pair<int, int>> pointShape;
    int rCircle, aElip, bElip;
    Shape* shape = listShape.getShape(indexShape);
    pointShape = shape->getPoint();

    switch (key) {
    case GLUT_KEY_UP:
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Translate(0.0, 1.0);
        // thay doi toa do cac dinh
        pointShape = myMatrix.TransformPoints(pointShape);
        // thay doi diem cua shape
        shape->setPoint(pointShape);
        // cho phep luu hinh
        check = 2;
        // ve duong vien
        shape->draw();
        // update cac pixel thuoc shape
        shape->updatePoint();
        // update lai mau
        PaintToTransform();
        break;
    case GLUT_KEY_DOWN:
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Translate(0.0, -1.0);
        // thay doi toa do cac dinh
        pointShape = myMatrix.TransformPoints(pointShape);
        // thay doi diem cua shape
        shape->setPoint(pointShape);
        // cho phep luu hinh
        check = 2;
        // ve duong vien
        shape->draw();
        // update cac pixel thuoc shape
        shape->updatePoint();
        // update lai mau
        PaintToTransform();
        break;
    case GLUT_KEY_RIGHT:
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Translate(1.0, 0.0);
        // thay doi toa do cac dinh
        pointShape = myMatrix.TransformPoints(pointShape);
        // thay doi diem cua shape
        shape->setPoint(pointShape);
        // cho phep luu hinh
        check = 2;
        // ve duong vien
        shape->draw();
        // update cac pixel thuoc shape
        shape->updatePoint();
        // update lai mau
        PaintToTransform();
        break;
    case GLUT_KEY_LEFT:
        ClearShapeSelected();
        glClear(GL_COLOR_BUFFER_BIT);
        myMatrix.Reset();
        myMatrix.Translate(-1.0, 0.0);
        // thay doi toa do cac dinh
        pointShape = myMatrix.TransformPoints(pointShape);
        // thay doi diem cua shape
        shape->setPoint(pointShape);
        // cho phep luu hinh
        check = 2;
        // ve duong vien
        shape->draw();
        // update cac pixel thuoc shape
        shape->updatePoint();
        // update lai mau
        PaintToTransform();
        break;
    }
    glFlush();
}


#endif