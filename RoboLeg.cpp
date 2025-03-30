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

float RoboLeg::RadiansToDegrees(float angleRadians) {
  return angleRadians * (180.0 / PI);
}

void RoboLeg::moveToPoint(Point targetPoint) {
  const float angle3clarification = 25.702837;

  const float angle1 = 90 - RadiansToDegrees(atan((float)targetPoint.y/targetPoint.x));

  const float newY = sqrt(pow(targetPoint.x - a, 2) + pow(targetPoint.y, 2)) + a; //TODO: check for simpler formula
  const float d = sqrt(pow(newY - this->a, 2) + pow(targetPoint.z - this->h, 2));

  const float angle21 = calcAngleCosLaw(this->b, d, this->c); 
  const float angle22 = RadiansToDegrees(atan((targetPoint.z - this->h)/(newY - this->a))); 
  const float angle2 = angle21 + angle22 + 90;

  const float angle3 = (180 - calcAngleCosLaw(this->b, this->c, d)) + angle3clarification;

  Serial.println("angle1: " + String(angle1) + "° | angle2: " + String(angle2) + "° | angle3: " + String(angle3) + "°");

  if (!isnan(angle1)) this->servo1.write(angle1);
  if (!isnan(angle2)) this->servo2.write(angle2);
  if (!isnan(angle3)) this->servo3.write(angle3);
  Serial.println(' ');
}

float RoboLeg::calcAngleCosLaw(float side1, float side2, float oppositeSide) {
  float value = (side1 * side1 + side2 * side2 - oppositeSide * oppositeSide) / (2 * side1 * side2);
  return (value >= -1.0 && value <= 1.0) ? acos(value) * (180.0 / PI) : NAN;
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
