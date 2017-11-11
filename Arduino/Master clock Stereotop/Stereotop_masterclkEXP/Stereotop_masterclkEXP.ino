//########################### VARIABLES TEMPS ##################################
int duree=90; // durée totale en min
int bpmi=30; // bpm début
int bpmf=300; // bpm fin
//##############################################################################

 byte midi=0;
 float ti;
 float tf;
 float tt; 
 unsigned long previousmicros=0; 
 float T;
 float a;

void setup() { Serial.begin(31250); //start serial with midi baudrate 31250
 Serial.write(0xfa); //midi start
 ti=60000000/(bpmi);
 tf=60000000/(bpmf);
 tt=duree*60000; 

 }
 
void loop () {

  if (millis()<=tt){
 if(micros() - previousmicros > T)
  {
  previousmicros = micros();

  Serial.write(0xf8); // ****MIDI Clock****
  if(midi<12){analogWrite(6,midi*22+10);digitalWrite(5,HIGH);digitalWrite(3,LOW);}
        else{analogWrite(6,(23-midi)*22+10);digitalWrite(5,LOW);digitalWrite(3,HIGH);}
   if (midi==0){digitalWrite(2,HIGH); }else{digitalWrite(2,LOW);}
   
  
a=millis()*(ti-tf)/tt; 
T = (ti - a)/24;
  
  ++midi; 
  if(midi>23){midi=0;}
  }
  }
  if(millis()>tt){analogWrite(6,0);digitalWrite(5,LOW);digitalWrite(3,LOW);digitalWrite(2,LOW);}

}
