#pragma once

#ifndef _MENU_H_
#define _MENU_H_

#include "Header.h"
#include "MouseAndKeyboard.h"
#include "Support.h"

// menu chon hinh/ mau
void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    }
    else {
        value = num;
        check = 0;
        //checkSelected = 0;
    }
    glutPostRedisplay();
}
void createMenu(void) {
    submenu_id_tamgiac = glutCreateMenu(menu);
    glutAddMenuEntry("Vuong can", 2);
    glutAddMenuEntry("Deu", 3);


    submenu_id_tugiac = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh chu nhat", 4);
    glutAddMenuEntry("Hinh vuong", 5);


    submenu_id_oval = glutCreateMenu(menu);
    glutAddMenuEntry("Hinh tron", 6);
    glutAddMenuEntry("Elip", 7);


    submenu_id_dagiacdeu = glutCreateMenu(menu);
    glutAddMenuEntry("Ngu giac deu", 8);
    glutAddMenuEntry("Luc giac deu", 9);


    submenu_id_hinhkhac = glutCreateMenu(menu);
    glutAddMenuEntry("Mui ten", 10);
    glutAddMenuEntry("Ngoi sao", 11);


    submenu_id_dau = glutCreateMenu(menu);
    glutAddMenuEntry("Cong", 12);
    glutAddMenuEntry("Tru", 13);
    glutAddMenuEntry("Nhan", 14);
    glutAddMenuEntry("Chia", 15);


    submenu_id_tomau = glutCreateMenu(menu);
    glutAddMenuEntry("Xanh", 16);
    glutAddMenuEntry("Do", 17);
    glutAddMenuEntry("Vang", 18);

    //submenu_id_chonhinh = glutCreateMenu(menu);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Duong thang", 1);
    glutAddSubMenu("Tam giac", submenu_id_tamgiac);
    glutAddSubMenu("Tu giac", submenu_id_tugiac);
    glutAddSubMenu("Oval", submenu_id_oval);
    glutAddSubMenu("Da giac deu", submenu_id_dagiacdeu);
    glutAddSubMenu("Hinh khac", submenu_id_hinhkhac);
    glutAddSubMenu("Dau", submenu_id_dau);
    glutAddSubMenu("To mau", submenu_id_tomau);
    //glutAddSubMenu("Chon hinh", submenu_id_chonhinh);
    glutAddMenuEntry("Chon hinh", 19);

    glutAddMenuEntry("Thoat", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// xu li click chuot
void display(void) {
    Shape* shape = NULL;
    if (value == 1) {
        shape = new Line();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 2) {
        shape = new IsoscelesRightTriangle();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 3) {
        shape = new EquilateralTriangle();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 4) {
        shape = new Rectangle1();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 5) {
        shape = new Square();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 6) {
        shape = new Circle();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 7) {
        shape = new Elip();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 8) {
        shape = new Pentagon();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 9) {
        shape = new Hexagon();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 10) {
        shape = new Arrow();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 11) {
        shape = new Star();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 12) {
        shape = new Plus();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 13) {
        shape = new Minus();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 14) {
    shape = new Multiply();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 15) {
        shape = new Divide();
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                shape->create();
                shape->draw();
                //drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            // tao duoc cac dinh hinh vuong
            shape->create();
            // dua hinh vuong vao listShape
            listShape.putShape(shape);
            // lay index cua hinh vuong
            indexShape = listShape.getSize() - 1;
            // ve cac duong vien cua hinh vuong
            shape->draw();
            // cap nhap cac diem nam ben trong duong vien
            shape->updatePoint();
            // dua cac pixel len lai man hinh
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 16) {
    // to mau xanh
        F_Color = createColor(2, 0, 255, 0);
        PaintShape(F_Color);
    }
    else if (value == 17) {
    // to mau do
        F_Color = createColor(3, 255, 0, 0);
        PaintShape(F_Color);
    }
    else if (value == 18) {
    // to mau vang
        F_Color = createColor(4, 255, 255, 0);
        PaintShape(F_Color);
    }
    else if (value == 19) {
        //F_Color = createColor(5, 0, 0, 0);
        glutMouseFunc(XulyMouseChonHinh);
        checkSelected = 1;
    }
    else {
        glutKeyboardFunc(XulyNhanNormal);
        glutSpecialFunc(XulyNhanSpecial);
        //glutMouseFunc(XulyMouseTest);
    }
    glFlush();
};

#endif