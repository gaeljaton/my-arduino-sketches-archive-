#define OFF 1
#define ON 2
#define WAIT 3

byte incomingByte;
byte note;
byte previousnote =0;
byte velocity;

byte byte1;
byte byte2;
byte byte3;
int action=2; //1 =note off ; 2=note on ; 3= wait

const int trig = 9;
const int echo = 10;
long time, dist;
void setup() {
  delay(10);
  Serial.begin(31250);
  //Serial.begin(9600); 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
   pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite (2, LOW);
  digitalWrite (3, HIGH);
  digitalWrite (8, HIGH);
  digitalWrite (11, LOW);
  digitalWrite (12, LOW);
    digitalWrite (13, LOW);
    delay(100);
     digitalWrite (13, HIGH);
     delay(100);
      digitalWrite (13, LOW);
    delay(100);
     digitalWrite (13, HIGH);
     delay(100); digitalWrite (13, LOW);
    delay(100);
     digitalWrite (13, HIGH);
     delay(100); digitalWrite (13, LOW);
    delay(100);
     digitalWrite (13, HIGH);
     delay(100); digitalWrite (13, LOW);
    delay(100);
     digitalWrite (13, HIGH);
     delay(100);
     
  delay (20);
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  time = pulseIn(echo, HIGH);
  dist = (time / 2) / 2.91;
delay(10);
  if (dist < 2500) { 
  note = map(dist, 50, 2500, 100, 20);
  if(note != previousnote){
  Serial.write(0x90);
  Serial.write(note);
  Serial.write(0x7F);}
  previousnote = note;
delay (50);
//  Serial.write(0x80);
//  Serial.write(note);
//  Serial.write(0x00);
 }
}
