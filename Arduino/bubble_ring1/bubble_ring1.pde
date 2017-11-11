#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 
int v; //vitesse
int t; //période totale
int d; //durée impusion
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);// initialisation LCD en mode 4 bits 


void setup()  
{     
pinMode(19, OUTPUT);  
pinMode(18, OUTPUT);  
 
lcd.begin(20,4); 
delay(10); // pause rapide pour laisser temps initialisation

lcd.print("LCD OK") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran
}

void loop(){ 
  
d = analogRead(0)*20;
lcd.setCursor(0, 0) ; 
lcd.print("t implusion") ;
lcd.setCursor(0, 12) ; 
lcd.print(d) ;
digitalWrite(18, HIGH);  // set the LED on
delayMicroseconds(d);
digitalWrite(18, LOW); 
 delay(500);
lcd.clear();

}
