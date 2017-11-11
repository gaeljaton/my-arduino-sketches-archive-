#define STROBE 4
#define RESET 5
#define DC_One A1
int freq_amp;
int Frequencies_One[7];
unsigned long previousmillis=0; 

void setup() {
  
 Serial.begin(9600);
  for (int i = 0; i<7; i++)
  {
analogWrite(9, 255);
analogWrite(10, 255);
analogWrite(11, 255);
delay (10);
analogWrite(9, 0);
analogWrite(10, 0);
analogWrite(11, 0);
delay (50);
 pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);

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
}

}

void loop() {
  

 delay (10);
 
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Frequencies_One[freq_amp] = analogRead(DC_One);
    digitalWrite(STROBE, HIGH);
 delay(2);
    digitalWrite(STROBE, LOW);
    delay(2);
    }
int l=(Frequencies_One[0]-80)/4;
 l = constrain(l, 0, 255);
 
 int m=(Frequencies_One[2]-80)/4;
 m = constrain(m, 0, 255);
 
 int h=(Frequencies_One[4]-80)/3;
 h = constrain(h, 0, 255);
  
  analogWrite (9 , l);
  analogWrite (10 , m);
  analogWrite (11 , h);
 Serial.print(l); Serial.print(m); Serial.println(h);
}
