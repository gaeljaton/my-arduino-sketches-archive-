#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 
unsigned long time= 0;
int v; //vitesse
float t; //période totale
float d; //durée off
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);// initialisation LCD en mode 4 bits 


void setup()  
{     
pinMode(19, OUTPUT);    
 
lcd.begin(20,4); 
delay(10); // pause rapide pour laisser temps initialisation

lcd.print("LCD OK") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran
}

void loop(){ 
  

d=(20000/(analogRead(0)*0.4+10)) ;
digitalWrite(18, HIGH);  // set the LED on
 delay(10);
digitalWrite(18, LOW); 
// set the LED off
 delay(d);

//delayMicroseconds (d+10000);

 //delay(10);
lcd.setCursor(0, 0) ; 
t = millis() - time ;
time=millis() ;
lcd.clear();
lcd.print(1000/t) ;

lcd.setCursor(4, 0) ;
lcd.print(" Hz ") ; 
lcd.setCursor(4, 3) ;
lcd.print(analogRead(0)) ; 
//lcd.print(d) ;
//v = analogRead(0);
//lcd.setCursor(0, 4) ;
//lcd.print("vitesse : ") ; 
//lcd.print(1023-v) ; 
//if (analogRead(1)< 256)
//{lcd.setCursor(0, 3) ;
//lcd.print("augmentation") ; 
//d= d- d*d/(10*v);
//}
//else if (analogRead(1)> 768)
//{
//lcd.setCursor(0, 3) ;
//lcd.print("diminution") ; 
//d= d+ d*d/(10*v);
//}
//else
//{
//lcd.setCursor(0, 3) ;
//lcd.print("stop") ; 
//d= d;}

}
