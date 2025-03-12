#include "Point.h"

Point::Point(int value) {
  x = value;
  y = value;
  z = value;
}

Point::Point(int x, int y, int z) {
  this->x = x;
  this->y = y;
  this->z = z;
}
