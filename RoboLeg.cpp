#include "RoboLeg.h"


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
