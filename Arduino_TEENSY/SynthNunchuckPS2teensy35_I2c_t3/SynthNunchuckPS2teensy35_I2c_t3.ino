#include <Audio.h>
#include <i2c_t3.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioSynthWaveform       triangle;       //xy=88,202
AudioSynthWaveform       square;         //xy=88,265
AudioSynthNoiseWhite     noise;          //xy=88,333
AudioMixer4              mixerfm;        //xy=262,234
AudioMixer4              mixerfilter;    //xy=304,324
AudioSynthWaveformSineModulated sinefm;         //xy=383,234
AudioEffectBitcrusher    bitcrusher1;    //xy=513,234
AudioMixer4              mixerbit;       //xy=667,253
AudioFilterStateVariable filter1;        //xy=802,287
AudioMixer4              mixer;          //xy=920,294
AudioMixer4              left;           //xy=1042,254
AudioMixer4              right;          //xy=1045,334
AudioOutputPT8211        pt8211;       //xy=1209,242
AudioConnection          patchCord1(triangle, 0, mixerfm, 1);
AudioConnection          patchCord2(triangle, 0, mixerfilter, 1);
AudioConnection          patchCord3(square, 0, mixerfm, 2);
AudioConnection          patchCord4(square, 0, mixerfilter, 2);
AudioConnection          patchCord5(noise, 0, mixerfm, 3);
AudioConnection          patchCord6(noise, 0, mixerfilter, 3);
AudioConnection          patchCord7(mixerfm, sinefm);
AudioConnection          patchCord8(mixerfilter, 0, filter1, 1);
AudioConnection          patchCord9(sinefm, bitcrusher1);
AudioConnection          patchCord10(bitcrusher1, 0, mixerbit, 0);
AudioConnection          patchCord11(mixerbit, 0, filter1, 0);
AudioConnection          patchCord12(filter1, 0, mixer, 0);
AudioConnection          patchCord13(filter1, 1, mixer, 1);
AudioConnection          patchCord14(filter1, 2, mixer, 2);
AudioConnection          patchCord15(mixer, 0, left, 0);
AudioConnection          patchCord16(mixer, 0, right, 0);
AudioConnection          patchCord18(left, 0, pt8211, 0);
AudioConnection          patchCord20(right, 0, pt8211, 1);
// GUItool: end automatically generated code



#include "Nunchuk.h"
IntervalTimer NuchukTimer;
Nunchuk nc = Nunchuk();
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

#include <PS2Keyboard.h>
const int DataPin = 26;///clavier pins
const int IRQpin =  25;
byte c;
float note = 440;
float srcrush;
float LP;
float BP;
float amp;
float nunFact;
float mainFreq;
byte bitcrush = 16;
unsigned long last_time = millis();
PS2Keyboard keyboard;

void setup() {

  NVIC_SET_PRIORITY(IRQ_PORTA, 0);        ////////////////////// Interrupts Priority (PS2 debug)
  //  NVIC_SET_PRIORITY(IRQ_PORTB, 0);
  //  NVIC_SET_PRIORITY(IRQ_PORTC, 0);
  //  NVIC_SET_PRIORITY(IRQ_PORTD, 0);
  //  NVIC_SET_PRIORITY(IRQ_PORTE, 0);
  AudioMemory(200);////////////////////////////////////
  analogReadRes(13);
  delay(500);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("serialOk");

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  // Initialize the Nunchuk.
  nc.begin();
  NuchukTimer.begin(readNuchuk, 7000);// all 10ms
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
  AudioNoInterrupts();
  triangle.begin(WAVEFORM_TRIANGLE);///////
  triangle.amplitude(1);
  triangle.frequency(440);
  triangle.phase(0);
  square.begin(WAVEFORM_SQUARE);///////
  square.amplitude(1);
  square.frequency(440);
  square.phase(0);
  noise.amplitude(1);//////////////////////
  mixerfm.gain(0, 0); ///////////////////////
  mixerfm.gain(1, 0);
  mixerfm.gain(2, 0);
  mixerfm.gain(3, 0);
  sinefm.amplitude(1);//////////////////
  sinefm.frequency(110);
  sinefm.phase(0);
  mixerbit.gain(0, 0.7);
  bitcrusher1.bits(16); /////////////////
  bitcrusher1.sampleRate(44100);
  mixerfilter.gain(0, 0); //////////////////
  mixerfilter.gain(1, 0);
  mixerfilter.gain(2, 0);
  mixerfilter.gain(3, 0);
  mixer.gain(0, 0); ///////////////////////
  mixer.gain(1, 0);
  mixer.gain(2, 0);
  mixer.gain(3, 0);
  left.gain(0, 0.7);
  left.gain(1, 0);
  left.gain(2, 0);
  left.gain(3, 0);
  right.gain(0, 0.7);
  right.gain(1, 0);
  right.gain(2, 0);
  right.gain(3, 0);
  filter1.frequency(22000);
  filter1.resonance(1.2); //0.7 to 5.0
  filter1.octaveControl(7); // 0 to 7
  AudioInterrupts();
  AudioProcessorUsageMaxReset();
  AudioMemoryUsageMaxReset();
  delay(50);

  mixer.gain(0, 1);
  delay(50);
  sinefm.frequency(110);
  delay(250);
  sinefm.frequency(220);
  delay(250);
  sinefm.frequency(440);
  delay(250);
  sinefm.frequency(880);
  delay(250);
  sinefm.frequency(1760);
  delay(250);
  sinefm.frequency(10);
  delay(250);

}
/// -------Nunchuk Timer Function all 10ms---
void readNuchuk() {
  nc.read();
  if ( nc.isOk() )
  { NcAccel = nc.getAccel();
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

///------------------ Main LOOP ---------------- Main LOOP ------------------- Main LOOP ---------------- Main LOOP -------------------------- Main LOOP --------
void loop() {


  // if (millis() - last_time >= 5000) {
  //    Serial.print("Proc = ");
  //    Serial.print(AudioProcessorUsage());
  //    Serial.print(" (");
  //    Serial.print(AudioProcessorUsageMax());
  //    Serial.print("),  Mem = ");
  //    Serial.print(AudioMemoryUsage());
  //    Serial.print(" (");
  //    Serial.print(AudioMemoryUsageMax());
  //    Serial.println(")");
  //    AudioMemoryUsageMaxReset();
  //    last_time = millis();
  //  }
  //serial_print_all_nunchuk_inputs();  //--------DEBUG---------
  //serial_print_pots();
  if (keyboard.available()) {
    keyboardmap();
  }

  AudioNoInterrupts();
  srcrush =  sq(8191 - (float)analogRead(A4)) / 1550 + analogRead(A14); /////////SAMPLERATEBITCRUSH
  bitcrusher1.sampleRate(srcrush); //Serial.print(srcrush); Serial.print( "\t" );Serial.println(bitcrush);
  mixerfm.gain(3, (float)analogRead(A12) / 8192); //noiseFM
  mixerfm.gain(1, (float)analogRead(A7) / 8192); //triFM
  mixerfm.gain(2, (float)analogRead(A3) / 8192); //sqFM
  triangle.frequency((float)sq(analogRead(A6)) / 3500);
  square.frequency((float)sq(analogRead(A2)) / 3500);

  if (NcBtnZ == 0) {
    int y = NcJoyY + NcJoyY_offset ;
    runningAverageY(y);
    if ( y > 2) {
      float amp = sq((float)y-3) / 12100 ;
      mixerbit.gain(0, amp);
      Serial.println((float)amp);
    } else {
      mixerbit.gain(0, 0);
    }
  }
  else {
    mixerbit.gain(0,0.7);
  }


  nunFact = sq((float)NcAccelX+511) / 262144 ;
  sinefm.frequency(note * nunFact);//  Serial.print(mainFreq); Serial.print( "\t" );Serial.println(nunFact);

  int ffilter = sq(analogRead(A10)) / 3000;
  float res = (float)analogRead(A11) / 1700 + 1.05; //Serial.print(ffilter); Serial.print( "\t" ); Serial.println (res);
  filter1.frequency(ffilter);
  filter1.resonance(res);
  float LP = cos(analogRead(A25) * 3.14159265359 / 16384); LP = constrain(LP, 0, 1);
  float BP = sin(analogRead(A25) * 3.14159265359 / 16384); BP = constrain(BP, 0, 1);
  mixer.gain(0, LP);
  mixer.gain(1, BP);
  mixerfilter.gain(3, (float)analogRead(A13) / 8192);
  mixerfilter.gain(1, (float)analogRead(A5) / 8192);

  float leftlvl = sin(((float)NcJoyX + (float)NcJoyX_offset + 100) * 3.14159265359 / 400); leftlvl = constrain(leftlvl, 0, 1);
  float rightlvl = cos(((float)NcJoyX + (float)NcJoyX_offset + 100) * 3.14159265359 / 400); rightlvl = constrain(rightlvl, 0, 1);
  //Serial.print( rightlvl ); Serial.print( "\t" ); Serial.println(leftlvl);
  left.gain(0, leftlvl);
  right.gain(0, rightlvl);
  mixerfilter.gain(3, (float)analogRead(A13) / 8192);
  //Serial.println((float)analogRead(A13)/8192);
  AudioInterrupts();
  delay(2);

}

///------------------  END Main LOOP ---------------- END Main LOOP ------------------- END Main LOOP ---------------- END Main LOOP -------------------------- END Main LOOP --------
void keyboardmap() {
  // read the next key
  c = keyboard.read();
  Serial.println(c);
  switch (c) {
    case 122: bitcrusher1.bits(16); bitcrush = 16; break; //w
    case 120: bitcrusher1.bits(12); bitcrush = 12; break; //x
    case 99:  bitcrusher1.bits(8); bitcrush = 8; break; //c
    case 118: bitcrusher1.bits(7); bitcrush = 7; break; //v
    case 98:  bitcrusher1.bits(6); bitcrush = 6; break; //b
    case 110: bitcrusher1.bits(5); bitcrush = 5; break; //n
    case 109: bitcrusher1.bits(4); bitcrush = 4; break; //,
    case 44:  bitcrusher1.bits(3); bitcrush = 3; break; //;
    case 46:  bitcrusher1.bits(2); bitcrush = 2; break; //:
    case 47:  bitcrusher1.bits(1); bitcrush = 1; break; //!

    case 96: note = 55; break;// ²_la0
    case 49: note = 110; break;// 1_la1
    case 50: note = 220; break;// 2_la2
    case 51: note = 440; break;// 3_la3
    case 52: note = 880; break;// 4_la4
    case 53: note = 1760; break;// 5_la5
    case 54: note = 3520; break;// 6_la6
    case 55: note = 7040; break;// 7_la7
    case 56: note = 14080; break;// 8_la8
    case 57: note = 28160; break;// 9_la9

    case 113: note = 137.5; break;// a_la1tierce
    case 119: note = 275; break;// z_la2tierce
    case 101: note = 550; break;// e_la3tierce
    case 114: note = 1100; break;// r_la4tierce
    case 116: note = 2200; break;// t_la5tierce
    case 121: note = 4400; break;// y_la6tierce
    case 117: note = 8800; break;// u_la7tierce
    case 105: note = 17600; break;// i_la8tierce
    case 111:            break;// o_la9tierce

    case 97: note = 165; break;// q_la1quinte
    case 115: note = 330; break;// s_la2quinte
    case 100: note = 660; break;// d_la3quinte
    case 102: note = 1320; break;// f_la4quinte
    case 103: note = 2640; break;// g_la5quinte
    case 104: note = 5280; break;// h_la6quinte
    case 106: note = 10560; break;// j_la7quinte
    case 107: note = 21120; break;// k_la6quinte
    case 108:              break;// l_la7quinte
    
    
    default:
      note = c * c / 4;
      break;
  }



}
//------------ DEBUG Nunchuck ---------
void serial_print_all_nunchuk_inputs() {
  Serial.print( NcBtnZ, DEC );
  Serial.print( "\t" );
  Serial.print( NcBtnC, DEC );
  Serial.print( "\t" );
  Serial.print( NcJoyX + NcJoyX_offset, DEC );
  Serial.print( "\t" );
  Serial.print( NcJoyY + NcJoyY_offset, DEC );
  Serial.print( "\t" );
  Serial.print( NcAccelX, DEC );
  Serial.print( "\t" );
  Serial.print(NcAccelY, DEC );
  Serial.print( "\t" );
//  Serial.print( NcTiltX, DEC );
//  Serial.print( "\t" );
//  Serial.print( NcTiltY, DEC );
//  Serial.print( "\t" );
  //  Serial.print( NcTiltZ, DEC );
  Serial.print( "\n" );
}
void serial_print_pots() {

  Serial.print( "A10 :" ); Serial.print( analogRead(A10) ); Serial.print( "_____" );
  Serial.print( "A11 :" ); Serial.print( analogRead(A11) ); Serial.print( "_____" );
  Serial.print( "A25 :" ); Serial.print( analogRead(A25) ); Serial.print( "_____" );
  Serial.print( "A13 :" ); Serial.print( analogRead(A13) ); Serial.print( "_____" );
  Serial.print( "A12 :" ); Serial.print( analogRead(A12) ); Serial.print( "_____" );
  Serial.print( "A2 :" ); Serial.print( analogRead(A2) ); Serial.print( "\t" );
  Serial.print( "A3 :" ); Serial.print( analogRead(A3) ); Serial.print( "\t" );
  Serial.print( "A6 :" ); Serial.print( analogRead(A6) ); Serial.print( "\t" );
  Serial.print( "A7 :" ); Serial.print( analogRead(A7) ); Serial.print( "\t" );
  Serial.print( "A8 :" ); Serial.print( analogRead(A8) ); Serial.print( "\t" );
  Serial.print( "A9 :" ); Serial.print( analogRead(A9) ); Serial.print( "\t" );
  Serial.print( "\n" );
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


