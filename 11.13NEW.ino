#include <SoftwareSerial.h>
#include<Servo.h>

SoftwareSerial Marisa(50,51);
Servo Servo;

int pos=0,sta=0,js=0;
uint8_t DataRead[6] = {0};
uint8_t Data[6] = {0};
int motorPins[] = {47,46,48,49,43,42,45,44,41,40};
int pwmPins[]={3,4,5,6}

void setup() {
  Serial.begin(38400);
  Marisa.begin(38400);
  Servo.attach(7);
for (int i = 0; i < 10; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
for (int i = 0; i < 4; i++) {
    pinMode(pwmPins[i], OUTPUT);
  }
}

void loop() {
  Receive()
  Command(Data[0],Data[1],Data[2]);
}

void Command(uint8_t a,uint8_t b,uint8_t c)
{
  switch(a)
  {
    case 1:
    goForward();
    break;

    case 2:
    goBackward();
    break;

    case 3:
    goLeft();
    break;

    case 4:
    goRight();
    break;

    case 5:
    TurnLeft();
    break;

    case 6:
    TurnRight();
    break;

    case 7:
    goLeftBackward();
    break;

    case 8:
    goRightBackward();
    break;

    case 9:
    goLeftForward();
    break;

    case 10:
    goRightForward();
    break;

    default:
    Stopmove();
    break;
    
  }
  switch(b){
    case 1:
    HighSpeed();
    break;

    case 2:
    LowSpeed();
    break;
  }
  switch(c){
    case 1:
    PutUp();
    break;

    case 2:
    PutDown();
    break;

    case 3:
    Open();
    break;

    case 4:
    Close();
    break;

    default:
    Stopput();
    break;
  }
}
/*数据包*/
uint8_t Receive(){
  for(js=0;js<6;js++)
  {
    if (mySerial.available())
     {DataRead[js]=mySerial.read();}
  }
  if(DataRead[0]==0XA5)
  {for(js=0;js<3;js++)
  {Data[js]=DataRead[js+1];}}
}
/*麦轮*/
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

void Stopmove() {
  setMotors(LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW);
}
/*速度*/
void HighSpeed(){
     setSpeed(255,255,255,255);    //pwm待修改调参
}

void LowSpeed(){
     setSpeed(128,128,128,128);  //pwm待修改调参
}
/*丝杆*/
void PutUp()
{
  digitalWrite(motorPins[8], HIGH);
  digitalWrite(motorPins[9], LOW);
}
void PutDown()
{
  digitalWrite(motorPins[8], LOW);
  digitalWrite(motorPins[9], HIGH);
}
void Stopput()
{
  digitalWrite(motorPins[8], LOW);
  digitalWrite(motorPins[9], LOW);
}
/*夹爪未调参*/
void Open(){
  sta=Servo.read();
  for(pos=sta; pos<=90;pos++)
{
  Servo.write(pos);
  delay(5);}
}
void Close(){
  sta=Servo.read();
  for(pos=sta; pos<=90;pos++)
{
  Servo.write(pos);
  delay(5);}
}

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
void setSpeed(int js1,int js2,int js3,int js4)
{
  analogWrite(pwmPins[0],js1);
  analogWrite(pwmPins[1],js2);
  analogWrite(pwmPins[2],js3);
  analogWrite(pwmPins[3],js4);
}