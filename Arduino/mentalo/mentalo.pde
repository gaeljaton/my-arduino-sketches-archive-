#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 
int t; //période totale
int d = 30; //durée impusion
int r = 6;
int v = 5;
int b = 3;
void setup()  
{
  pinMode (10, OUTPUT);
   Serial.begin(9600); 
}

void loop()
{ 
  Serial.println(analogRead(A3));  
  int i = analogRead(A3);
  if (i<20)
  {
    analogWrite (r,255);
    analogWrite (v,0);
    analogWrite (b,0);
    digitalWrite(10, HIGH);  
    delay(15);
    digitalWrite(10, LOW); 
    delay(1500);
  }
  if (i>20){
    if (i<1001)
  {
    analogWrite (r,255);
    analogWrite (v,i/4);
    analogWrite (b,0);
    digitalWrite(10, HIGH);  
    delay(d);
    digitalWrite(10, LOW); 
    delay(1500+i);
  }
  if (i>1000)
  {
    digitalWrite(10, HIGH);
    for(int q = 0 ; q <= 255; q +=20)
    { 
    analogWrite (r,q);
    analogWrite (v,255-q);
    analogWrite (b,0);
    delay (10);
    }
        for(int q = 0 ; q <= 255; q +=20)
    { 
    analogWrite (r,255-q);
    analogWrite (v,0);
    analogWrite (b,q);
    delay (10);
    }
        for(int q = 0 ; q <= 255; q +=20)
    { 
    analogWrite (r,0);
    analogWrite (v,q);
    analogWrite (b,255-q);
    delay (10);
    }
  }



  }
}
