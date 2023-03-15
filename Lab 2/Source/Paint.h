#pragma once

#ifndef _PAINT_H_
#define _PAINT_H_
#include "Header.h"
#include "SupportDrawPaint.h"

// to mau bang thuat toan dfs
void BoudaryFill(int x, int y, RGBColor F_Color, RGBColor B_Color)
{
    RGBColor currentColor;
    vector<pair<int, int>> ToaDo;
    pair<int, int> currentToaDo;
    ToaDo.push_back({ x, y });
    int codeColor;
    // khi Toa Do trong tuc la to xong 1 hinh
    while (!ToaDo.empty()) {
        currentToaDo = ToaDo.back();
        ToaDo.pop_back();
        codeColor = pixelNotWhite[{currentToaDo.first, currentToaDo.second}];
        // kiem tra mau tai vi tri do 
        // khac vien hoac khac mau can to thi thuc hien to
        if (codeColor != B_Color.code && codeColor != F_Color.code)
        {
            // them key-value ( toa do - ma mau) vao pixelNotWhite 
            if (F_Color.r == 0 && F_Color.g == 255 && F_Color.b == 0)
                pixelNotWhite[{currentToaDo.first, currentToaDo.second}] = 2;
            else if (F_Color.r == 255 && F_Color.g == 0 && F_Color.b == 0)
                pixelNotWhite[{currentToaDo.first, currentToaDo.second}] = 3;
            else if (F_Color.r == 255 && F_Color.g == 255 && F_Color.b == 0)
                pixelNotWhite[{currentToaDo.first, currentToaDo.second}] = 4;
            // PutPixel(currentToaDo.first, currentToaDo.second, F_Color);
            // thuc hien luu cac gia tri xung quanh
            for (int i = 0; i < 4; i++) {
                if (currentToaDo.first + dr[i] >= 0 && currentToaDo.first + dr[i] < width && currentToaDo.second + dc[i] >= 0 && currentToaDo.second + dc[i] < height) {
                    ToaDo.push_back({ currentToaDo.first + dr[i], currentToaDo.second + dc[i] });
                }
            }
        }
    }
}

// xu li bat chuot de to mau
void XulyMouseToMau(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //check = 2;
        getTime();
        BoudaryFill(x, height - y, F_Color, B_Color);
        // lay thoi gian to mau
        cout << "Thoi gian to mau: " << 1000.0 * stopTime() << " (ms)" << endl;
        pulPixelNotWhite();
    }
}



#endif