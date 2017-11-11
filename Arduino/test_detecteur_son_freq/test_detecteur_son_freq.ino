
int p = 0;    // first analog sensor

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode(10, INPUT);   // digital sensor is on digital pin 2
   
}

void loop()
{
if (analogRead(0)>200)
{ Serial.println("BOOM");
digitalWrite(7,HIGH);
 delay(10);
 digitalWrite(7,LOW);
 delay(200);

//    while(digitalRead(10)==LOW){ }
//
//  p = pulseIn(10, LOW);
//  delay (10);
//   
}


}

//void midiClock(){
//  PORTB = B111100; 
//  delayMicroseconds(128); 
//  PORTB = B111111;
//}
//
//void Cstart(){
//  PORTB = B111100;    
//  delayMicroseconds(64); 
//  PORTB = B111111;  
//  delayMicroseconds(32);
//  PORTB = B111100; 
//  delayMicroseconds(32);  
//  PORTB = B111111;
//}
//
//void Cstop(){
//  PORTB = B111100;
//  delayMicroseconds(96);
//  PORTB = B111111;
//}

