int v;
int b;
int r;
int color=0;
float x;
float freq;
float time;
int ptime =0;
int ctime;
#include <DmxSimple.h>

void setup() {
  /* The most common pin for DMX output is pin 3, which DmxSimple
  ** uses by default. If you need to change that, do it here. */
  DmxSimple.usePin(3);
  pinMode (9, OUTPUT);
    pinMode (10, OUTPUT);
      pinMode (11, OUTPUT);
 
  DmxSimple.maxChannel(3);
  Serial.begin(9600);
}

void loop() {

if(analogRead(2)>=512){x=analogRead(2)-512;}
 if(analogRead(2)<512){x=511-analogRead(2);}
 freq=(x*40/113)+1;
 time= 1000/freq ;
 Serial.println(time);
 ctime = millis(); 
  
  if (ctime-ptime>=time)
  {
   
  if(color==0){
    r = analogRead(3)/4;
    v = 0;
    b = 0;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  analogWrite (9, r);
  analogWrite (10, 0);
  analogWrite (11, 0);}     
  if(color==1){
    r = 0;
    v = analogRead(4)/4;
    b = 0;   
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  analogWrite (9, 0);
  analogWrite (10, v);
  analogWrite (11, 0);}
 if(color==2){
    r = 0;
    v = 0;
    b = analogRead(5)/4;
  DmxSimple.write(1,r);
  DmxSimple.write(2,v);
  DmxSimple.write(3,b);
  analogWrite (9, 0);
  analogWrite (10, 0);
  analogWrite (11, b);}
  
  if(analogRead(2)>=512)
{++color; if (color>2){color=0;}}
  if(analogRead(2)<512)
  {--color; if (color<0){color=2;}}
  ptime=ctime; }

}
  
// 
//}
//if(analogRead(2)<=512)
//{ 
//    r = 0;
//    v = 0;
//    b = analogRead(5)/4;
//  DmxSimple.write(1,r);
//  DmxSimple.write(2,v);
//  DmxSimple.write(3,b);
//  analogWrite (9, 0);
//  analogWrite (10, 0);
//  analogWrite (11, b);
// 
//    r = 0;
//    v = analogRead(4)/4;
//    b = 0;   
//  DmxSimple.write(1,r);
//  DmxSimple.write(2,v);
//  DmxSimple.write(3,b);
//  analogWrite (9, 0);
//  analogWrite (10, v);
//  analogWrite (11, 0);
// 
//    r = analogRead(3)/4;
//    v = 0;
//    b = 0;
//  DmxSimple.write(1,r);
//  DmxSimple.write(2,v);
//  DmxSimple.write(3,b);
//  analogWrite (9, r);
//  analogWrite (10, 0);
//  analogWrite (11, 0);
//}
//}
