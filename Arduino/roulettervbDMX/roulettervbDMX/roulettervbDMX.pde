int r=0;
int b=0;
int v=0;
int i=0;
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
t=1000;
for (int i=0; i <6; i++)//********
{
  
    r = analogRead(0)/4 ;
    v = 0;
    b = 0;
    t=t-50;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
  r = 0;
    v = analogRead(1)/4;
    b = 0;
    t=t-50;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
  r = 0;
    v = 0;
    b = analogRead(2)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t-50;
}
t=50;
for (int i=0; i <= 32; i++)
{
    r = analogRead(0)/4;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
  r = 0;
    v = analogRead(1)/4;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
  r = 0;
    v = 0;
    b = analogRead(2)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
}
for (int i=0; i <6; i++)//****************
{
  
    r = analogRead(0)/4;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t+50;
  r = 0;
    v = analogRead(1)/4;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t+50;
  r = 0;
    v = 0;
    b = analogRead(2)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t+50;
}
////////////////////////////////////////////////////////////////////
t=1000;
for (int i=0; i < 6; i++)//**************
{
  
   r = 0;
    v = 0;
    b = analogRead(2)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t-50;
  r = 0;
    v = analogRead(1)/4;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t-50;
  r = analogRead(0)/4;
    v = 0;
    b = 0;
  
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  
  
 delay(t);
t=t-50;
}
t=50;
for (int i=0; i <= 32; i++)
{
   r = 0;
    v = 0;
    b = analogRead(2)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
  r = 0;
    v = analogRead(1)/4;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
  r = analogRead(0)/4;
    v = 0;
    b = 0;
  
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  
  
 delay(t);
}
for (int i=0; i <6; i++)//***************
{
  
    r = 0;
    v = 0;
    b = analogRead(2)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t+50;
  r = 0;
    v = analogRead(1)/4;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay(t);
 t=t+50;
  r = analogRead(0)/4;
    v = 0;
    b = 0;
  
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  
  
 delay(t);
t=t+50;
}



}
