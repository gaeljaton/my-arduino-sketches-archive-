#include <LiquidCrystal.h> // Inclusion de la librairie pour afficheur LCD 


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);// initialisation LCD en mode 4 bits 


void setup()   { 

lcd.begin(20,4); 
delay(10); // pause rapide pour laisser temps initialisation

lcd.print("LCD OK") ; // affiche la chaîne texte - message de test
delay(2000); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche
delay(10); // pour laisser temps effacer écran

}

void loop(){ // debut de la fonction loop()
lcd.setCursor(5, 0) ;
lcd.print("imput 0") ; // affiche la chaîne texte - message de test
// pause de 2 secondes

lcd.setCursor(5, 1) ; // 10ème col - 2ème ligne - positionne le curseur à l'endroit voulu (colonne, ligne) (1ère=0 !) 
lcd.print("imput 1") ; // affiche la chaîne texte - message de test
 // pause de 2 secondes

lcd.setCursor(0, 0) ; // 5ème col - 3ème ligne - positionne le curseur à l'endroit voulu (colonne, ligne) (1ère=0 !) 
lcd.print(analogRead(0)) ; // affiche la chaîne texte - message de test
// pause de 2 secondes

lcd.setCursor(0, 1) ; // 13ème col - 4ème ligne - positionne le curseur à l'endroit voulu (colonne, ligne) (1ère=0 !) 
lcd.print(analogRead(1)) ; // affiche la chaîne texte - message de test
delay(100); // pause de 2 secondes

lcd.clear(); // // efface écran et met le curseur en haut à gauche

//for (int positionCounter = 0; positionCounter < 29; positionCounter++) {lcd.print("@") ; delay(30);}
delay(10); // pour laisser temps effacer écran

//lcd.clear();
}
