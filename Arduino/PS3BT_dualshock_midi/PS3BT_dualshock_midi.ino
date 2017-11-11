/*
PS3 sixaxis Midi Controller
 */
#include <PS3BT.h>
USB Usb;
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
/* You can create the instance of the class in two ways */
//PS3BT PS3(&Btd); // This will just create the instance
PS3BT PS3(&Btd, 0x00, 0x11, 0x22, 0x98, 0x76, 0x54); // This will also store the bluetooth address - this can be obtained from the dongle when running the sketch

bool printTemperature;
bool printAngle;
bool Btriangle =0;
bool Bcircle =0;
bool Bcross =0;
bool Bsquare =0;
bool Bup =0;
bool Bright =0;
bool Bdown =0;
bool Bleft =0;
bool Bl1 =0;
bool Bl3 =0;
bool Br1 =0;
bool Br3 =0;
bool Bstart =0;
bool Bselect =0;
void setup() {
  Serial.begin(9600);
  //  Set MIDI baud rate:
  //Serial.begin(31250);
  if (Usb.Init() == -1) {
    
    while (1); //halt
  }
  pinMode(6, OUTPUT);
  analogWrite(6, 50);
  digitalWrite (13, HIGH);
}
void loop() {
  Usb.Task();
  delay(1);
  
  if (PS3.PS3Connected ) {
    if (PS3.getButtonClick(PS)) PS3.disconnect();
    
/////////////////////////////////////////Note On///////////////////////////////////////////////////
      if (PS3.getButtonClick(TRIANGLE))
       { Serial.write(0x96); Serial.write(0x20); Serial.write(0x40); Btriangle=1;}
      if (PS3.getButtonClick(CIRCLE))
       { Serial.write(0x96); Serial.write(0x30); Serial.write(0x40); Bcircle =1;}
      if (PS3.getButtonClick(CROSS))
       { Serial.write(0x96); Serial.write(0x40); Serial.write(0x40); Bcross =1;}
      if (PS3.getButtonClick(SQUARE))
       { Serial.write(0x96); Serial.write(0x50); Serial.write(0x40); Bsquare =1;}
      if (PS3.getButtonClick(UP))
       { Serial.write(0x96); Serial.write(0x21); Serial.write(0x40); Bup =1;}
      if (PS3.getButtonClick(RIGHT)) 
       {digitalWrite (13, LOW); Serial.write(0x96); Serial.write(0x31); Serial.write(0x40); Bright =1;}
      if (PS3.getButtonClick(DOWN)) 
       { Serial.write(0x96); Serial.write(0x41); Serial.write(0x40); Bdown =1;}
      if (PS3.getButtonClick(LEFT))
       {digitalWrite (13, HIGH); Serial.write(0x96); Serial.write(0x51); Serial.write(0x40); Bleft =1;}
      if (PS3.getButtonClick(L1))
       { Serial.write(0x96); Serial.write(0x1A); Serial.write(0x40); Bl1 =1;}
      if (PS3.getButtonClick(R1))
       { Serial.write(0x96); Serial.write(0x2A); Serial.write(0x40); Br1 =1;}
      if (PS3.getButtonClick(L3))
       { Serial.write(0x96); Serial.write(0x1B); Serial.write(0x40); Bl3 =1;}
      if (PS3.getButtonClick(R3))
       { Serial.write(0x96); Serial.write(0x2B); Serial.write(0x40); Br3 =1;}
      if (PS3.getButtonClick(SELECT))
       { Serial.write(0x96); Serial.write(0x1C); Serial.write(0x40); Bselect =1;}
      if (PS3.getButtonClick(START))
       { Serial.write(0x96); Serial.write(0x2C); Serial.write(0x40); Bstart =1;}

//////////////////////////////////////////Note Off///////////////////////////////////////////////
      if (Btriangle ==1 & !PS3.getButtonPress(TRIANGLE))
       { Serial.write(0x86); Serial.write(0x20); Serial.write(0x00); Btriangle=0;}
      if (Bcircle ==1 & !PS3.getButtonPress(CIRCLE))
       { Serial.write(0x86); Serial.write(0x30); Serial.write(0x00); Bcircle =0;}
      if (Bcross ==1 & !PS3.getButtonPress(CROSS))
       { Serial.write(0x86); Serial.write(0x40); Serial.write(0x00); Bcross =0;}
      if (Bsquare ==1 & !PS3.getButtonPress(SQUARE))
       { Serial.write(0x86); Serial.write(0x50); Serial.write(0x00); Bsquare =0;}
      if (Bup ==1 & !PS3.getButtonPress(UP))
       { Serial.write(0x86); Serial.write(0x21); Serial.write(0x00); Bup =0;}
      if (Bright ==1 & !PS3.getButtonPress(RIGHT)) 
       { Serial.write(0x86); Serial.write(0x31); Serial.write(0x00); Bright =0;}
      if (Bdown ==1 & !PS3.getButtonPress(DOWN)) 
       { Serial.write(0x86); Serial.write(0x41); Serial.write(0x00); Bdown =0;}
      if (Bleft ==1 & !PS3.getButtonPress(LEFT))
       { Serial.write(0x86); Serial.write(0x51); Serial.write(0x00); Bleft =0;}
      if (Bl1 ==1 & !PS3.getButtonPress(L1))
       {  Serial.write(0x86); Serial.write(0x1A); Serial.write(0x00); Bl1 =0;}
      if (Br1 ==1 & !PS3.getButtonPress(R1))
       { Serial.write(0x86); Serial.write(0x2A); Serial.write(0x00); Br1 =0;}
      if (Bl3 ==1 & !PS3.getButtonPress(L3))
       { Serial.write(0x86); Serial.write(0x1B); Serial.write(0x00); Bl3 =0;}
      if (Br3 ==1 & !PS3.getButtonPress(R3))
       { Serial.write(0x86); Serial.write(0x2B); Serial.write(0x00); Br3 =0;}
      if (Bselect ==1 & !PS3.getButtonPress(SELECT))
       { Serial.write(0x86); Serial.write(0x1C); Serial.write(0x00); Bselect =0;}
      if (Bstart ==1 & !PS3.getButtonPress(START))
       { Serial.write(0x86); Serial.write(0x2C); Serial.write(0x00); Bstart =0;}
       
///////////////////////////////////////////////////////Analogs////////////////////////////////////////////
byte LX=PS3.getAnalogHat(LeftHatX)/2;
Serial.write(0xB6); Serial.write(0x51); Serial.write(LX); 
byte LY=PS3.getAnalogHat(LeftHatY)/2;
Serial.write(0xB6); Serial.write(0x41); Serial.write(LY); 
byte RX=PS3.getAnalogHat(RightHatX)/2;
Serial.write(0xB6); Serial.write(0x50); Serial.write(RX); 
byte RY=PS3.getAnalogHat(RightHatY)/2;
Serial.write(0xB6); Serial.write(0x40); Serial.write(RY); 
byte Ldeux=PS3.getAnalogButton(L2)/2;
Serial.write(0xB6); Serial.write(0x61); Serial.write(Ldeux); 
byte Rdeux=PS3.getAnalogButton(R2)/2;
Serial.write(0xB6); Serial.write(0x60); Serial.write(Rdeux); 

/////////////////////////////////////////////////////Accelerometers////////////////////////////////////////////////////
int accX=PS3.getSensor(aX)*16;
Serial.write(0xB6); Serial.write(0x07); Serial.write((accX>>7)&127); 
Serial.write(0xB6); Serial.write(0x27); Serial.write(accX&127); 
int accY=PS3.getSensor(aY)*16;
Serial.write(0xB6); Serial.write(0x08); Serial.write((accY>>7)&127); 
Serial.write(0xB6); Serial.write(0x28); Serial.write(accY&127); 
int accZ=PS3.getSensor(aZ)*16;
Serial.write(0xB6); Serial.write(0x09); Serial.write((accZ>>7)&127); 
Serial.write(0xB6); Serial.write(0x29); Serial.write(accZ&127); 
}
}
