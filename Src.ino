#include "RoboLeg.h"
#include "Point.h"

Options options(8, 9, 10, 26, 38, 50, 90, Point(100, 50, 0));
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
  } else if (command.startsWith("m ")) {
    int firstSpaceIndex = command.indexOf(' ', 2);
    int secondSpaceIndex = command.indexOf(' ', firstSpaceIndex + 1);
    if (firstSpaceIndex != -1 && secondSpaceIndex != -1) {
      int x = command.substring(2, firstSpaceIndex).toInt();
      int y = command.substring(firstSpaceIndex + 1, secondSpaceIndex).toInt();
      int z = command.substring(secondSpaceIndex + 1).toInt();
      roboleg->moveToPoint(Point(x, y, z));
    }
  } else if (command == "scheme") {
    Serial.println(RoboLeg::getSchema());
  } else {
    Serial.println("Unknown command");
  }
}
