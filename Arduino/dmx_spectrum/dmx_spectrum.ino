#include <DmxSimple.h>
//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A1
#define DC_Two A0 

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7]; 


/********************Setup Loop*************************/
void setup() {
    DmxSimple.usePin(3);
    DmxSimple.maxChannel(3);
   //Serial.begin(9600);

  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);  
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);
  delay (5);
  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(5);
  digitalWrite(STROBE, HIGH);
   digitalWrite(RESET, LOW);
  delay(5);
  digitalWrite(STROBE, LOW);
  delay(5);
//   DmxSimple.write(1,255);
//  DmxSimple.write(2,0);
//  DmxSimple.write(3,0);
//   delay (500);
//   DmxSimple.write(1,0);
//  DmxSimple.write(2,255);
//  DmxSimple.write(3,0);
//  delay (500);
//  DmxSimple.write(1,0);
//  DmxSimple.write(2,0);
//  DmxSimple.write(3,255);
}
/**************************Main Function Loop*****************************/
void loop() {
  
  Read_Frequencies();
  Graph_Frequencies();
}

/*******************Pull frquencies from Spectrum Shield********************/
void Read_Frequencies(){
  //Read frequencies for each band
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Frequencies_One[freq_amp] = analogRead(DC_One);
    Frequencies_Two[freq_amp] = analogRead(DC_Two); 
    digitalWrite(STROBE, HIGH);
 delay(2);
    digitalWrite(STROBE, LOW);
    delay(2);

  }
}

/*******************Light LEDs based on frequencies*****************************/
void Graph_Frequencies(){
   
 int r=(Frequencies_Two[0]+Frequencies_Two[1])-80;
 r = constrain(r, 1, 255);
 
 int v=(Frequencies_Two[2]-80)/4;
 v = constrain(v, 1, 155);
 
 int b=(Frequencies_Two[3]-80)/4;
 b = constrain(b, 1, 155);
  
  analogWrite (9 , r);
  analogWrite (10 , b);
  analogWrite (11 , v);
//  Serial.print(Frequencies_Two[0]);Serial.print("low");    Serial.print(Frequencies_Two[1]);Serial.print("   ");  Serial.print(Frequencies_Two[2]);Serial.print("   ");
//  Serial.print(Frequencies_Two[3]);Serial.print("   ");  Serial.print(Frequencies_Two[4]);Serial.print("   ");  Serial.print(Frequencies_Two[5]);Serial.print("   ");
//   Serial.println( Frequencies_Two[6]);
  delay (10);

}
