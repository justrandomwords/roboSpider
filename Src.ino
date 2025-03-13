#include "RoboLeg.h"
#include "Point.h"

Options options(8, 9, 10, 5, 3, 4, 6, Point(10, 0, 0));
RoboLeg* roboleg;

void setup() {
  Serial.begin(9600);
  roboleg = new RoboLeg(options);
}

void loop() {
  parseSerialCommand();
}

void parseSerialCommand() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    executeCommand(input);
  }
}

void executeCommand(String command) {
  if (command.startsWith("s ")) {
    int spaceIndex = command.indexOf(' ', 2);
    if (spaceIndex != -1) {
      int servoNumber = command.substring(2, spaceIndex).toInt();
      int angle = command.substring(spaceIndex + 1).toInt();
      roboleg->moveServo(servoNumber, angle);
    }
  } else if (command == "scheme") {
    Serial.println(RoboLeg::getSchema());
  } else {
    Serial.println("Unknown command");
  }
}
