#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 
int e = 1; //etat on/off
int t; //période totale
int d; //durée impusion
int i;
int r=9;
int v=10;
int b=11;
int c;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);// initialisation LCD en mode 4 bits 


void setup()  
{     
pinMode(13, OUTPUT);  
pinMode(12, OUTPUT);  
  

lcd.begin(20,4); 
delay(10); // pause rapide pour laisser temps initialisation

lcd.print("LCD OK") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran
Serial.begin(9600);
}

void loop(){ 
  
  
if (analogRead (A0) > 500)
  {  
  e=1;
  lcd.setCursor(0, 0) ; 
  lcd.print("start") ;
  delay (100);
  }
 if (analogRead (A2) > 500)
  {  
  e=0;
  lcd.setCursor(0, 0) ; 
  lcd.print("stop") ;
  delay (100);
  }


d = analogRead(5)/20;
t = analogRead(4)*8;
i = analogRead(3)/2;
lcd.setCursor(0, 0) ; 
lcd.print("implusion") ;
lcd.setCursor(12, 0) ;
lcd.print(d) ;
lcd.setCursor(0, 2) ; 
lcd.print("intervalle") ;
lcd.setCursor(12, 2) ; 
lcd.print(t) ;
lcd.setCursor(0, 3) ; 
lcd.print("double") ;
lcd.setCursor(12, 3) ; 
lcd.print(i) ;
delay (50);
// if(e==1)

 if(digitalRead(15)==1)

  {
    analogWrite (r,255);
    analogWrite (v,255);
    analogWrite (b,255);
  digitalWrite(13, HIGH);  
  delay(d);
  digitalWrite(13, LOW); 
  if (analogRead (3)>10)
    {delay (i);
    digitalWrite(13, HIGH);  
    delay(d);
    digitalWrite(13, LOW); 
    }
  
  //delay(t);
//  for (int z=0;z<2;z++)
//  {
//  for (c=0;c<=255;c++)
//  {
//  analogWrite (r,c);
//  analogWrite (v,0);
//  analogWrite (b,(255-c)/2);
//  delay (4);
//  }
//  
//  for (c=0;c<=255;c++)
//  {
//  analogWrite (r,255-c);
//  analogWrite (v,c/2);
//  analogWrite (b,0);
//  delay (4);
//  }
//    for (c=0;c<=255;c++)
//  {
//  analogWrite (r,0);
//  analogWrite (v,(255-c)/2);
//  analogWrite (b,c/2);
//  delay (4);
//  }
//  
//  
//  }
  }

lcd.clear();
delay(10);
}
