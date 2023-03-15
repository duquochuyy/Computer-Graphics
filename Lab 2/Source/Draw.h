#pragma once

#ifndef _DRAW_H_
#define _DRAW_H_
#include "Header.h"
#include "SupportDrawPaint.h"

// ve duong thang bang dda
void lineDDA(int X1, int Y1, int X2, int Y2) {
    int  dx = X2 - X1, dy = Y2 - Y1;
    float x_inc, y_inc;
    float step = max(abs(dx), abs(dy));
    x_inc = dx / step;
    y_inc = dy / step;
    float x = X1, y = Y1; // Khoi tao cac gia tri ban dau	
    setPixel(x, y);

    int k = 1;
    while (k <= step) {
        k++;
        x += x_inc;
        y += y_inc;
        setPixel(round(x), round(y));
    }
}

// ve duong tron bang midpoint
void circleMidPoint(int xT, int yT, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    put8pixel(xT, yT, x, y);

    // ve tu 90do -> 45do
    while (x < y)
    {
        if (p < 0)
            p += (x * 2) + 3;
        else {
            y--;
            p += ((x - y) * 2) + 5;
        }
        x++;
        put8pixel(xT, yT, x, y);
    }
}

// ve hinh ellipse bang midpoint
void ellipseMidPoint(int xT, int yT, int a, int b)
{
    int x = 0, y = b;
    float p1 = b * b - a * a * b + a * a * 0.25;
    put4pixel(xT, yT, x, y);
    while (x * b * b <= y * a * a) {
        if (p1 < 0)
            p1 += b * b * (2 * x + 3);
        else {
            y--;
            p1 += b * b * (2 * x + 3) - a * a * (2 * y - 2);
        }
        x++;
        put4pixel(xT, yT, x, y);
    }


    float p2 = (x + 0.5) * (x + 0.5) * b * b + (y - 1) * (y - 1) * a * a - a * a * b * b;
    put4pixel(xT, yT, x, y);
    while (y >= 0) {
        if (p2 > 0)
            p2 -= a * a * (2 * y - 3);
        else {
            x++;
            p2 += b * b * (2 * x + 2) - a * a * (2 * y - 3);
        }
        y--;
        put4pixel(xT, yT, x, y);
    }
}


// ve hinh
// ve duong thang
void drawDuongThang()
{
    lineDDA(X1, Y1, X2, Y2);
}

// ve tam giac vuong can
void drawTamGiacVuongCan()
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    // duong ve hinh vuong de xac dinh toa do cac dinh
    if (abs(dx) > abs(dy)) {
        Y3 = Y1 + ((dy > 0) ? abs(dy) : -abs(dy));
        X3 = X1;
        Y4 = Y3;
        X4 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
    }
    else {
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
        X3 = X1;
        Y4 = Y3;
        X4 = X1 + ((dx > 0) ? abs(dx) : -abs(dx));
    }
    // noi cac dinh voi nhau
    lineDDA(X1, Y1, X3, Y3);
    lineDDA(X1, Y1, X4, Y4);
    lineDDA(X3, Y3, X4, Y4);
}

// ve tam giac vuong can
void drawTamGiacDeu()
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    // xet canh cua hinh tam giac deu
    // xac dinh toa do cac dinh
    if (abs(dx) > (abs(dy) * 2 / sqrt(3))) {
        canh = abs(dy) * 2 / sqrt(3);
        X3 = X1 + ((dx > 0) ? canh : -canh);
        Y3 = Y1;
        X4 = X1 + ((dx > 0) ? (canh / 2) : (-canh / 2));
        Y4 = Y2;
    }
    else {
        canh = abs(dx);
        X3 = X2;
        Y3 = Y1;
        X4 = X1 + ((dx > 0) ? (canh / 2) : (-canh / 2));
        Y4 = Y1 + ((dy > 0) ? (int)(canh * sqrt(3) / 2) : (int)(-canh * sqrt(3) / 2));
    }
    // noi cac dinh voi nhau
    lineDDA(X1, Y1, X3, Y3);
    lineDDA(X1, Y1, X4, Y4);
    lineDDA(X3, Y3, X4, Y4);
}

// ve hinh chu nhat
void drawHinhChuNhat()
{
    // noi 4 dinh voi nhau tao ra hinh chu nhat
    lineDDA(X1, Y1, X2, Y1);
    lineDDA(X2, Y1, X2, Y2);
    lineDDA(X1, Y2, X2, Y2);
    lineDDA(X1, Y1, X1, Y2);
}

// ve hinh vuong
void drawHinhVuong()
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    // dua ve hinh vuong
    // xac dinh toa do cac dinh
    if (abs(dx) > abs(dy)) {
        canh = abs(dy);
        X3 = X1 + ((dx > 0) ? canh : -canh);
        Y3 = Y1;
        X4 = X3;
        Y4 = Y2;
        X5 = X1;
        Y5 = Y2;
    }
    else {
        canh = abs(dx);
        X3 = X1;
        Y3 = Y1 + ((dy > 0) ? canh : -canh);
        X4 = X2;
        Y4 = Y3;
        X5 = X2;
        Y5 = Y1;
    }
    // ve 4 duong thang noi cac dinh
    lineDDA(X1, Y1, X3, Y3);
    lineDDA(X3, Y3, X4, Y4);
    lineDDA(X4, Y4, X5, Y5);
    lineDDA(X5, Y5, X1, Y1);
}

// ve hinh tron
void drawHinhTron()
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    // dua ve hinh vuong
    // xac dinh tam va ban kinh
    if (abs(dx) > abs(dy)) {
        xT = X1 + ((dx > 0) ? abs(dy) / 2 : -abs(dy) / 2);
        yT = Y1 + ((dy > 0) ? abs(dy) / 2 : -abs(dy) / 2);
        r = abs(dy) / 2;
    }
    else {
        xT = X1 + ((dx > 0) ? abs(dx) / 2 : -abs(dx) / 2);
        yT = Y1 + ((dy > 0) ? abs(dx) / 2 : -abs(dx) / 2);
        r = abs(dx) / 2;
    }
    // thuc hien ve hinh tron bang midpoint
    circleMidPoint(xT, yT, r);
}

// ve hinh ellipse
void drawElip()
{
    // xac dinh tam, 1/2 truc lon, 1/2 truc nho
    xT = (X1 + X2) / 2;
    yT = (Y1 + Y2) / 2;
    A = abs(xT - X1);
    B = abs(yT - Y1);
    if (A > 0 && B > 0) // dieu kien ve
        ellipseMidPoint(xT, yT, A, B);  // ve ellipse bang midpoint
}

// ve hinh ngu giac deu
void drawNguGiacDeu()
{
    // dua ve hinh vuong
    dx = X2 - X1;
    dy = Y2 - Y1;
    if (abs(dx) > abs(dy)) {
        canh = abs(dy);
        Y3 = Y2;
        X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
    }
    else {
        canh = abs(dx);
        X3 = X2;
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
    }
    // xac dinh tam doi xung
    xT = (X1 + X3) / 2;
    yT = (Y1 + Y3) / 2;
    
    // ban kinh hinh tron ngoai tiep ngu giac deu
    r = canh / 2;

    // su dung 2 toa do (X4, Y4) va (X5, Y5) de gan/ thay doi lien tuc ve cac duong thang
    X4 = xT;
    Y4 = Y1;
    // dinh tren cung
    int d1 = r * cos(72 * PI / 180);
    int d2 = r * sin(72 * PI / 180);
    X5 = xT + ((dx > 0) ? -d2 : d2);
    Y5 = yT + ((dy > 0) ? -d1 : d1);
    lineDDA(X4, Y4, X5, Y5);

    // lay doi xung qua xT
    X5 = X5 + ((dx > 0) ? 2 * abs(xT - X5) : -2*abs(xT - X5));
    lineDDA(X4, Y4, X5, Y5);

    d1 = r * sin(54 * PI / 180);
    d2 = r * cos(54 * PI / 180);
    X4 = xT + ((dx > 0) ? d2 : -d2);
    Y4 = yT + ((dy > 0) ? d1 : -d1);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? -2 * abs(xT - X5) : +2 * abs(xT - X5));
    X4 = X4 + ((dx > 0) ? -2 * abs(xT - X4) : +2 * abs(xT - X4));
    lineDDA(X4, Y4, X5, Y5);

    lineDDA(X4, Y4, X4 + ((dx > 0) ? 2 * abs(xT - X4) : -2 * abs(xT - X4)), Y4);

    //circleMidPoint(xT, yT, r);
}

// ve hinh luc giac deu
void drawLucGiacDeu()
{
    // dua ve hinh vuong
    dx = X2 - X1;
    dy = Y2 - Y1;
    if (abs(dx) > abs(dy)) {
        canh = abs(dy);
        Y3 = Y2;
        X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
    }
    else {
        canh = abs(dx);
        X3 = X2;
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
    }
    // xac dinh tam doi xung
    xT = (X1 + X3) / 2;
    yT = (Y1 + Y3) / 2;
    // ban kinh duong tron ngoai tiep luc giac deu
    r = canh / 2;
    // xac dinh dinh tren dung
    X4 = xT;
    Y4 = Y1;
    int d1 = r * cos(60 * PI / 180);
    int d2 = r * sin(60 * PI / 180);
    X5 = xT + ((dx > 0) ? d2 : -d2);
    Y5 = yT + ((dy > 0) ? -d1 : d1);
    lineDDA(X4, Y4, X5, Y5);

    // xu dung phep doi xung tam de xac dinh cac dinh khac
    // dung cong thuc luong giac de tim toa do canh
    X5 = X5 + ((dx > 0) ? -2 * abs(xT - X5) : 2 * abs(xT - X5));
    lineDDA(X4, Y4, X5, Y5);

    X4 = X5;
    Y4 = Y5 + ((dy > 0) ? 2 * abs(yT - Y5) : -2 * abs(yT - Y5));
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? 2 * abs(xT - X5) : -2 * abs(xT - X5));
    X4 = X5;
    lineDDA(X4, Y4, X5, Y5);

    X5 = xT;
    Y5 = Y3;
    lineDDA(X4, Y4, X5, Y5);

    X4 = X4 + ((dx > 0) ? -2 * abs(xT - X4) : 2 * abs(xT - X4));
    lineDDA(X4, Y4, X5, Y5);

    //circleMidPoint(xT, yT, r);
}

// ve hinh mui ten
void drawMuiTen()
{
    dx = X2 - X1;
    dy = Y2 - Y1;

    // ve than tren
    X4 = X1;
    Y4 = Y1 + ((dy > 0) ? abs(dy) / 4 : -abs(dy) / 4);
    X5 = X1 + ((dx > 0) ? abs(dx) / 2 : -abs(dx) / 2);
    Y5 = Y4;
    lineDDA(X4, Y4, X5, Y5);

    X4 = X5;
    Y4 = Y1;
    lineDDA(X4, Y4, X5, Y5);

    // ve phan tren cua mui nhon
    X5 = X2;
    Y5 = Y1 + ((dy > 0) ? abs(dy) / 2 : -abs(dy) / 2);
    lineDDA(X4, Y4, X5, Y5);

    // ve phan duoi cua mui nhon
    Y4 = Y2;
    lineDDA(X4, Y4, X5, Y5);

    // ve phan duoi cho thanh mui ten
    X5 = X4;
    Y5 = Y1 + ((dy > 0) ? 3 * abs(dy) / 4 : -3 * abs(dy) / 4);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X1;
    Y4 = Y5;
    lineDDA(X4, Y4, X5, Y5);

    // ve canh duoi mui ten
    X5 = X1;
    Y5 = Y1 + ((dy > 0) ? abs(dy) / 4 : -abs(dy) / 4);
    lineDDA(X4, Y4, X5, Y5);
}

// ve hinh ngoi sao
void drawNgoiSao()
{
    // dua ve hinh vuong
    dx = X2 - X1;
    dy = Y2 - Y1;
    if (abs(dx) > abs(dy)) {
        canh = abs(dy);
        Y3 = Y2;
        X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
    }
    else {
        canh = abs(dx);
        X3 = X2;
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
    }
    // xac dinh tam doi xung
    xT = (X1 + X3) / 2;
    yT = (Y1 + Y3) / 2;
    // ban kinh duong tron lon
    r = canh / 2;

    // ban kinh duong tron nho
    int r_nho;
    int a, b, c;
    a = r * sin(54 * PI / 180);
    b = r * cos(54 * PI / 180);
    c = b * tan(36 * PI / 180);
    r_nho = a - c;
    int d1 = r_nho * cos(36 * PI / 180);
    int d2 = r_nho * sin(36 * PI / 180);

    // xu dung 2 hinh ngu giac deu noi tiep 2 duong tron dong tam de xac dinh toa do

    // dinh tren cung
    X4 = xT;
    Y4 = Y1;
    X5 = xT + ((dx > 0) ? d2 : -d2);
    Y5 = yT + ((dy > 0) ? -d1 : d1);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? -2 * abs(xT - X5) : 2 * abs(xT - X5));
    lineDDA(X4, Y4, X5, Y5);


    int d3 = r * cos(72 * PI / 180);
    int d4 = r * sin(72 * PI / 180);
    X4 = xT + ((dx > 0) ? -d4 : d4);
    Y4 = yT + ((dy > 0) ? -d3 : d3);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? 2 * abs(xT - X5) : -2 * abs(xT - X5));
    X4 = X4 + ((dx > 0) ? 2 * abs(xT - X4) : -2 * abs(xT - X4));
    lineDDA(X4, Y4, X5, Y5);

    d1 = r_nho * cos(72 * PI / 180);
    d2 = r_nho * sin(72 * PI / 180);
    X5 = xT + ((dx > 0) ? d2 : -d2);
    Y5 = yT + ((dy > 0) ? d1 : -d1);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? -2 * abs(xT - X5) : 2 * abs(xT - X5));
    X4 = X4 + ((dx > 0) ? -2 * abs(xT - X4) : 2 * abs(xT - X4));
    lineDDA(X4, Y4, X5, Y5);

    d3 = r * sin(54 * PI / 180);
    d4 = r * cos(54 * PI / 180);
    X4 = xT + ((dx > 0) ? -d4 : d4);
    Y4 = yT + ((dy > 0) ? d3 : -d3);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? 2 * abs(xT - X5) : -2 * abs(xT - X5));
    X4 = X4 + ((dx > 0) ? 2 * abs(xT - X4) : -2 * abs(xT - X4));
    lineDDA(X4, Y4, X5, Y5);

    X5 = xT;
    Y5 = yT + ((dy > 0) ? r_nho : -r_nho);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X4 + ((dx > 0) ? -2 * abs(xT - X4) : 2 * abs(xT - X4));
    lineDDA(X4, Y4, X5, Y5);
}

// ve dau cong
void drawDauCong()
{
    // xac dinh kich thuoc 4 canh xung quanh
    dx = X2 - X1;
    dy = Y2 - Y1;
    xT = (X2 + X1) / 2;
    yT = (Y2 + Y1) / 2;
    // X1, Y1
    // X3, Y3 la toa do dung cho hinh vuong
    if (abs(dx) > abs(dy)) {
        X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
        Y3 = Y2;
    }
    else {
        X3 = X2;
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
    }
    // canh hinh xuong
    canh = abs(X3 - X1);

    // xac dinh cac dinh va ve cach canh lien tiep nhau
    // (X4, Y4) va (X5, Y5) thay doi/ gan lien tuc de luu toa do
    X4 = X1 + ((dx > 0) ? canh / 3 : -canh / 3);
    Y4 = Y1;
    X5 = X4 + ((dx > 0) ? canh / 3 : -canh / 3);
    Y5 = Y4;
    lineDDA(X4, Y4, X5, Y5);

    X5 = X4;
    Y5 = Y4 + ((dy > 0) ? canh / 3 : -canh / 3);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X4 + ((dx > 0) ? canh / 3 : -canh / 3);
    X5 = X5 + ((dx > 0) ? canh / 3 : -canh / 3);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X5;
    Y4 = Y5;
    X5 = X3;
    Y5 = Y4;
    lineDDA(X4, Y4, X5, Y5);

    X4 = X5;
    Y4 = Y5;
    Y5 = Y4 + ((dy > 0) ? canh / 3 : -canh / 3);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X5 + ((dx > 0) ? -canh / 3 : +canh / 3);
    Y4 = Y5;
    lineDDA(X4, Y4, X5, Y5);

    X5 = X4;
    Y5 = Y3;
    lineDDA(X4, Y4, X5, Y5);

    X4 = X1 + ((dx > 0) ? canh / 3 : -canh / 3);
    Y4 = Y3;
    lineDDA(X4, Y4, X5, Y5);

    X5 = X4;
    Y5 = Y4 + ((dy > 0) ? -canh / 3 : canh / 3);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X1;
    Y4 = Y5;
    lineDDA(X4, Y4, X5, Y5);

    X5 = X4;
    Y5 = Y1 + ((dy > 0) ? canh / 3 : -canh / 3);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X1 + ((dx > 0) ? canh / 3 : -canh / 3);
    Y4 = Y5;
    lineDDA(X4, Y4, X5, Y5);
}

// ve dau tru
void drawDauTru()
{
    // ve tuong tu hinh chu nhat
    dx = X2 - X1;
    dy = Y2 - Y1;
    X3 = X2;
    Y3 = Y2;
    // cho no dep hon mot chut xiu
    if (abs(dy) > (abs(dx) / 3)) {
        Y3 = Y1 + ((dy > 0) ? abs(dx) / 3 : -abs(dx) / 3);
    }
    // noi cac dinh tao ra hinh chu nhat
    lineDDA(X1, Y1, X3, Y1);
    lineDDA(X3, Y1, X3, Y3);
    lineDDA(X1, Y3, X3, Y3);
    lineDDA(X1, Y1, X1, Y3);
}

// ve dau nhan
void drawDauNhan()
{
    // tuong tu nhu dau cong
    dx = X2 - X1;
    dy = Y2 - Y1;
    xT = (X2 + X1) / 2;
    yT = (Y2 + Y1) / 2;
    // X1, Y1
    // X3, Y3 la toa do dung cho hinh vuong
    if (abs(dx) > abs(dy)) {
        X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
        Y3 = Y2;
    }
    else {
        X3 = X2;
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
    }
    // canh hinh vuong
    canh = abs(X3 - X1);

    // xac dinh toa do cac dinh cua dau nhan
    // (X4, Y4) (X5, Y5) thay doi/ gan lien tuc de luu gia tri dinh
    X4 = X1 + ((dx > 0) ? canh / 4 : -canh / 4);
    Y4 = Y1;
    X5 = X1 + ((dx > 0) ? canh / 2 : -canh / 2);
    Y5 = Y1 + ((dy > 0) ? canh / 4 : -canh / 4);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X4 + ((dx > 0) ? canh / 2 : -canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X3;
    lineDDA(X4, Y4, X5, Y5);

    Y4 = Y1 + ((dy > 0) ? canh / 2 : -canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    Y5 = Y5 + ((dy > 0) ? canh / 2 : -canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    Y4 = Y4 + ((dy > 0) ? canh / 2 : -canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? -canh / 2 : canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    X4 = X4 + ((dx > 0) ? -canh / 2 : canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X5 + ((dx > 0) ? -canh / 2 : canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    Y4 = Y4 + ((dy > 0) ? -canh / 2 : canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    Y5 = Y5 + ((dy > 0) ? -canh / 2 : canh / 2);
    lineDDA(X4, Y4, X5, Y5);

    Y4 = Y4 + ((dy > 0) ? -canh / 2 : canh / 2);
    lineDDA(X4, Y4, X5, Y5);
}

// ve dau chia
void drawDauChia()
{
    // ve 2 hinh tron va 1 hinh chu nhat
    dx = X2 - X1;
    dy = Y2 - Y1;
    xT = (X2 + X1) / 2;
    yT = (Y2 + Y1) / 2;
    // X1, Y1
    // X3, Y3 la toa do dung cho hinh vuong
    if (abs(dx) > abs(dy)) {
        X3 = X1 + ((dx > 0) ? abs(dy) : -abs(dy));
        Y3 = Y2;
    }
    else {
        X3 = X2;
        Y3 = Y1 + ((dy > 0) ? abs(dx) : -abs(dx));
    }
    // canh hinh vuong  = chieu dai hcn
    canh = abs(X3 - X1);

    // ve hinh chu nhat
    X4 = X1;
    Y4 = Y1 + ((dy > 0) ? 7 * canh / 18 : -7 * canh / 18);
    X5 = X3;
    Y5 = Y4;
    lineDDA(X4, Y4, X5, Y5);

    X4 = X5;
    Y4 = Y5 + ((dy > 0) ? 2 * canh / 9 : -2 * canh / 9);
    lineDDA(X4, Y4, X5, Y5);

    X5 = X1;
    Y5 = Y4;
    lineDDA(X4, Y4, X5, Y5);

    X4 = X1;
    Y4 = Y1 + ((dy > 0) ? 7 * canh / 18 : -7 * canh / 18);
    lineDDA(X4, Y4, X5, Y5);

    // ban kinh hinh tron nho tren/ duoi hcn
    r = canh / 9;

    // ve hinh tron voi toa do tuong ung
    xT = (X3 + X1) / 2;
    yT = Y1 + ((dy > 0) ? canh / 6 : -canh / 6);
    circleMidPoint(xT, yT, r);

    // ve hinh tron voi do tuong ung
    xT = (X3 + X1) / 2;
    yT = Y1 + ((dy > 0) ? canh * 5 / 6 : -canh * 5 / 6);
    circleMidPoint(xT, yT, r);
}

// bat su kien chuot de ve hinh
// click lan dau: se lay toa do X1 Y1 check = 1
// click lan hai: dung ve hinh, xuat hinh ra man hinh check = 2
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

#endif
