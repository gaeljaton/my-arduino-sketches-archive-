// Declaration of Varialbes
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;
int clock_step;

// Initialization
void setup() {
Serial.begin(38400);
clock_step=0;
}

// Main Programm
void loop() {
if(Serial.available() > 0) {
data = Serial.read();
Serial.println(data); 
if(data == midi_start) {
play_flag = 1;
clock_step=0;
}
else if(data == midi_continue) {
play_flag = 1;
}
else if(data == midi_stop) {
play_flag = 0;
clock_step=0;
}
if((data == midi_clock)) {
Sync();
digitalWrite(13, HIGH); 

}
}
}



// Function

void Sync() { // 1st half of a bar: LED=on, seconds half of a bar: LED=off
clock_step = clock_step+1;
if (clock_step==1){
digitalWrite(13, HIGH); // set the LED on
}
else if (clock_step==96/2){
digitalWrite(13, LOW); // set the LED off
}
else if (clock_step==96){
clock_step=0;
}
}


