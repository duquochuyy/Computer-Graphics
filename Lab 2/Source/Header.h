#pragma once

#ifndef _HEADER_H_
#define _HEADER_H_

#include <windows.h>
#include <GL/glut.h> 
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <chrono>
#include <thread>
static int window;
static int menu_id;
static int submenu_id;
static int value = 0;
static int submenu_id_tamgiac;
static int submenu_id_tugiac;
static int submenu_id_oval;
static int submenu_id_dagiacdeu;
static int submenu_id_hinhkhac;
static int submenu_id_dau;
static int submenu_id_tomau;
static int submenu_id_chonhinh;

#define height 480
#define width 640
#define PI 3.14159265358979323846

using namespace std;

// cau truc 1 mau 
typedef struct _RGBColor
{
    int code;
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGBColor;

// 0: white
// 1: black
// 2: green
// 3: red
// 4: yellow

RGBColor B_Color; // black
RGBColor W_Color; // white
RGBColor F_Color; // green / red / yellow
RGBColor G_Color; // green
RGBColor R_Color; // red
RGBColor Y_Color; // yellow

// ho tro cho boundary
vector<int> dr = { 0, -1, 0, 1 };
vector<int> dc = { -1, 0, 1, 0 };

// mot vai bien de luu toa do va thong tin ve hinh
int X1, X2, Y1, Y2, X3, Y3, X4, Y4, X5, Y5, dx, dy, xT, yT, r, canh, A, B;
// vector<pair<int, int>> ToaDoKeoHinh;
// 0: chua ve, 1: dang ve, 2: dung ve
int check = 0;
// luu lai nhung pixel da duoc to mau (khac trang)
map < pair<int, int>, int > pixelNotWhite;
// x, y, color
// 0: white
// 1: black
// 2: green
// 3: red
// 4: yellow

#endif