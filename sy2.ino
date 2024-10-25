#include<RSCG12864B.h>
#include<SoftwareSerial.h>
SoftwareSerial BT(8,9);
char val;

int sy1 = 2;
int sy2 = 3;
void setup() {
  Serial.begin(38400);
  BT.begin(38400);
 pinMode(sy1, OUTPUT);
  pinMode(sy2, OUTPUT);
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
    default:
    Stop();
    break;
    }}
    val=0;
    delay(20);

}
void Stop(void)         //停止
{
	    digitalWrite(sy1,LOW);
      digitalWrite(sy2,LOW);}
void goForward(void)      //前
{
	    digitalWrite(sy1,HIGH);
      digitalWrite(sy2,LOW);}
      void goBackward(void)      //后
{
	    digitalWrite(sy1,LOW);
      digitalWrite(sy2,HIGH);}