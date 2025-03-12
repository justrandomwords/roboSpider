#include "Point.h"

#ifndef OPTION_H
#define OPTION_H

struct Option {
    int servoPin1;
    int servoPin2;
    int servoPin3;
    double h;
    double a;
    double b;
    double c;
    Point p;

    Option(int sp1, int sp2, int sp3, double height, double angleA, double angleB, double angleC, const Point& point)
        : servoPin1(sp1), servoPin2(sp2), servoPin3(sp3), h(height), a(angleA), b(angleB), c(angleC), p(point) {}
};

#endif
