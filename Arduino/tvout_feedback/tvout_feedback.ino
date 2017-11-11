#include <TVout.h>
int x;
int y;
TVout TV;
int o=0;
unsigned long  previousMillis;
int b;
void setup ()
{
  TV.begin(_PAL);

//  TV.clear_screen ();
//  TV.print_str (10, 10, "OUVREZ DU BONHEUR" );
//
//  TV.print_str (20, 20, "OUVREZ DU BONHEUR" );
//  TV.delay (20);
  TV.clear_screen ();
  delay(100);
  pinMode(2, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(3, INPUT);
digitalWrite(2,LOW);
digitalWrite(4,HIGH);
}

void loop ()
{ 

  int b=(analogRead(1)/4 );
analogWrite(11, b);


if (digitalRead(3)==HIGH)
{
if (analogRead(0)<256)
{
  TV.print(3, 44, "Frequences Minerales" );
 }
 else if(analogRead(0)<512)
 {
  TV.print(3, 44, "Jaensch Stroop" );
 }
 else if(analogRead(0)<768)
 {
  TV.print(3, 15, "Antoine Hubineau" );
  TV.print(3, 25, "synth. modulaire" );
  TV.print(3, 44, "Gael Jaton" );
  TV.print(3, 54, "video experimentale" );
 }
 else
 {
   TV.print(3, 44, "Primordial Primates" );
 }
}
if (digitalRead(3)==LOW){TV.clear_screen ();}
}
