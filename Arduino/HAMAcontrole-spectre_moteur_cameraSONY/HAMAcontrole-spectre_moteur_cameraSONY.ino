#define STROBE 4
#define RESET 5
#define DC_One A1
int freq_amp;
int Frequencies_One[7];
unsigned long previousmillis=0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
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
  
unsigned long currentMillis = millis();
  if(currentMillis-previousmillis >= analogRead(0)/10)
  {previousmillis = millis();
  digitalWrite(3, HIGH); delay(5); digitalWrite(3, LOW);}
 
 delay (10);
 
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Frequencies_One[freq_amp] = analogRead(DC_One);
    digitalWrite(STROBE, HIGH);
 delay(2);
    digitalWrite(STROBE, LOW);
    delay(2);
    }
int l=(Frequencies_One[0])/3;
 l = constrain(l, 0, 255);
 
 int m=(Frequencies_One[2])/3;
 m = constrain(m, 0, 255);
 
 int h=(Frequencies_One[4])/3;
 h = constrain(h, 0, 255);
  
  analogWrite (9 , l);
  analogWrite (10 , m);
  analogWrite (11 , h);
  
}
