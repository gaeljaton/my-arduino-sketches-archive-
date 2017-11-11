#include <Audio.h>
#include <i2c_t3.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>



// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=55,139
AudioPlaySdRaw           playRaw1;       //xy=61,194
AudioAnalyzePeak         peak1;          //xy=187,20
AudioRecordQueue         queue1;         //xy=208,79
AudioMixer4              mixer;         //xy=349,126
AudioOutputI2S           i2s1;           //xy=524,179
AudioConnection          patchCord1(i2s2, 0, queue1, 0);
AudioConnection          patchCord2(i2s2, 0, peak1, 0);
AudioConnection          patchCord3(i2s2, 1, mixer, 0);
AudioConnection          patchCord4(playRaw1, 0, mixer, 1);
AudioConnection          patchCord5(mixer, 0, i2s1, 0);
AudioConnection          patchCord6(mixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=304,210
// GUItool: end automatically generated code

// GUItool: end automatically generated code

//const int myInput = AUDIO_INPUT_LINEIN;
const int myInput = AUDIO_INPUT_MIC;

// Bounce objects to easily and reliably read the buttons
Bounce buttonRecord = Bounce(16, 20);
//Bounce buttonStop =   Bounce(1, 20);  // 20 = 20 ms debounce time
//Bounce buttonPlay =   Bounce(2, 20);

// Remember which mode we're doing
int mode = 0;  // 0=stopped, 1=recording, 2=playing
int stutterMode = 0; // 0=stopped, 1=recording, 2=playing
// The file where data is recorded
File frec;
int midiStep = 1;
unsigned long  timestart = 0 ;

void setup() {
  // Configure the pushbutton pins
  pinMode(16, INPUT_PULLUP);
  analogReadRes(13);

  Serial1.begin(31250);
  // Audio connections require memory, and the record queue
  // uses this memory to buffer incoming audio.
  AudioMemory(60);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(1);

  // Initialize the SD card
  SPI.setMOSI(7);
  SPI.setSCK(14);
  if (!(SD.begin(10))) {
    // stop here if no SD card, but print a message
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example


  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(1);
  mixer.gain(0, 1);
  mixer.gain(1, 1);
  sgtl5000_1.micGain(20);

}

//elapsedMillis volmsec = 0;

void startRecording() {
  Serial.println("startRecording");
  if (SD.exists("RECORD.RAW")) {
    // The SD library writes new data to the end of the
    // file, so to start a new recording, the old file
    // must be deleted before new data is written.
    SD.remove("RECORD.RAW");
  }
  frec = SD.open("RECORD.RAW", FILE_WRITE);
  if (frec) {
    queue1.begin();
    mode = 1;
  }
}

void continueRecording() {
  if (queue1.available() >= 2) {
    byte buffer[512];
    // Fetch 2 blocks from the audio library and copy
    // into a 512 byte buffer.  The Arduino SD library
    // is most efficient when full 512 byte sector size
    // writes are used.
    memcpy(buffer, queue1.readBuffer(), 256);
    queue1.freeBuffer();
    memcpy(buffer + 256, queue1.readBuffer(), 256);
    queue1.freeBuffer();
    // write all 512 bytes to the SD card
    elapsedMicros usec = 0;
    frec.write(buffer, 512);
    // Uncomment these lines to see how long SD writes
    // are taking.  A pair of audio blocks arrives every
    // 5802 microseconds, so hopefully most of the writes
    // take well under 5802 us.  Some will take more, as
    // the SD library also must write to the FAT tables
    // and the SD card controller manages media erase and
    // wear leveling.  The queue1 object can buffer
    // approximately 301700 us of audio, to allow time
    // for occasional high SD card latency, as long as
    // the average write time is under 5802 us.
    //Serial.print("SD write, us=");
    //Serial.println(usec);
  }
}

void stopRecording() {
  Serial.println("stopRecording");
  queue1.end();
  if (mode == 1) {
    while (queue1.available() > 0) {
      frec.write((byte*)queue1.readBuffer(), 256);
      queue1.freeBuffer();
    }
    frec.close();
  }
  mode = 0;
}


void startPlaying() {
  //Serial.println("startPlaying");
  timestart = millis();
  playRaw1.play("RECORD.RAW");

  mode = 2;
}

void continuePlaying() {
  if (!playRaw1.isPlaying()) {
    startPlaying();
  }
}

void stopPlaying() {
  Serial.println("stopPlaying");
  if (mode == 2) playRaw1.stop();
  mode = 0;
}
void loop() {
  // First, read the buttons
  buttonRecord.update();
  //  buttonStop.update();
  //  buttonPlay.update();

  // Respond to button presses
  //  if (buttonRecord.fallingEdge()) {
  //    Serial.println("Record Button Press");
  //
  //    stopRecording();
  //    startPlaying();
  //  }
  //  if (buttonRecord.risingEdge()) { //buttonRecord.fallingEdge()
  //    Serial.println("Stop Button Press");
  //    stopPlaying();
  //  }
  if (Serial1.available() > 0) {
    byte midiIn = Serial1.read();
    Serial.println(midiIn, HEX);

    if (midiIn == 0xf8) {
      if (digitalRead(16) == LOW) {
        Serial.println("Record Button Press");
        if (stutterMode == 1) {
          midiStep = midiStep + 1;
          if (midiStep == 25) {
            midiStep = 0;
            stopRecording();
            stutterMode = 2;
          }
        }
        if (stutterMode == 0) {
          startRecording();
          midiStep = midiStep + 1;
          stutterMode = 1;
        }

        if (stutterMode == 2) {
          if (midiStep == 1) {
            startPlaying();
          }
          midiStep = midiStep + 1;
          if (midiStep == 25) {
            midiStep = 1;
          }
        }
      }
      if (digitalRead(16) == HIGH) {
        stopPlaying(); stutterMode = 0; midiStep = 1;
      }
    }
  }
  // If we're playing or recording, carry on...
  if (mode == 1) {
    continueRecording();
  }
  if (mode == 2) {
    continuePlaying();
    //      unsigned long  timeGo = 10 + timestart + sq(analogRead(A3)) / 20000;
    //      if (millis() >= timeGo) {
    //        timestart = millis();
    //        startPlaying();
  }
}

