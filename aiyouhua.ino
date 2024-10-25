#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

#define BUFF_SIZE 20

uint8_t index = 0;

int motorPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
}

void loop() {
  if (mySerial.available() > 0) {
    int len = mySerial.available();
    for (int i = 0; i < len; i++) {
      buffer[i] = char(mySerial.read());
    }
    handleCommand(buffer[0]);
    memset(buffer, 0, BUFF_SIZE);
  }
  delay(20);
}

void handleCommand(char command) {
  switch (command) {
    case 'a':
      goForward();
      break;
    case 'b':
      goBackward();
      break;
    case 'l':
      goLeft();
      break;
    case 'r':
      goRight();
      break;
    case 'L':
      TurnLeft();
      break;
    case 'R':
      TurnRight();
      break;
    case 1:
      goLeftBackward();
      break;
    case 3:
      goRightBackward();
      break;
    case 7:
      goLeftForward();
      break;
    case 9:
      goRightForward();
      break;
    default:
      Stop();
      break;
  }
}

void goForward() {
  setMotors(HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW);
}

void goBackward() {
  setMotors(LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH);
}

void goLeft() {
  setMotors(LOW, HIGH, HIGH, LOW, HIGH, LOW, LOW, HIGH);
}

void goRight() {
  setMotors(HIGH, LOW, LOW, HIGH, LOW, HIGH, HIGH, LOW);
}

void TurnLeft() {
  setMotors(LOW, HIGH, LOW, HIGH, HIGH, LOW, HIGH, LOW);
}

void TurnRight() {
  setMotors(HIGH, LOW, HIGH, LOW, LOW, HIGH, LOW, HIGH);
}

void goLeftBackward() {
  setMotors(LOW, HIGH, LOW, LOW, LOW, LOW, LOW, HIGH);
}

void goRightBackward() {
  setMotors(LOW, LOW, LOW, HIGH, LOW, LOW, HIGH, LOW);
}

void goLeftForward() {
  setMotors(LOW, LOW, HIGH, LOW, HIGH, LOW, LOW, LOW);
}

void goRightForward() {
  setMotors(HIGH, LOW, LOW, LOW, LOW, HIGH, LOW, LOW);
}

void Stop() {
  setMotors(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW);
}

void setMotors(int lf1, int lf2, int rf1, int rf2, int lb1, int lb2, int rb1, int rb2) {
  digitalWrite(motorPins[0], lf1);
  digitalWrite(motorPins[1], lf2);
  digitalWrite(motorPins[2], rf1);
  digitalWrite(motorPins[3], rf2);
  digitalWrite(motorPins[4], lb1);
  digitalWrite(motorPins[5], lb2);
  digitalWrite(motorPins[6], rb1);
  digitalWrite(motorPins[7], rb2);
}