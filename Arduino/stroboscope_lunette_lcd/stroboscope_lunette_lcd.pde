#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 
unsigned long time= 0;
int v;
float t;
float d=2;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);// initialisation LCD en mode 4 bits 


void setup()  
{ 
pinMode(18, OUTPUT);     
pinMode(19, OUTPUT);    
 
lcd.begin(20,4); 
delay(10); // pause rapide pour laisser temps initialisation

lcd.print("LCD OK") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran
}

void loop(){ 
  
//d=analogRead(1);

digitalWrite(18, HIGH);  // set the LED on
digitalWrite(19, HIGH);
 delay(5);
digitalWrite(18, LOW); 
digitalWrite(19, LOW);  // set the LED off
 delay(3*d);

//delayMicroseconds (d+10000);
 lcd.clear();
 delay(10);
lcd.setCursor(0, 0) ; // 5ème col - 3ème ligne - positionne le curseur à l'endroit voulu (colonne, ligne) (1ère=0 !) 
t = millis() - time ;
time=millis() ;
lcd.print(1000/t) ;

lcd.setCursor(4, 0) ;
lcd.print(" Hz ") ; 
lcd.print(d) ;
v = analogRead(0);
lcd.setCursor(0, 4) ;
lcd.print("vitesse : ") ; 
lcd.print(1023-v) ; 
if (analogRead(1)< 256)
{lcd.setCursor(0, 3) ;
lcd.print("augmentation") ; 
d= d- d*d/(10*v);
}
else if (analogRead(1)> 768)
{
lcd.setCursor(0, 3) ;
lcd.print("diminution") ; 
d= d+ d*d/(10*v);
}
else
{
lcd.setCursor(0, 3) ;
lcd.print("stop") ; 
d= d;}

}
