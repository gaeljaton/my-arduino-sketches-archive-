
unsigned long t=0 ;
unsigned long tb=0 ;
unsigned long ti=0 ;

void setup() 
{   
 //baut rate:
  Serial.begin(31250);
  //Serial.begin(9600);
  delay(10);
  Serial.write(250);
  delay(10);
}
  

void loop() {
//  digitalWrite(13, HIGH);   // set the LED on
//  delay(1000);              // wait for a second
//  digitalWrite(13, LOW);    // set the LED off
//  delay(1000);              // wait for a second
// for (int i=0; i <= 48; i++){

if(digitalRead(10) == HIGH)
{
  ti = micros();
  t = tb - ti;
  for(int i=0; i<24; i++)
  {
    Serial.write(0xf8);
    delayMicroseconds((t/24)-50);
  }
}
//start sequence
//        Serial.print(250, BYTE);
//        clocksignals = true;
//      }else{
//        //stop sequence
//        Serial.print(252, BYTE);
//        clocksignals = false;


//delay(5000);
// Serial.write(252);


//
//    * clock (decimal 248, hex 0xF8)
//    * start (decimal 250, hex 0xFA)
//    * continue (decimal 251, hex 0xFB)
//    * stop (decimal 252, hex 0xFC)


}
