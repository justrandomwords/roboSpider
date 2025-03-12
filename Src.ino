#include "RoboLeg.h"
#include "Point.h"

void parseSerialInput() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.equals("schema")) {
      Serial.println(RoboLeg::getSchema());
    } else {
    }
  }
}

Options options(9, 10, 11, 5, 3, 4, 6, Point(10, 0, 0));

void setup() {
  Serial.begin(9600);
}

void loop() {
  parseSerialInput();

  RoboLeg roboleg(options);
}
