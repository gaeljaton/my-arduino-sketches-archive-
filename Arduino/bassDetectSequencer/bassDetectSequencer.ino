#include <PS2Keyboard.h>
unsigned long t=0;
unsigned long tc=0; //temps beat
unsigned long to=0;
int ta=0; //T oscillateur 1
int tb=0; //T oscillateur 2
unsigned long t1=0; //comparateur osc 1
unsigned long t2=0;//comparateur osc 1

const int DataPin = 2;
const int IRQpin =  3;
PS2Keyboard keyboard;
int four=3;
int j=0;
int a = 0;
int b = 0;
void setup()
{

  pinMode(4, OUTPUT);  //led 1/4 beat
  pinMode(5, OUTPUT);  //led 2/4 beat 
  pinMode(6, OUTPUT);  //led 3/4 beat
  pinMode(7, OUTPUT);  //led 4/4 beat
  pinMode(8, OUTPUT);  //led
  pinMode(9, OUTPUT);  //led 
  pinMode(10, OUTPUT); //led 
  pinMode(11, OUTPUT); //led 
  pinMode(12, OUTPUT); //led 
  pinMode(13, OUTPUT); //led 1/1 beat
 delay(100);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");

}

void loop()
{
  
  
  
  to=micros();
t = millis();
if (keyboard.available()) {
    int c = keyboard.read();
    if (c==127){digitalWrite(four, LOW); if (four==7){four=3;}; four=four+1; digitalWrite(four, HIGH); }
    if (c==27){digitalWrite(10, LOW); digitalWrite(11, LOW); ta=0; tb=0; }
    if (c==11){ta = ta+10;}
    if (c==10){ta = ta-10;}
    if (c==21){tb = tb+10;}
    if (c==8){tb = tb-10;}
    //rangée 1
    if (c==52){ta=532;}
    if (c==53){ta=630;}
    if (c==54){ta=780;}
    if (c==55){ta=900;}
    if (c==56){ta=1037;}
    if (c==57){ta=1100;}
    if (c==48){ta=1260;}
    if (c==45){ta=1533;}
   //rangée 2  
    if (c==101){ta=2317;}
    if (c==114){ta=2750;}
    if (c==116){ta=3212;}
    if (c==121){ta=4000;}
    if (c==117){ta=4776;}
    if (c==105){ta=6000;}
    if (c==111){ta=7400;}
    if (c==112){ta=9868;}
    //rangée 3
     if (c==115){tb=532;}
    if (c==100){tb=630;}
    if (c==102){tb=780;}
    if (c==103){tb=900;}
    if (c==104){tb=1037;}
    if (c==106){tb=1100;}
    if (c==107){tb=1260;}
    if (c==108){tb=1533;}
   //rangée 4  
    if (c==122){tb=2317;}
    if (c==120){tb=2750;}
    if (c==99){tb=3212;}
    if (c==118){tb=4000;}
    if (c==98){tb=4776;}
    if (c==110){tb=6000;}
    if (c==109){tb=7400;}
    if (c==44){tb=9868;}
      }
      
    if (t-tc>analogRead(3)){
      tc=millis();
      if (j==0){
        if (analogRead(0)>300){
          j=1;
          digitalWrite(four, LOW);
          if (four==7){four=3;};
          four=four+1;
          digitalWrite(four, HIGH); 
          digitalWrite(13, HIGH); 
         tone(12, analogRead(4)*4);} ;}
       else{digitalWrite(13, LOW); j=0;};
  }
    if (ta>0){
  if (a==1){if (to-t1>=ta){t1=micros();digitalWrite(10, LOW); a=0;};}
  else{if (to-t1>=ta){t1=micros();digitalWrite(10, HIGH); a=1;};}
    }
    
     if (tb>0){
  if (b==1){if (to-t2>=tb){t2=micros();digitalWrite(11, LOW); b=0;};}
  else{if (to-t2>=tb){t2=micros();digitalWrite(11, HIGH); b=1;};}
    }
    
}

