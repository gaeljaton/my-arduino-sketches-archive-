

boolean clocksignals = false;

unsigned long McM = 0;
unsigned long LcM = 0;
unsigned long RcM = 0;

boolean ledA = LOW;

boolean nanclock = LOW;

//lsdj L&R clock pins
byte LPin = 5;
byte RPin = 13;

byte TrACounter = 0;
byte triggerA = 7;
byte triggerB = 2;
boolean TrAB = LOW;

unsigned long analogValueA = 0;

int ledPin = 3;

boolean BRead[2] = {HIGH, HIGH};

//http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1208715493/11
#define FASTADC 1

//defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

void setup(){

  #if FASTADC
    // set prescale to 16
    sbi(ADCSRA,ADPS2) ;
    cbi(ADCSRA,ADPS1) ;
    cbi(ADCSRA,ADPS0) ;
  #endif
  
  //trigger pins
  pinMode(triggerA, OUTPUT);  
  pinMode(triggerB, OUTPUT);
  
  //LEDs
  pinMode(ledPin, OUTPUT);                //  speed indication
  
  //buttons
  pinMode(9, INPUT);                      //  start/stop
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  
  //lsdj clock internal pins
  pinMode(LPin, OUTPUT);  
  pinMode(RPin, OUTPUT);
  
  //nanoloop clock internal pins
  pinMode(12, OUTPUT);  
  pinMode(6, OUTPUT);
  
  //baut rate:
  Serial.begin(31250);
  //Serial.begin(9600);
}

void loop(){
  
  analogValueA = map(analogRead(0), 0, 1023, 10000, 32000);  // delay settings
  
  BRead[0] = digitalRead(9);
  BRead[1] = digitalRead(11);
  
  StartStop();
  
  MClockerLSDj();
  LClockerLSDj();
  RClockerLSDj();
  
}

boolean SS = false;
boolean hold = false;
void StartStop(){
  
  if(digitalRead(10) == LOW){
    hold = true;
  }
  
  if(digitalRead(10) == HIGH){
    
    if(hold){
      SS = !SS;
      if(SS){
        //start sequence
        Serial.print(250, BYTE);
        clocksignals = true;
      }else{
        //stop sequence
        Serial.print(252, BYTE);
        clocksignals = false;
      }
      hold = false;
    }
  }
}

byte indicatorLed = 0;
//master clock LSDj
void MClockerLSDj(){
  if(micros() - McM > analogValueA){
    McM = micros();
    
    //midi timing clock
    Serial.print(248, BYTE);
    
    if(clocksignals){
      //speed indicator LED
      ledA = !ledA;
      digitalWrite(ledPin, ledA);
      //nanoloop
      digitalWrite(6, ledA);
      digitalWrite(12, ledA);
    }else{
      digitalWrite(ledPin, HIGH);
      //nanoloop
      digitalWrite(6, ledA);
      digitalWrite(12, ledA);
    }
    
    triggerPulses();
  }
}

//R clock LSDj
void RClockerLSDj(){
  
  if(clocksignals){
  
    unsigned long tunerDelay = 0;
    if(BRead[1] == LOW){
      tunerDelay = 1600;
    }
  
    if(micros() - RcM > (analogValueA + tunerDelay)){
      RcM = micros();
    
      //master lsdj out pulses
      for (int i=0; i <= 7; i++){
        digitalWrite(RPin, LOW);
        delayMicroseconds(61);
        digitalWrite(RPin, HIGH);
        delayMicroseconds(61);
      }
    }
  }
}

//L clock LSDj
void LClockerLSDj(){
  
  if(clocksignals){
    
    unsigned long tunerDelay = 0;
    if(BRead[0] == LOW){
      tunerDelay = 1600;
    }
  
    if(micros() - LcM > (analogValueA + tunerDelay)){
      LcM = micros();
    
      //master lsdj out pulses
      for (int i=0; i <= 7; i++){
        digitalWrite(LPin, LOW);
        delayMicroseconds(61);
        digitalWrite(LPin, HIGH);
        delayMicroseconds(61);
      }
    }
  }
}

byte triggerPulses(){
  
  if(clocksignals){
    
    TrACounter++;
    if(TrACounter > 2){
      TrACounter = 0;
      TrAB = !TrAB;
      digitalWrite(triggerA, TrAB);
      digitalWrite(triggerB, TrAB);
    }
  }
}
