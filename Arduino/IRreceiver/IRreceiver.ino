#include <Servo.h>

#include <IRremote.h>

const int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  pinMode (3, OUTPUT); digitalWrite (3,HIGH); 
  pinMode (4, OUTPUT);  digitalWrite (4, LOW);
  //pinMode (18, OUTPUT); digitalWrite (18,HIGH); 
  // Serial.begin(31250); 
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
   Serial.print("ready");
}

void loop() {
  if (irrecv.decode(&results)) {
//    if (results.decode_type == NEC) {
//      Serial.print("NEC: ");
//    } else if (results.decode_type == SONY) {
//      Serial.print("SONY: ");
//    } else if (results.decode_type == RC5) {
//      Serial.print("RC5: ");
//    } else if (results.decode_type == RC6) {
//      Serial.print("RC6: ");
//    } else if (results.decode_type == UNKNOWN) {
//      Serial.print("UNKNOWN: ");
//    }

if (results.value != 0xFFFFFFFF) {Serial.println(results.value, HEX);}
    digitalWrite (18,LOW); 
    delay(5);
    digitalWrite (18,HIGH); 
    irrecv.resume(); // Receive the next value
    
  }
}

