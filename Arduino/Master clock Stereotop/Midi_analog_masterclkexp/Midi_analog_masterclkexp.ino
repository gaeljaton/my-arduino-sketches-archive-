#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
//########################### VARIABLES TEMPS ##################################
int duree=20; // durée totale en min
int bpmi=30; // bpm début
int bpmf=300; // bpm fin
//##############################################################################
int bpm;
byte midi=0;
unsigned long previousmillis=0; 
float T;

void setup() {
  lcd.begin(16, 2);
  pinMode(17,OUTPUT);   
  pinMode(19,OUTPUT);
  digitalWrite(17,HIGH);  
  digitalWrite(19,LOW);
  T=60000/(bpmi*24);
  for(int i = 0;i < 10;i++) // flash LED's on startup
  {
    digitalWrite(13,HIGH);  
    delay(30);
    digitalWrite(13,LOW);  
    delay(30);
  }
  Serial.begin(31250); //start serial with midi baudrate 31250
  lcd.print("Masterclock "); lcd.print(duree); lcd.print("mn");
  delay(50);
}
void loop () {
  unsigned long currentMillis = millis();
  if(currentMillis-previousmillis >= T)
  {
  previousmillis = millis();
  Serial.write(0xf8); // ****MIDI Clock****
  T = 60000/(24*(bpmi+(previousmillis*(bpmf-bpmi))/(duree*60000))) ;
  ++midi; 
  if(midi>23){midi=0;}
  if(midi<12){analogWrite(11,midi*22+1);digitalWrite(2,HIGH);digitalWrite(3,LOW);}else{analogWrite(11,(23-midi)*22+1);digitalWrite(2,LOW);digitalWrite(3,HIGH);}
  if (midi==0){digitalWrite(13,HIGH); }else{digitalWrite(13,LOW);}
 
  bpm=60000/(24*T);
   lcd.setCursor(0, 0); lcd.print(T);
  lcd.setCursor(0, 1); lcd.print("BPM = "); lcd.print(bpm); lcd.print("  ");
  lcd.setCursor(10, 1); lcd.print("mn:"); lcd.print(previousmillis/60000);
  }
}
