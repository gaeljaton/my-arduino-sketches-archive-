#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int Sg = 2;
int Sd = 3;
int mode = 0;
boolean statg = HIGH;
boolean statd = HIGH;

unsigned long previousmillisg=0; 
unsigned long previousmillisd=0; 

float T;

void setup() {
lcd.begin(16, 2);
Serial.begin(9600); //start serial with midi baudrate 31250
pinMode(Sg, OUTPUT);
pinMode(Sd, OUTPUT);
digitalWrite(Sg,statg);
digitalWrite(Sd,statd);
delay(500);
}
void loop () {
  //aquisition fréquences & T  sur A1 et A2
 int valg = analogRead(1);
 valg = map(valg, 0, 1023, 50, 3000);
 int Tg = 100000/(valg*2); // gauche
  int vald = analogRead(2);
 vald = map(vald, 0, 1023, 50, 3000);
 int Td = 100000/(vald*2); // droite
 
  
unsigned long currentMillis = millis();
 if(currentMillis-previousmillisg >= Tg)
    { statg = !statg; digitalWrite(Sg,statg); if (mode==0){digitalWrite(Sd,statg);} if (mode==1){digitalWrite(Sd,!statg);} previousmillisg = millis(); }
 if(currentMillis-previousmillisd >= Td)
    {if (mode==2)
    {previousmillisd = millis(); if(statd==HIGH){statd=LOW; } else {statd=HIGH;} digitalWrite(Sd,statd);}}
    

lcd.setCursor(0, 0); if(valg<100){lcd.print("0");} if(valg<1000){lcd.print("0");} lcd.print(valg);
lcd.setCursor(12, 0); if(vald<100){lcd.print("0");} if(vald<1000){lcd.print("0");} lcd.print(vald);
if (mode==0){lcd.setCursor(0, 1);  lcd.print(analogRead(0));lcd.print("mode:symetrique");}

Serial.println (analogRead(1));
 
  }
  
