#pragma once

#ifndef _MENU_H_
#define _MENU_H
#include "Header.h"
#include "SupportDrawPaint.h"
#include "Draw.h"
#include "Paint.h"

// kiem tra con dung menu ko
void menu(int num) {
    if (num == 0) {
        glutDestroyWindow(window);
        exit(0);
    }
    else {
        value = num;
        check = 0;
    }
    glutPostRedisplay();
}

// tao ra menu
// moi chuc nang tuong ung 1 value
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

    submenu_id_chonhinh = glutCreateMenu(menu);

    menu_id = glutCreateMenu(menu);
    glutAddMenuEntry("Duong thang", 1);
    glutAddSubMenu("Tam giac", submenu_id_tamgiac);
    glutAddSubMenu("Tu giac", submenu_id_tugiac);
    glutAddSubMenu("Oval", submenu_id_oval);
    glutAddSubMenu("Da giac deu", submenu_id_dagiacdeu);
    glutAddSubMenu("Hinh khac", submenu_id_hinhkhac);
    glutAddSubMenu("Dau", submenu_id_dau);
    glutAddSubMenu("To mau", submenu_id_tomau);
    glutAddSubMenu("Chon hinh", submenu_id_chonhinh);

    glutAddMenuEntry("Thoat", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// kiem tra gia tri value de ve hinh/ to mau / thoat
void display(void) {
    if (value == 1) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawDuongThang();
                pulPixelNotWhite();
            }
        }
        else {
            drawDuongThang();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 2) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawTamGiacVuongCan();
                pulPixelNotWhite();
            }
        }
        else {
            drawTamGiacVuongCan();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 3) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawTamGiacDeu();
                pulPixelNotWhite();
            }
        }
        else {
            drawTamGiacDeu();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 4) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawHinhChuNhat();
                pulPixelNotWhite();
            }
        }
        else {
            drawHinhChuNhat();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 5) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawHinhVuong();
                pulPixelNotWhite();
            }
        }
        else {
            drawHinhVuong();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 6) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawHinhTron();
                pulPixelNotWhite();
            }
        }
        else {
            drawHinhTron();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 7) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawElip();
                pulPixelNotWhite();
            }
        }
        else {
            drawElip();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 8) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawNguGiacDeu();
                pulPixelNotWhite();
            }
        }
        else {
            drawNguGiacDeu();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 9) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawLucGiacDeu();
                pulPixelNotWhite();
            }
        }
        else {
            drawLucGiacDeu();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 10) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawMuiTen();
                pulPixelNotWhite();
            }
        }
        else {
            drawMuiTen();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 11) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawNgoiSao();
                pulPixelNotWhite();
            }
        }
        else {
            drawNgoiSao();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 12) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawDauCong();
                pulPixelNotWhite();
            }
        }
        else {
            drawDauCong();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 13) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawDauTru();
                pulPixelNotWhite();
            }
        }
        else {
            drawDauTru();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 14) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawDauNhan();
                pulPixelNotWhite();
            }
        }
        else {
            drawDauNhan();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 15) {
        glColor3ub(0, 0, 0);
        glutMouseFunc(XulyMouseVeHinh);
        glutPassiveMotionFunc(myMotion);
        if (check != 2) {
            if (check == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                glutMouseFunc(XulyMouseVeHinh);
                glutPassiveMotionFunc(myMotion);
                drawDauChia();
                pulPixelNotWhite();
            }
        }
        else {
            drawDauChia();
            pulPixelNotWhite();
            //value = 0;
            check = 0;
        }
    }
    else if (value == 16) {
        F_Color = createColor(2, 0, 255, 0);
        glutMouseFunc(XulyMouseToMau);
    }
    else if (value == 17) {
        F_Color = createColor(3, 255, 0, 0);
        glutMouseFunc(XulyMouseToMau);
    }
    else if (value == 18) {
        F_Color = createColor(4, 255, 255, 0);
        glutMouseFunc(XulyMouseToMau);
    }
    glFlush();
}

#endif
