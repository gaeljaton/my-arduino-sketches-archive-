#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 
int e = 0; //etat on/off
int t; //période totale
int d; //durée impusion
int i;
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
 if(e==1)
  {
  digitalWrite(13, HIGH);  
  delay(d);
  digitalWrite(13, LOW); 
  if (analogRead (3)>10)
  {delay (i);
  digitalWrite(13, HIGH);  
  delay(d);
  digitalWrite(13, LOW); 
  }
  delay(t);
  }

lcd.clear();
delay(10);
}
