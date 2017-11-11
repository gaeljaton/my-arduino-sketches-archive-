#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=82,339
AudioSynthWaveform       waveform1;      //xy=85,295
AudioSynthWaveformSine   sine1;          //xy=87,251
AudioMixer4              mixer1;         //xy=241,301
AudioSynthWaveformSineModulated sine_fm1;       //xy=386,306
AudioEffectBitcrusher    bitcrusher1;    //xy=537,306
AudioEffectEnvelope      envelope1;      //xy=671,314
AudioFilterStateVariable filter1;        //xy=798,325
AudioOutputAnalog        dac1;           //xy=1003,234
AudioMixer4              mixer2;         //xy=1009,316
AudioOutputUSB           usb1;           //xy=1010,402
AudioConnection          patchCord1(noise1, 0, mixer1, 2);
AudioConnection          patchCord2(waveform1, 0, mixer1, 1);
AudioConnection          patchCord3(sine1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, sine_fm1);
AudioConnection          patchCord5(sine_fm1, bitcrusher1);
AudioConnection          patchCord6(bitcrusher1, envelope1);
AudioConnection          patchCord7(envelope1, 0, filter1, 0);
AudioConnection          patchCord8(filter1, 0, mixer2, 0);
AudioConnection          patchCord9(filter1, 1, mixer2, 1);
AudioConnection          patchCord10(filter1, 2, mixer2, 2);
AudioConnection          patchCord11(mixer2, dac1);
AudioConnection          patchCord12(mixer2, 0, usb1, 0);
AudioConnection          patchCord13(mixer2, 0, usb1, 1);
// GUItool: end automatically generated code
