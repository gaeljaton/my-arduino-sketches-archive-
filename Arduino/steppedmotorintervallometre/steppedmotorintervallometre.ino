#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
// Map our pins to constants to make things easier to keep track of
#include <Stepper.h>
const int pwmA = 3;
const int pwmB = 11;
const int brakeA = 9;
const int brakeB = 8;
const int dirA = 12;
const int dirB = 13;
int state= 0;
int steps = 30; //nb de pas par rotation********************************
long interval = 2000; //interval de temps****************************
long previousMillis = 0;  

// Initialize the Stepper class
Stepper myStepper(48, dirA, dirB);

void setup() {
 lcd.begin(16, 2); 
 lcd.setBacklight(0x1);
 
  pinMode(14, OUTPUT); /// déclancheur photo
  /// 0v ""
  
  
  // Set the RPM of the motor
  myStepper.setSpeed(200);

  // Turn OFF pulse width modulation
  pinMode(pwmA, OUTPUT);
  digitalWrite(pwmA, LOW);
  pinMode(pwmB, OUTPUT);
  digitalWrite(pwmB, LOW);

  // Turn off the brakes
  pinMode(brakeA, OUTPUT);
  digitalWrite(brakeA, LOW);
  pinMode(brakeB, OUTPUT);
  digitalWrite(brakeB, LOW);
  
  lcd.setCursor(5, 0);
  lcd.print("Hello,");
   delay(500);
   lcd.setCursor(0, 1);
  lcd.print("press any key...");

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {
  
uint8_t buttons = lcd.readButtons();
  if (buttons) {
  
    
    if (buttons & BUTTON_UP) {
      interval=interval+50;
    }
    if (buttons & BUTTON_DOWN) {
     if(interval >500){interval=interval-50;}
    }
    if (buttons & BUTTON_LEFT) {
       steps=steps-1;
    }
    if (buttons & BUTTON_RIGHT) {
      steps=steps+1;
    }
    if (buttons & BUTTON_SELECT) {
   if(state==0){state=1;} else{state=0;}
    }
      
    lcd.clear();delay(20);
    lcd.setCursor(0, 0);
    lcd.print("T(ms): ");lcd.print(interval);
    lcd.setCursor(0, 1);
    lcd.print("NBpas: ");lcd.print(steps);lcd.print("/8100");
    lcd.setCursor(12, 0);
    if(state==0){lcd.print("Stop");} else{lcd.print("GO");}
    }
    
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) 
  {previousMillis = currentMillis;  
  if(state==1){
  //declancheur
  digitalWrite(14, HIGH);
  delay(50);
  digitalWrite(14, LOW);
  delay(800);
  
  //rotation
  digitalWrite(pwmB, HIGH);
  digitalWrite(pwmA, HIGH);
  delay(20);
  myStepper.step(steps);
  delay(20);
  digitalWrite(pwmB, LOW);
  digitalWrite(pwmA, LOW);
  
  }
}
  
}
