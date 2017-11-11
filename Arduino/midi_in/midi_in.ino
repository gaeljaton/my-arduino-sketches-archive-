
// Declaration of Varialbes
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;
int clock_step;
int note;
int noteval;
int LowestNote;
int HighestNote;

int Note1;
int Note2;
int Note3;
int Note4;
int Note5;
int Note6;
int Note7;
int Note8;
int Note9;
int Note10;
int Note11;
int Note12;
int Note13;
int Note14;
int Note15;
int Note16;

int SeqLength;

int ShufflePin;
int Shuffle_Flag;
int ShuffleDelay;

// Initialization
void setup() {
Serial.begin(31250);
clock_step=0;
note = 0x3F;
noteval = 0;
LowestNote=36;
HighestNote=36+3*12; //3 Octaves over LowestNote

ShufflePin = 2;
pinMode(ShufflePin, INPUT); //Pin 0 for shuffle on/off as input
Shuffle_Flag = 0;
ShuffleDelay = 0;

Note1 = (96*1)/16-5;
Note2 = (96*2)/16-5;
Note3 = (96*3)/16-5;
Note4 = (96*4)/16-5;
Note5 = (96*5)/16-5;
Note6 = (96*6)/16-5;
Note7 = (96*7)/16-5;
Note8 = (96*8)/16-5;
Note9 = (96*9)/16-5;
Note10 = (96*10)/16-5;
Note11 = (96*11)/16-5;
Note12 = (96*12)/16-5;
Note13 = (96*13)/16-5;
Note14 = (96*14)/16-5;
Note15 = (96*15)/16-5;
Note16 = (96*16)/16-5;

SeqLength = 6*16; //Sequence length is 16*16th notes

pinMode(22, OUTPUT);
pinMode(24, OUTPUT);
pinMode(26, OUTPUT);
pinMode(28, OUTPUT);
pinMode(30, OUTPUT);
pinMode(32, OUTPUT);
pinMode(34, OUTPUT);
pinMode(36, OUTPUT);
pinMode(38, OUTPUT);
pinMode(40, OUTPUT);
pinMode(42, OUTPUT);
pinMode(44, OUTPUT);
pinMode(46, OUTPUT);
pinMode(48, OUTPUT);
pinMode(50, OUTPUT);
pinMode(52, OUTPUT);

digitalWrite(22, HIGH);
digitalWrite(24, LOW);
digitalWrite(26, LOW);
digitalWrite(28, LOW);
digitalWrite(30, LOW);
digitalWrite(32, LOW);
digitalWrite(34, LOW);
digitalWrite(36, LOW);
digitalWrite(38, LOW);
digitalWrite(40, LOW);
digitalWrite(42, LOW);
digitalWrite(44, LOW);
digitalWrite(46, LOW);
digitalWrite(48, LOW);
digitalWrite(50, LOW);
digitalWrite(52, LOW);
}

// Main Programm
void loop() {

Shuffle_Flag = digitalRead(ShufflePin);

if(Shuffle_Flag == LOW) {
ShuffleDelay = 0;
}
if (Shuffle_Flag == HIGH){
ShuffleDelay = 2; // start every 2nd note two MIDI clock signals later
}

if(Serial.available() > 0) {
data = Serial.read();
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
sendMidiNote (0x80, note, 0x7F); //last note off
digitalWrite(22, HIGH);
digitalWrite(24, LOW);
digitalWrite(26, LOW);
digitalWrite(28, LOW);
digitalWrite(30, LOW);
digitalWrite(32, LOW);
digitalWrite(34, LOW);
digitalWrite(36, LOW);
digitalWrite(38, LOW);
digitalWrite(40, LOW);
digitalWrite(42, LOW);
digitalWrite(44, LOW);
digitalWrite(46, LOW);
digitalWrite(48, LOW);
digitalWrite(50, LOW);
digitalWrite(52, LOW);
}
else if((data == midi_clock) && (play_flag == 1)) {
Sync();
}
}
}


// Functions

void Sync() { // play 16 x 16th notes, repeat after the cycle is finshed
clock_step = clock_step+1;

Note1 = (96*1)/16-5;
Note2 = (96*2)/16-5+ShuffleDelay;
Note3 = (96*3)/16-5;
Note4 = (96*4)/16-5+ShuffleDelay;
Note5 = (96*5)/16-5;
Note6 = (96*6)/16-5+ShuffleDelay;
Note7 = (96*7)/16-5;
Note8 = (96*8)/16-5+ShuffleDelay;
Note9 = (96*9)/16-5;
Note10 = (96*10)/16-5+ShuffleDelay;
Note11 = (96*11)/16-5;
Note12 = (96*12)/16-5+ShuffleDelay;
Note13 = (96*13)/16-5;
Note14 = (96*14)/16-5+ShuffleDelay;
Note15 = (96*15)/16-5;
Note16 = (96*16)/16-5+ShuffleDelay;

if (clock_step==Note1){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(0);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(22, HIGH);
digitalWrite(52, LOW);
}

if (clock_step==Note2){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(1);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(24, HIGH);
digitalWrite(22, LOW);
}

if (clock_step==Note3){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(2);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(26, HIGH);
digitalWrite(24, LOW);
}

if (clock_step==Note4){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(3);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(28, HIGH);
digitalWrite(26, LOW);
}

if (clock_step==Note5){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(4);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(30, HIGH);
digitalWrite(28, LOW);
}

if (clock_step==Note6){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(5);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(32, HIGH);
digitalWrite(30, LOW);
}

if (clock_step==Note7){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(6);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(34, HIGH);
digitalWrite(32, LOW);
}

if (clock_step==Note8){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(7);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(36, HIGH);
digitalWrite(34, LOW);
}

if (clock_step==Note9){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(8);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(38, HIGH);
digitalWrite(36, LOW);
}

if (clock_step==Note10){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(9);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(40, HIGH);
digitalWrite(38, LOW);
}

if (clock_step==Note11){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(10);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(42, HIGH);
digitalWrite(40, LOW);
}

if (clock_step==Note12){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(11);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(44, HIGH);
digitalWrite(42, LOW);
}

if (clock_step==Note13){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(12);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(46, HIGH);
digitalWrite(44, LOW);
}

if (clock_step==Note14){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(13);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(48, HIGH);
digitalWrite(46, LOW);
}

if (clock_step==Note15){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(14);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(50, HIGH);
digitalWrite(48, LOW);
}

if (clock_step==Note16){
sendMidiNote (0x80, note, 0x7F); //last note off
noteval = analogRead(15);
note = map(noteval, 0, 1023, LowestNote, HighestNote);
sendMidiNote (0x90, note, 0x7F); //note of this step on
digitalWrite(52, HIGH);
digitalWrite(50, LOW);
}

else if (clock_step==SeqLength){
clock_step=0;
}
}

void sendMidiNote (byte midiCommand, byte noteValue, byte velocityValue){
Serial.print(midiCommand, BYTE);
Serial.print(noteValue, BYTE);
Serial.print(velocityValue, BYTE);
}
