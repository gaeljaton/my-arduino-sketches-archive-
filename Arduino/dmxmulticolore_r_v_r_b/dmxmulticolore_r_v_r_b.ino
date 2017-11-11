int r=0;
int b=0;
int v=0;
int i=0;
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
  
  ////////////////////////////////rouge
for (int i=0; i <= 255; i++)
{
    r = i;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}

delay(3*analogRead(0));

for (int i=0; i <= 255; i++)
{
    r = 255-i;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}
delay(3*analogRead(2));


////////////////////////////////vert

for (int i=0; i<= 255; i++)
{
    r = 0;
    v = (i)/3;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}

delay(3*analogRead(0));

for (int i=0; i<= 255; i++)
{
    r = 0;
    v = (255-i)/3;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}

delay(3*analogRead(2));
/////////////////////////////////rouge

for (int i=0; i <= 255; i++)
{
    r = i;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}

delay(3*analogRead(0));

for (int i=0; i <= 255; i++)
{
    r = 255-i;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}
delay(3*analogRead(2));


////////////////////////////////bleu
for (int i=0; i <= 255; i++)
{
    r = 0;
    v = 0;
    b = (i)/3;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}
delay(3*analogRead(0));

for (int i=0; i <= 255; i++)
{
    r = 0;
    v = 0;
    b = (255-i)/3;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
 delay((3200-3*analogRead(1))/256);
}
delay(3*analogRead(2));
}
 
