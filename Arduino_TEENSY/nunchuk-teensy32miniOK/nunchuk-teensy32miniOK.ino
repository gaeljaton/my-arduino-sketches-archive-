#include <Wire.h>
#include "Nunchuk.h"

// Nunchuck for input
IntervalTimer NuchukTimer;
Nunchuk nc = Nunchuk();

// vars for left right beatdetection 
unsigned long XACC_LEFT_TIME = 0;
unsigned long XACC_RIGHT_TIME = 0;
unsigned int LEFTCOUNT = 0;
unsigned int RIGHTCOUNT = 0;

/*
 *  Nunchuk Data.
 *  Can not use a struct here because volatile vars.
 *  nunchuk read runns in a Timer all 10 ms.
 *  all datatyps are the same than in Nunchuk.h
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


int mouseDead = 5; // set between min of 0 and max of 10
int mylookupZeroOffset= 126 + mouseDead +1;
int mouseLookupX[300];
int mouseLookupY[300];


/// activate nuchuk emulation
bool IS_MOUSE = true;
bool IS_KEY = true;
bool IS_JOY = false;

float SLOW_MOUSE_MOVE_X = 0.0;
float SLOW_MOUSE_MOVE_Y = 0.0;


/// --------------SETUP-------------
void setup()
{  
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  // Initialize the serial port
  Serial.begin(57600);
  
  // Initialize the Nunchuk.
  nc.begin();
  NuchukTimer.begin(readNuchuk, 1000);// all 10ms

  // Calibrate Joy X and Joy Y
  elapsedMillis waiting;     // "waiting" starts at zero
  while (waiting < 2000) {
    NcJoyX_offset = runningAverageX(NcJoyX);
    NcJoyY_offset = runningAverageY(NcJoyY);
  }
  if(NcBtnZ){
    IS_MOUSE = false;
    IS_KEY = false;
    IS_JOY = true;
    }
   
  NcJoyX_offset *= -1;
  NcJoyY_offset *= -1;
  Serial.print("offset X: ");
  Serial.print(NcJoyX_offset);
  Serial.print("offset Y: ");
  Serial.println(NcJoyY_offset);

}


/// -------Nunchuk Timer Function all 10ms---
void readNuchuk(){
  
  nc.read();
  
  if( nc.isOk() ) {
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
  
serial_print_all_nunchuk_inputs();

/// Delay everything a little bit.

  delay(5);
  
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


void serial_print_all_nunchuk_inputs(){
  
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
