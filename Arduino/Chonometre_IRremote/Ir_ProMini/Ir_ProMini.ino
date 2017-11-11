#include <IRremote.h>
const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
const byte mstart = 0xFA;
const byte mstop = 0xFC;
const byte mclk = 0xF8;
const byte up10 = 0xF9;
const byte dw10 = 0xF7;
const byte up1 = 0xF5;
const byte dw1 = 0xF2;
const byte prev = 0xF4;
const byte next = 0xF6;


long incommingByte;

void setup()
{
  pinMode (3, OUTPUT); digitalWrite (3, LOW);
  pinMode (4, OUTPUT);  digitalWrite (4, HIGH);
  pinMode (9, OUTPUT); digitalWrite (18, LOW);
  // Serial.begin(31250);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);
 
}

void loop() {
  if (irrecv.decode(&results)) {
    incommingByte = results.value ;
    switch (incommingByte) {
      case 0x6170A45B:
        Serial.write(mstart);
        break;
      case 0x617048B7:
        Serial.write(mstop);
        break;
      case 0x617008F7:
        Serial.write(up10);
        break;
      case 0x617058A7:
        Serial.write(dw10);
        break;
      case 0x617038C7:
        Serial.write(next);
        break;
      case 0x6170D02F:
        Serial.write(up1);
        break;
      case 0x6170D827:
        Serial.write(prev);
        break;
      case 0x617030CF:
        Serial.write(dw1);
        break;  
      default:
        break;
    }
//    Serial.print( "\t" );
//    Serial.println(results.value, HEX);
    digitalWrite (9,HIGH );
    delay(20);
    digitalWrite (9, LOW);
    irrecv.resume(); // Receive the next value
  }
}

