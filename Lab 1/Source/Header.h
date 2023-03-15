#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_
#include <GL/glut.h>
#include <iostream>
#include <time.h>  
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "DrawByOpenGL.h"
#include "SupportDraw.h"
#include "LineDDA.h"
#include "LineBresenham.h"
#include "CircleMidPoint.h"
#include "EllipseMidPoint.h"
#include "ParabolMidPoint.h"
#include "HyperbolMidPoint.h"
using namespace std;

#define height 480
#define width 640
#define max(a,b) ((a) > (b) ? (a) : (b))

using namespace std;


void lineDDA(int x1, int y1, int x2, int y2);

void lineBresenham(int x1, int y1, int x2, int y2);

void circleMidPoint(int xT, int yT, int r);

void ellipseMidPoint(int xT, int yT, int rx, int ry);

void parabolMidPoint(int xT, int yT, int p);

void hyperbolMidPoint(int xT, int yT, int a, int b);

#endif