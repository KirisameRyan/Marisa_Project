/*没必要看下去了*/
/*一次失败的蓝牙通信尝试*/

#include <SoftwareSerial.h>
#include<RSCG12864B.h>
SoftwareSerial BT(8,9);

char val;


void setup() {
  Serial.begin(38400);
   RSCG12864B.begin();
  RSCG12864B.brightness(255);
  Serial.println("BT is ready!");
  BT.begin(38400);
}
void loop() {

  if (BT.available()) {

    val = BT.read();

    Serial.print(val);
    RSCG12864B.print_string_16_xy(0,0,val);
    


  }
  delay(2000);
    RSCG12864B.clear();
}
