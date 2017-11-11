int dT = 2000;

byte counter; 
byte CLOCK = 248; 
byte START = 250; 
byte CONTINUE = 251; 
byte STOP = 252; 

int sync_24_pulse_pin = 14; 
int sync_24_start_pin = 11; 
int sync_24_continue_pin = 13; 
int sync_ground = 12; 

void setup() {
  pinMode(sync_ground, OUTPUT); 
  digitalWrite(sync_ground, LOW);
  pinMode(sync_24_start_pin, OUTPUT); // Sync 24 sync pulse output
  pinMode(sync_24_continue_pin, OUTPUT); // Sync 24 sync pulse output
  
  pinMode(sync_24_start_pin, OUTPUT); // Sync 24 start / stop output
  usbMIDI.setHandleRealTimeSystem(RealTimeSystem);
  
}

void loop() {
  usbMIDI.read(); 

}

void RealTimeSystem(byte realtimebyte) {
  if(realtimebyte == CLOCK) {
    dinSync(); 
  }
  if(realtimebyte == START) {
    digitalWrite(sync_24_start_pin, HIGH); 
    digitalWrite(sync_24_continue_pin, LOW); 
  }
  if(realtimebyte == CONTINUE) {
    digitalWrite(sync_24_start_pin, HIGH); 
    digitalWrite(sync_24_continue_pin, HIGH); 
  }
  if(realtimebyte == STOP) {
    digitalWrite(sync_24_start_pin, LOW);  
    digitalWrite(sync_24_continue_pin, LOW); 
  }
}


void dinSync() {
  digitalWrite(sync_24_pulse_pin, HIGH); 
  delayMicroseconds(dT); 
  digitalWrite(sync_24_pulse_pin, LOW); 


}
