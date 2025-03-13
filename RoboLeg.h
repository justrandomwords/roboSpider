#include <Arduino.h>
#include "Servo.h"
#include "Point.h"

#ifndef ROBOLEG_H
#define ROBOLEG_H

struct Options {
    int servoPin1;
    int servoPin2;
    int servoPin3;
    double h;
    double a;
    double b;
    double c;
    Point pointer;

    Options(int sp1, int sp2, int sp3, int height, int sideA, int sideB, int sideC, const Point& defaultPointer)
        : servoPin1(sp1), servoPin2(sp2), servoPin3(sp3), h(height), a(sideA), b(sideB), c(sideC), pointer(defaultPointer) {}
};

class RoboLeg {
  public:
    RoboLeg(const Options& options);
    static String getSchema();

    void moveServo(int servoNumber, int targetAngle);
    
  private: 
    int h, a, b, c;
    Point origin;
    Point pointer;
    Servo servo1;
    Servo servo2;
    Servo servo3;
};

#endif
