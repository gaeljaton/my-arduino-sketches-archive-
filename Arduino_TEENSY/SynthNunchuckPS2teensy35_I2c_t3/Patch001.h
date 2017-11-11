#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine;          //xy=81,84
AudioSynthNoiseWhite     noise;         //xy=81,243
AudioSynthWaveform       triangle;      //xy=84,137
AudioSynthNoisePink      pink;          //xy=84,184
AudioMixer4              mixerfm;         //xy=274,158
AudioSynthWaveformSineModulated sinefm;       //xy=280,251
AudioEffectBitcrusher    bitcrusher;    //xy=287,328
AudioFilterStateVariable filter1;        //xy=294,404
AudioMixer4              mixer;         //xy=325,491
AudioEffectDelay         delay;         //xy=349,621
AudioOutputAnalogStereo  dacs;          //xy=469,582
AudioConnection          patchCord1(sine, 0, mixerfm, 0);
AudioConnection          patchCord2(noise, 0, mixer, 3);
AudioConnection          patchCord3(noise, 0, mixerfm, 3);
AudioConnection          patchCord4(triangle, 0, mixerfm, 1);
AudioConnection          patchCord5(pink, 0, mixerfm, 2);
AudioConnection          patchCord6(mixerfm, sine_fm1);
AudioConnection          patchCord7(sinefm, bitcrusher2);
AudioConnection          patchCord8(bitcrusher, 0, filter1, 0);
AudioConnection          patchCord9(filter1, 0, mixer, 0);
AudioConnection          patchCord10(filter1, 1, mixer, 1);
AudioConnection          patchCord11(filter1, 2, mixer, 2);
AudioConnection          patchCord12(mixer, delay1);
AudioConnection          patchCord13(delay, 0, dacs, 0);
AudioConnection          patchCord14(delay, 1, dacs, 1);
// GUItool: end automatically generated code
