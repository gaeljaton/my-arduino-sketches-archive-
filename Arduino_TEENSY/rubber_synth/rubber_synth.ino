#include <Audio.h>
#include <i2c_t3.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       saw1;      //xy=195,216
AudioSynthWaveformSineModulated sine1;          //xy=198,170
AudioSynthWaveformSineModulated sine2; //xy=203,347
AudioSynthWaveform       saw2; //xy=210,403
AudioMixer4              mixer2; //xy=410,333
AudioMixer4              mixer1;         //xy=413,261
AudioOutputI2S           i2s1;           //xy=716,274
AudioConnection          patchCord1(saw1, 0, mixer1, 1);
AudioConnection          patchCord2(sine1, 0, mixer1, 0);
AudioConnection          patchCord3(sine2, 0, mixer2, 0);
AudioConnection          patchCord4(saw2, 0, mixer2, 1);
AudioConnection          patchCord5(mixer2, 0, i2s1, 1);
AudioConnection          patchCord6(mixer1, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=708,352
// GUItool: end automatically generated code




float note ;
float note1 ;
float note2 ;
float vol = 0;
float modFreq ;
float  a15;
float  a16;
float  a17;
float  a18;
float  a19;
float  a20;

void setup() {
  // Configure the pushbutton pins
 ;
  analogReadRes(13);

 
  // Audio connections require memory, and the record queue
  // uses this memory to buffer incoming audio.
  AudioMemory(160);


  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN );
  sgtl5000_1.volume(1);
 
AudioNoInterrupts();
  sine1.amplitude(1);
  saw1.begin(WAVEFORM_SQUARE);///////
  saw1.amplitude(1);

  sine2.amplitude(1);
  saw2.begin(WAVEFORM_SQUARE);///////
  saw2.amplitude(1);
  
  mixer1.gain(0, 0); ///////////////////////
  mixer1.gain(1, 0);
  mixer1.gain(2, 0);
  mixer1.gain(3, 0);

  mixer2.gain(0, 0); ///////////////////////
  mixer2.gain(1, 0);
  mixer2.gain(2, 0);
  mixer2.gain(3, 0);
 
//  bitcrusher1.bits(16); /////////////////
//  bitcrusher1.sampleRate(44100);
  AudioInterrupts();
}



void loop() {
 AudioNoInterrupts();
float vol = analogRead(A12);
float a15= analogRead(A15);
float a16= analogRead(A16);
float a17= analogRead(A17);
float a18= analogRead(A18);
float a19= analogRead(A19);
float a20= analogRead(A20);
 vol = (vol-200)/7000; 

vol= vol + a18/8191;
vol = constrain(vol, 0, 1);
 vol= vol*(a17/8191);

float sinevol = vol*a15/8191;
float sawvol = vol*a20/8191;
  mixer1.gain(0, sinevol); 
  mixer1.gain(1, sawvol);
  mixer2.gain(0, sinevol); 
  mixer2.gain(1, sawvol);
  
 float note=sq(analogRead(A13))/40000 +100 ;
 note = note+ sq(analogRead(A19))/80000;

 if (analogRead(A16)>191) {modFreq=sq(a16/8000); note1=note*(1+modFreq); note2=note/(1+modFreq); }
 //else if (analogRead(A16)>4192) {modFreq=(a16-4192)/8000; note1=note/(1+modFreq); note2=note*(1+modFreq); }
 else { note1=note; note2=note; }
 
 sine1.frequency(note1);
 saw1.frequency(note1);
 sine2.frequency(note2);
 saw2.frequency(note2);
AudioInterrupts();

 delay(5);
}


