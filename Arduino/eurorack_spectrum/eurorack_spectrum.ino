#define STROBE 4
#define RESET 5
#define DC_One A1
byte freq_amp =0;
int Frequencies_One[7];
int l;
int m;
int h;


void setup() {
 //TCCR2B = (TCCR2B & 0b11111000) | 0x01  ;
 //TCCR1B = (TCCR1B & 0b11111000) | 0x01  ;
   pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
   digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);
 delay (150);
 
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
}

 delay (5);
  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(5);
   digitalWrite(RESET, LOW);
   delay(5);
   digitalWrite(STROBE, HIGH);
  delay(5);
}

void loop() {
//   digitalWrite(RESET, HIGH);
//   delay(1);
//digitalWrite(STROBE, LOW);
//  delay(1);
//   digitalWrite(RESET, LOW);
//   delay(1);
//   digitalWrite(STROBE, HIGH);
//  delay(1);
 
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    digitalWrite(STROBE, LOW);
    delay(2);
    Frequencies_One[freq_amp] = analogRead(DC_One);
    
    digitalWrite(STROBE, HIGH);
 delay(2);
    
    }
 l=(Frequencies_One[0]-120)/3;
 l = constrain(l, 0, 255);
 m=(Frequencies_One[2]-120)/3;
 m = constrain(m, 0, 255);
 h=(Frequencies_One[4]-120)/3;
 h = constrain(h, 0, 255);
  
  analogWrite (9 , l);
  analogWrite (10 , m);
  analogWrite (11 , h);
 Serial.print("in");Serial.print(Frequencies_One[0]); Serial.print("__");Serial.print(Frequencies_One[1]); Serial.print("__"); Serial.print(Frequencies_One[2]); Serial.print("__");
 Serial.print(Frequencies_One[3]); Serial.print("__"); Serial.print(Frequencies_One[4]); Serial.print("__"); Serial.print(Frequencies_One[5]);
 Serial.print("__"); Serial.println(Frequencies_One[6]);
}
