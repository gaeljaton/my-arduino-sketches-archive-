#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>
#include "Nunchuk.h"


// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=433,337
AudioSynthWaveform       waveform1;      //xy=439,417
AudioMixer4              mixer1;         //xy=629,401
AudioEffectFade          fade1;          //xy=725,481
AudioOutputI2S           i2s1;           //xy=842,431
AudioOutputAnalog        dac1;           //xy=846,384
AudioConnection          patchCord1(sine1, 0, mixer1, 0);
AudioConnection          patchCord2(waveform1, 0, mixer1, 1);
AudioConnection          patchCord3(mixer1, fade1);
AudioConnection          patchCord4(fade1, dac1);
AudioConnection          patchCord5(fade1, 0, i2s1, 1);
AudioConnection          patchCord6(fade1, 0, i2s1, 0);
// GUItool: end automatically generated code


// Create an object to control the audio shield.
//
AudioControlSGTL5000 audioShield;

// Nunchuck for input
IntervalTimer NuchukTimer;
Nunchuk nc = Nunchuk();

// vars for left right beatdetection
unsigned long XACC_LEFT_TIME = 0;
unsigned long XACC_RIGHT_TIME = 0;
unsigned int LEFTCOUNT = 0;
unsigned int RIGHTCOUNT = 0;

/*
    Nunchuk Data.
    Can not use a struct here because volatile vars.
    nunchuk read runns in a Timer all 10 ms.
    all datatyps are the same than in Nunchuk.h
*/

volatile float NcAccel;
volatile int NcAccelX;
volatile int NcAccelY;
volatile int NcAccelZ;
volatile bool NcBtnZ;
volatile bool NcBtnC;
volatile int NcJoyX;
volatile int NcJoyY;
volatile float NcTiltX;
volatile float NcTiltY;
volatile float NcTiltZ;

int NcJoyX_offset = 0; // offset for joystick x achsis
int NcJoyY_offset = 0; // offset for joystick yS achsis


byte env=0;
 unsigned long last_time = millis();

/// --------------SETUP-------------
void setup()
{
  AudioMemory(10);
  // turn on the output
  audioShield.enable();
  audioShield.volume(0.7);
  // by default the Teensy 3.1 DAC uses 3.3Vp-p output
  // if your 3.3V power has noise, switching to the
  // internal 1.2V reference can give you a clean signal
 // dac1.analogReference(INTERNAL);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);


  // Initialize the serial port
  Serial.begin(9600);

  // Initialize the Nunchuk.
  nc.begin();
  NuchukTimer.begin(readNuchuk, 10000);// all 10ms

  // Calibrate Joy X and Joy Y
  elapsedMillis waiting;     // "waiting" starts at zero
  while (waiting < 2000) {
    NcJoyX_offset = runningAverageX(NcJoyX);
    NcJoyY_offset = runningAverageY(NcJoyY);
  }

  NcJoyX_offset *= -1;
  NcJoyY_offset *= -1;
  Serial.print("offset X: ");
  Serial.print(NcJoyX_offset);
  Serial.print("offset Y: ");
  Serial.println(NcJoyY_offset);
  
  waveform1.begin(0, 500, WAVEFORM_SQUARE);
  mixer1.gain(0, 0.7); //sine
  mixer1.gain(1, 0); //carré
  mixer1.gain(2, 0); //void
  
  sine1.amplitude(0.7);
  delay(50);
  sine1.frequency(220);
  delay(100);
  sine1.frequency(440);
  delay(100);
  sine1.frequency(880);
  delay(100);
  sine1.frequency(1760);
  delay(100);
  sine1.frequency(3520);
  
  //fade1.fadeOut(200);
  delay(200);
   AudioProcessorUsageMaxReset();
  AudioMemoryUsageMaxReset();
 
}


/// -------Nunchuk Timer Function all 10ms---
void readNuchuk() {

  nc.read();

  if ( nc.isOk() ) {
    NcAccel = nc.getAccel();
    NcAccelX = nc.getAccelX();
    NcAccelY = nc.getAccelY();
    NcAccelZ = nc.getAccelZ();
    NcBtnZ = nc.getButtonZ();
    NcBtnC = nc.getButtonC();
    NcJoyX = nc.getJoyX();
    NcJoyY = nc.getJoyY();
    NcTiltX = nc.getTiltX();
    NcTiltY = nc.getTiltY();
    NcTiltZ = nc.getTiltZ();
  }
}


/// ----------Main Loop------------
void loop()
{
  
//if(env==0){if(NcBtnZ==1){env=1; fade1.fadeIn(100);}}
//if(env==1){if(NcBtnZ==0){env=0; fade1.fadeOut(100);}}

  //serial_print_all_nunchuk_inputs();
  float YY = runningAverageY(NcJoyY);
  float NAX = runningAverageX(NcAccelX);
  //float YY = NcJoyY;
  /// Delay everything a little bit.
  float Ax = NAX + 300;
  float f1 = Ax * Ax / 200;
  sine1.frequency(f1);
  float amp = (float)(pow(YY, 2) - 10) / 15000;
  //float amp=(float)(pow(analogRead(A6),2)-10)/15000;
  sine1.amplitude(amp);/////////////////////////
  
 

 delay(5);
 
if(millis() - last_time >= 5000) {
    Serial.print("Proc = ");
    Serial.print(AudioProcessorUsage());
    Serial.print(" (");    
    Serial.print(AudioProcessorUsageMax());
    Serial.print("),  Mem = ");
    Serial.print(AudioMemoryUsage());
    Serial.print(" (");    
    Serial.print(AudioMemoryUsageMax());
    Serial.println(")");
    last_time = millis();
  }
}

// -----------Functions----------

/// simple Average filter
long runningAverageX(int M) {
#define LM_SIZE 20
  static int LM[LM_SIZE];      // LastMeasurements
  static byte index = 0;
  static long sum = 0;
  static byte count = 0;

  // keep sum updated to improve speed.
  sum -= LM[index];
  LM[index] = M;
  sum += LM[index];
  index++;
  index = index % LM_SIZE;
  if (count < LM_SIZE) count++;

  return sum / count;
}

long runningAverageY(int M) {
#define LM_SIZE 20
  static int LM[LM_SIZE];      // LastMeasurements
  static byte index = 0;
  static long sum = 0;
  static byte count = 0;

  // keep sum updated to improve speed.
  sum -= LM[index];
  LM[index] = M;
  sum += LM[index];
  index++;
  index = index % LM_SIZE;
  if (count < LM_SIZE) count++;
  return sum / count;
}


void serial_print_all_nunchuk_inputs() {

  //  Serial.print( NcAccel, DEC );
  //  Serial.print( "\t" );
  Serial.print( NcAccelX, DEC );
  Serial.print( "\t" );
  Serial.print( NcAccelY, DEC );
  Serial.print( "\t" );
  //  Serial.print( NcAccelZ, DEC );
  //  Serial.print( "\t" );

  Serial.print( NcBtnZ, DEC );
  Serial.print( "\t" );
  Serial.print( NcBtnC, DEC );
  Serial.print( "\t" );
  Serial.print( NcJoyX + NcJoyX_offset, DEC );
  Serial.print( "\t" );
  Serial.print( NcJoyY + NcJoyY_offset, DEC );
  Serial.print( "\t" );

  //  Serial.print( NcTiltX, DEC );
  //  Serial.print( "\t" );
  //  Serial.print( NcTiltY, DEC );
  //  Serial.print( "\t" );
  //  Serial.print( NcTiltZ, DEC );
  Serial.print( "\n" );
}
