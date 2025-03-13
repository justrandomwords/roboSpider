#include "RoboLeg.h"

RoboLeg::RoboLeg(const Options& options)
  : h(options.h), a(options.a), b(options.b), c(options.c), 
    pointer(options.pointer), origin(0) 
{
  servo1.attach(options.servoPin1);
  servo2.attach(options.servoPin2);
  servo3.attach(options.servoPin3);
}

void RoboLeg::moveServo(int servoNumber, int targetAngle) {
  Servo* selectedServo;

  if (servoNumber == 1) selectedServo = &servo1;
  else if (servoNumber == 2) selectedServo = &servo2;
  else if (servoNumber == 3) selectedServo = &servo3;
  
  selectedServo->write(targetAngle);
}

String RoboLeg::getSchema() {
  return R"(
                    Sr3
                    ╱ ╲
                   ╱   ╲ c
                b ╱     ╲ 
                 ╱       ╲
                ╱         ╲ 
        a      ╱           P 
 Sr1 ─────── Sr2
  │  
  │ h 
  │  
  O

Sr(n) - servo motors
O - origin
P - pointer

  )";
}
