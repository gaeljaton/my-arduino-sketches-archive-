// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 1-3: First "Hello World" program, play a music file
//
// WAV files for this and other Tutorials are here:
// http://www.pjrc.com/teensy/td_libs_AudioDataFiles.html

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <IRremote.h>
#include <IRremoteInt.h>

int RECV_PIN = 16;
IRrecv irrecv(RECV_PIN);
decode_results results;

AudioPlaySdWav           playSdWav1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;

void setup() {
  Serial.begin(9600);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.7);
  SPI.setMOSI(7);
  SPI.setSCK(14);
  if (!(SD.begin(10))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  irrecv.enableIRIn(); // Start the receiver
  delay(200);
}

void loop() {


   if (irrecv.decode(&results)) { ////////////////telecommande
    Serial.println(results.value, HEX);
    if (results.value==0xAF5609F){playSdWav1.stop(); }
    if (results.value==0xAF5B04F){if (playSdWav1.isPlaying() == false) {playSdWav1.play("01.WAV"); }}
    if (results.value==0xAF5708F){if (playSdWav1.isPlaying() == false) {playSdWav1.play("02.WAV"); }}
    if (results.value==0xAF5F00F){if (playSdWav1.isPlaying() == false) {playSdWav1.play("03.WAV"); }}
    if (results.value==0xAF538C7){if (playSdWav1.isPlaying() == false) {playSdWav1.play("04.WAV"); }}
    if (results.value==0xAF5B847){if (playSdWav1.isPlaying() == false) {playSdWav1.play("05.WAV"); }}
    if (results.value==0xAF57887){if (playSdWav1.isPlaying() == false) {playSdWav1.play("06.WAV"); }}
    irrecv.resume(); // Receive the next value
      }
//  if (playSdWav1.isPlaying() == false) {
//    Serial.println("Start playing");
//    playSdWav1.play("SDTEST2.WAV");
//    delay(10); // wait for library to parse WAV info
//  }

  delay(10);
}




