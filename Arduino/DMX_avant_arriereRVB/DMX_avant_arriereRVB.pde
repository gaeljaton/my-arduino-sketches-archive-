int r=0;
int b=0;
int v=0;
int i=10;
int t;
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
if(analogRead(0)>512)
{
  
    r = 255;
    v = 0;
    b = 0;
    t=1023-analogRead(0);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  delay(t+i);
 
    r = 0;
    v = 255;
    b = 0;
   t=1023-analogRead(0);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  delay(t+i);
 
    r = 0;
    v = 0;
    b = 255;
    t=1023-analogRead(0);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  delay(t+i);
 
}
if(analogRead(0)<=512)
{ 
    r = 0;
    v = 0;
    b = 255;
    t=analogRead(0);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t+i);
 
    r = 0;
    v = 255;
    b = 0;
    t=analogRead(0);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t+i);
 
    r = 255;
    v = 0;
    b = 0;
    t=analogRead(0);
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t+i);
}
}
