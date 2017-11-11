
#include <DmxSimple.h>

void setup() {
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(3);

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  DmxSimple.maxChannel(3);
//  Serial.begin(9600);
}

void loop() {
  
  int r = analogRead(0)/4;
  int v = analogRead(1)/4;
  int b = analogRead(2)/4;
  delay(7);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
//  DmxSimple.write(4,255);
//  DmxSimple.write(5,0);
  delay(7);
//    Serial.print(r); 
//    Serial.print(v); 
//    Serial.print(b); 
//    Serial.println(""); 
  }
