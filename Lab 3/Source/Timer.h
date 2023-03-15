#pragma once

#ifndef _TIMER_H_
#define _TIMER_H_

#include "Header.h"

class Timer {
private:
    std::chrono::high_resolution_clock::time_point timeIs;
    std::chrono::duration<double> timeDraw;
public:
    Timer() {}
    ~Timer() {}
    // lay thoi gian hien tai, ho tro tinh thoi gian to mau
    void getTime() {
        timeIs = std::chrono::high_resolution_clock::now();
    }

    // dung tinh thoi gian, ho tro tinh thoi gian to mau
    double stopTime() {
        timeDraw = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - timeIs);
        return 1.0 * timeDraw.count();
    }
};

#endif

