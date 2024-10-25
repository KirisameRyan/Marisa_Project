#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);

char val;

int lf1 = 2;
int lf2 = 3;
int rf1 = 4; 
int rf2 = 5;
int lb1 = 6;
int lb2 = 7; 
int rb1 = 8;
int rb2 = 9;

void goForward(void)      //前
{
	    digitalWrite(lf1,HIGH);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,HIGH);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,HIGH);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,HIGH);
      digitalWrite(rb2,LOW);
}
void goBackward(void)      //后
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,HIGH);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,HIGH);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,HIGH);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,HIGH);
}
void goLeft(void)      //左
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,HIGH);
      digitalWrite(rf1,HIGH);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,HIGH);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,HIGH);
}
void goRight(void)       //右
{
	    digitalWrite(lf1,HIGH);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,HIGH);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,HIGH);
      digitalWrite(rb1,HIGH);
      digitalWrite(rb2,LOW);
}
void goRightForward(void)     //右前
{
	    digitalWrite(lf1,HIGH);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,HIGH);
      digitalWrite(rb2,LOW);
}
void goLeftBackward(void)         //左后
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,HIGH);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,HIGH);
}
void goLeftForward(void)          //左前
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,HIGH);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,HIGH);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,LOW);
}
void goRightBackward(void)           //右后
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,HIGH);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,HIGH);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,LOW);
}
void TurnLeft(void)          //左旋转
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,HIGH);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,HIGH);
      digitalWrite(lb1,HIGH);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,HIGH);
      digitalWrite(rb2,LOW);
}
void TurnRight(void)         //右旋转
{
	    digitalWrite(lf1,HIGH);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,HIGH);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,HIGH);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,HIGH);
}
void Stop(void)         //停止
{
	    digitalWrite(lf1,LOW);
      digitalWrite(lf2,LOW);
      digitalWrite(rf1,LOW);
      digitalWrite(rf2,LOW);
      digitalWrite(lb1,LOW);
      digitalWrite(lb2,LOW);
      digitalWrite(rb1,LOW);
      digitalWrite(rb2,LOW);
}
void setup() {
  Serial.begin(38400);
  BT.begin(38400);

  pinMode(lf1, OUTPUT);
  pinMode(lf2, OUTPUT);
  pinMode(rf1, OUTPUT);
  pinMode(rf2, OUTPUT);
  pinMode(lb1, OUTPUT);
  pinMode(lb2, OUTPUT);
  pinMode(rb1, OUTPUT);
  pinMode(rb2, OUTPUT);

}

void loop() {
  if (BT.available()) {

    val = BT.read();
  switch(val)
  {
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
    
  }}
  val=0;
  delay(20);
}
