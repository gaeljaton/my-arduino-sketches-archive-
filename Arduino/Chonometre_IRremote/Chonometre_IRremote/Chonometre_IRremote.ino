#define DATAOUT 11 //MOSI
#define DATAIN 12 //MISO 
#define SPICLOCK 13 //sck
#define SLAVESELECT 10 //ss
#include <SPI.h>
#include <DigitShield.h>
#include <AltSoftSerial.h>
AltSoftSerial mySerial; //8 RX, 9 TX
const byte mstart = 0xFA;
const byte mstop = 0xFC;
const byte mclk = 0xF8;
const byte up10 = 0xF9;
const byte dw10 = 0xF7;
const byte up1 = 0xF5;
const byte dw1 = 0xF2;
const byte prev = 0xF4;
const byte next = 0xF6;
int clkMode = 0; //0 no clock, 1 set bpm, 2 set bpmi , 3 set bpmf, 4 set durée de la montée, 5 lin clock, 6 exp clock
float bpm = 120;
float t;
float t2;
int bpmi = 40;
int bpmf = 300;
int timeSeq = 1; //durée de l'accelleration en minutes
byte ledcode[10] = {
  B00111111, // = 0
  B00000110, // = 1
  B01011011, // = 2
  B01001111, // = 3
  B01100110, // = 4
  B01101101, // = 5
  B01111101, // = 6
  B00000111, // = 7
  B01111111, // = 8
  B01101111 // = 9
};
unsigned long nextsecond = 0;
unsigned long startTime = 0;
unsigned long midiTime ;
unsigned long analogStop ;
byte midiStep = 1;
byte inByte;
byte s = 0;
byte ss = 0;
byte m = 0;
byte mm = 0;
byte play = 0;

void setup()
{
  //Serial.begin(9600);
   Serial.begin(31250); //start serial with midi baudrate 31250
  mySerial.begin(9600);
  SPI.begin();
  Serial.print("ready");
  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);
  pinMode(SLAVESELECT, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  digitalWrite(SLAVESELECT, HIGH); //disable device
  delay(100);
  digitalWrite(SLAVESELECT, LOW);
  delay(10);
  SPI.transfer(B01110011);           // 4th Digit P
  SPI.transfer(B00111111);           // 3th Digit O
  SPI.transfer(B01110000);           // 2th Digit t
  SPI.transfer(B01101101);           // 1th Digit S
  digitalWrite(SLAVESELECT, HIGH);
  delay(10);
  DigitShield.begin();
  for (int n = 1; n < 5; ++n) {
    DigitShield.setDecimalPoint(n, 0) ;
  }

}

void loop()
{
  if (mySerial.available() > 0) {// telecommande de ProMini
    inByte = mySerial.read();
    switch (inByte) { //fonctions télecommande
      case mstart: //START
        if (play == 0) {
          for (int n = 1; n < 5; ++n) {
            DigitShield.setDecimalPoint(n, 0) ;
           
          }
          Serial.write(mstart);
           midiStep = 1; nextsecond = millis(); startTime = millis(); midiTime = micros() ;//+ (60000000 / (bpm * 24)) ; 
           if(clkMode <= 5 ){bpm = bpmi;}
        }
        play = 1;
        DigitShield.setBlank(0);
        break;
      case mstop: //STOP
        play = 0; s = 0; ss = 0; m = 0; mm = 0; clkMode = 0;
        Serial.write(mstop);
        digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B01110011);           // 4th Digit P
        SPI.transfer(B00111111);           // 3th Digit O
        SPI.transfer(B01110000);           // 2th Digit t
        SPI.transfer(B01101101);           // 1th Digit S
        digitalWrite(SLAVESELECT, HIGH);
        delay (10);
        DigitShield.setBlank(1);
        for (int n = 1; n < 5; ++n) {

        }
        break;
      case up10: //+10
        switch (clkMode) {
          case 1 : bpm = bpm + 10; break;
          case 2 : bpmi = bpmi + 10; break;
          case 3 : bpmf = bpmf + 10; break;
          case 4 : timeSeq = timeSeq + 10; break;
          default:
            break;
        }
        break;

      case dw10: //-10
        switch (clkMode) {
          case 1 : bpm = bpm - 10; break;
          case 2 : bpmi = bpmi - 10; break;
          case 3 : bpmf = bpmf - 10; break;
          case 4 : timeSeq = timeSeq - 10; break;
          default:
            break;
        }
        break;
      case dw1: //-1
        switch (clkMode) {
          case 1 : bpm = bpm - 1; break;
          case 2 : bpmi = bpmi - 1; break;
          case 3 : bpmf = bpmf - 1; break;
          case 4 : timeSeq = timeSeq - 1 ; break;
          default:
            break;
        }
        break;

      case up1: //+1
        switch (clkMode) {
          case 1 : bpm = bpm + 1; break;
          case 2 : bpmi = bpmi + 1; break;
          case 3 : bpmf = bpmf + 1; break;
          case 4 : timeSeq = timeSeq + 1; break;
          default:
            break;
        }
        break;

      case next: //menu suivant
        ++clkMode;
        if (clkMode > 6) {
          clkMode = 0;
        }
        break;
      case prev: //menu précedent
        --clkMode;
        if (clkMode < 0) {
          clkMode = 6;
        }
        break;
      default:
        break;



    }
    switch (clkMode) { //affichage données
      case 0 : digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B01110011);           // 4th Digit P
        SPI.transfer(B00111111);           // 3th Digit O
        SPI.transfer(B01110000);           // 2th Digit t
        SPI.transfer(B01101101);           // 1th Digit S
        digitalWrite(SLAVESELECT, HIGH);
        delay(10) ;
        DigitShield.setBlank(1);
        break;
      case 1 :  digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B00000000);           // 4th Digit
        SPI.transfer(B01110000);           // 3th Digit t
        SPI.transfer(B01111001);           // 2th Digit E
        SPI.transfer(B01101101);           // 1th Digit S
        digitalWrite(SLAVESELECT, HIGH);
        delay(10);
        DigitShield.setBlank(0); DigitShield.setValue(bpm);
        break;
      case 2 :  digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B00110000);           // 4th Digit I
        SPI.transfer(B00001000);           // 3th Digit _
        SPI.transfer(B01110011);           // 2th Digit P
        SPI.transfer(B01111100);           // 1th Digit b
        digitalWrite(SLAVESELECT, HIGH);
        delay(10);
        DigitShield.setBlank(0); DigitShield.setValue(bpmi); break;
      case 3 : digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B01110001);           // 4th Digit F
        SPI.transfer(B00001000);           // 3th Digit _
        SPI.transfer(B01110011);           // 2th Digit P
        SPI.transfer(B01111100);           // 1th Digit b
        digitalWrite(SLAVESELECT, HIGH);
        delay(10);
        DigitShield.setBlank(0); DigitShield.setValue(bpmf); break;
      case 4 : digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B00000000);           // 4th Digit
        SPI.transfer(B11010000);           // 3th Digit r.
        SPI.transfer(B00011100);           // 2th Digit u
        SPI.transfer(B01011110);           // 1th Digit d
        digitalWrite(SLAVESELECT, HIGH);
        delay(10);
        DigitShield.setBlank(0); DigitShield.setValue(timeSeq); break;
      case 5 : digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B01111001);           // 4th Digit E
        SPI.transfer(B01011110);           // 3th Digit d
        SPI.transfer(B01011100);           // 2th Digit o
        SPI.transfer(B01010100);           // 1th Digit n
        digitalWrite(SLAVESELECT, HIGH);
        delay(10);
        DigitShield.setBlank(0); DigitShield.setValue(1); break;
      case 6 : digitalWrite(SLAVESELECT, LOW);
        delay(10);
        SPI.transfer(B01111001);           // 4th Digit E
        SPI.transfer(B01011110);           // 3th Digit d
        SPI.transfer(B01011100);           // 2th Digit o
        SPI.transfer(B01010100);           // 1th Digit n
        digitalWrite(SLAVESELECT, HIGH);
        delay(10);
        DigitShield.setBlank(0); DigitShield.setValue(2); break;
      default:
        break;
    }
    //Serial.println(inByte, HEX);
  }
  if (play == 1) {
    if (millis() >= nextsecond) ///////// CHRONOMETRE //////////////
    { digitalWrite(SLAVESELECT, LOW);
      delay(10);
      SPI.transfer(ledcode[s]);             // 4th Digit
      SPI.transfer(ledcode[ss]);            // 3th Digit
      SPI.transfer(ledcode[m] + 128);       // 2th Digit
      SPI.transfer(ledcode[mm] );           // 1th Digit
      digitalWrite(SLAVESELECT, HIGH);
      delay(10);
      nextsecond = nextsecond + 1000; ++s; if (s > 9)
      { s = 0; ++ss; if (ss > 5)
        { ss = 0; ++m; if (m > 9)
          {
            m = 0;
            ++mm;
            if (mm > 9) {}
          }
        }
      }
      SPI.endTransaction();
      if (clkMode != 0) {
        DigitShield.setBlank(0);
        DigitShield.setValue(bpm);
      } else {
        DigitShield.setBlank(1);
      }
    }


    if (micros() >= midiTime) ///////////// Clock ////////////////////
    {if(clkMode<5 || millis()-startTime <= timeSeq*60000){
      Serial.write(mclk); ++midiStep ; if (midiStep > 24) {
        midiStep = 1;
      }
      if (midiStep == 1) {
        digitalWrite(14, HIGH); digitalWrite(15, HIGH); digitalWrite(16, HIGH); 
        analogStop= analogStop+150;
        for (int n = 1; n < 5; ++n) {
          DigitShield.setDecimalPoint(n, 1) ;
        }
      }
      else {
        for (int n = 1; n < 5; ++n) {
          DigitShield.setDecimalPoint(n, 0) ; 
        }
      }
      
      
      switch (clkMode) { // calcul BPM acceleration
      
        case 5: //bpm mode lin
        if(millis()-startTime <= timeSeq*60000){bpm= (millis()-startTime)*(bpmf-bpmi)/(timeSeq*60000)+bpmi;}
        break;
        case 6: //bpm mode Exp
         if(millis()-startTime <= timeSeq*60000){ t=pow((millis()-startTime)/(timeSeq),2); bpm = (bpmf-bpmi)*t/3600000000 + bpmi;}
        break;
        
      default:
        break;
    }
      DigitShield.setValue(bpm);
      midiTime = midiTime + (60000000 / (bpm * 24)) ;
    }
    else{DigitShield.setBlank(1);}
  }
  }
  if (millis()>=analogStop){digitalWrite(14, LOW); digitalWrite(15, LOW); digitalWrite(16, LOW); } /////// falldown analog out
}




