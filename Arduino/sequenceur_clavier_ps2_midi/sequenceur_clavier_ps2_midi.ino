//  keyboard.begin(data_pin, irq_pin);
//  Valid irq pins:
//     Arduino:      2, 3
//     Arduino Mega: 2, 3, 18, 19, 20, 21  
#include <PS2Keyboard.h>

const int DataPin = 3;
const int IRQpin =  2;

PS2Keyboard keyboard;


void setup() {
  
pinMode(13, OUTPUT);  
pinMode(12, OUTPUT); 
pinMode(11, OUTPUT); 
pinMode(10, OUTPUT);  
pinMode(9, OUTPUT); 
pinMode(8, OUTPUT); 
keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
}

void loop() {
  
  if (keyboard.available())      ////////////////////////////////mapage clavier
  {
   byte c=keyboard.read();
   Serial.println("in");
     Serial.println(c);}
//   
//   if(c==122) /////////////////// A1
//   {if(bitRead(A, 0)==1){bitWrite(A,0,0);} else{bitWrite(A,0,1);}}
//   
//    if(c==120) /////////////////// A2
//   {if(bitRead(A, 1)==1){bitWrite(A,1,0);} else{bitWrite(A,1,1);}}
//   
//   if(c==99) /////////////////// A3
//   {if(bitRead(A, 2)==1){bitWrite(A,2,0);} else{bitWrite(A,2,1);}}
//   
//   if(c==118) /////////////////// A4
//   {if(bitRead(A, 3)==1){bitWrite(A,3,0);} else{bitWrite(A,3,1);}}
//   
//   if(c==98) /////////////////// A5
//   {if(bitRead(A, 4)==1){bitWrite(A,4,0);} else{bitWrite(A,4,1);}}
//   
//   if(c==110) /////////////////// A6
//   {if(bitRead(A, 5)==1){bitWrite(A,5,0);} else{bitWrite(A,5,1);}}
//   
//   if(c==109) /////////////////// A7
//   {if(bitRead(A, 6)==1){bitWrite(A,6,0);} else{bitWrite(A,6,1);}}
//   
//   if(c==44) /////////////////// A8
//   {if(bitRead(A, 7)==1){bitWrite(A,7,0);} else{bitWrite(A,7,1);}}  
//   /////////////
//   
//    if(c==115) /////////////////// B1
//   {if(bitRead(B, 0)==1){bitWrite(B,0,0);} else{bitWrite(B,0,1);}}
//   
//    if(c==100) /////////////////// B2
//   {if(bitRead(B, 1)==1){bitWrite(B,1,0);} else{bitWrite(B,1,1);}}
//   
//   if(c==102) /////////////////// B3
//   {if(bitRead(B, 2)==1){bitWrite(B,2,0);} else{bitWrite(B,2,1);}}
//   
//   if(c==103) /////////////////// B4
//   {if(bitRead(B, 3)==1){bitWrite(B,3,0);} else{bitWrite(B,3,1);}}
//   
//   if(c==104) /////////////////// B5
//   {if(bitRead(B, 4)==1){bitWrite(B,4,0);} else{bitWrite(B,4,1);}}
//   
//   if(c==106) /////////////////// B6
//   {if(bitRead(B, 5)==1){bitWrite(B,5,0);} else{bitWrite(B,5,1);}}
//   
//   if(c==107) /////////////////// B7
//   {if(bitRead(B, 6)==1){bitWrite(B,6,0);} else{bitWrite(B,6,1);}}
//   
//   if(c==108) /////////////////// B8
//   {if(bitRead(B, 7)==1){bitWrite(B,7,0);} else{bitWrite(B,7,1);}}  
//   /////////////
//   
//    if(c==101) /////////////////// C1
//   {if(bitRead(C, 0)==1){bitWrite(C,0,0);} else{bitWrite(C,0,1);}}
//   
//    if(c==114) /////////////////// C2
//   {if(bitRead(C, 1)==1){bitWrite(C,1,0);} else{bitWrite(C,1,1);}}
//   
//   if(c==116) /////////////////// C3
//   {if(bitRead(C, 2)==1){bitWrite(C,2,0);} else{bitWrite(C,2,1);}}
//   
//   if(c==121) /////////////////// C4
//   {if(bitRead(C, 3)==1){bitWrite(C,3,0);} else{bitWrite(C,3,1);}}
//   
//   if(c==117) /////////////////// C5
//   {if(bitRead(C, 4)==1){bitWrite(C,4,0);} else{bitWrite(C,4,1);}}
//   
//   if(c==105) /////////////////// C6
//   {if(bitRead(C, 5)==1){bitWrite(C,5,0);} else{bitWrite(C,5,1);}}
//   
//   if(c==111) /////////////////// C7
//   {if(bitRead(C, 6)==1){bitWrite(C,6,0);} else{bitWrite(C,6,1);}}
//   
//   if(c==112) /////////////////// C8
//   {if(bitRead(C, 7)==1){bitWrite(C,7,0);} else{bitWrite(C,7,1);}}  
//   /////////////
//   
//    if(c==52) /////////////////// D1 ***********************************problÃ¨me!!! comflit de touche avec selection de la coupure ==> mise en manuel/preset
//   {if(bitRead(D, 0)==1){bitWrite(D,0,0);} else{bitWrite(D,0,1);}}
//   
//    if(c==53) /////////////////// D2
//   {if(bitRead(D, 1)==1){bitWrite(D,1,0);} else{bitWrite(D,1,1);}}
//   
//   if(c==54) /////////////////// D3
//   {if(bitRead(D, 2)==1){bitWrite(D,2,0);} else{bitWrite(D,2,1);}}
//   
//   if(c==55) /////////////////// D4
//   {if(bitRead(D, 3)==1){bitWrite(D,3,0);} else{bitWrite(D,3,1);}}
//   
//   if(c==56) /////////////////// D5
//   {if(bitRead(D, 4)==1){bitWrite(D,4,0);} else{bitWrite(D,4,1);}}
//   
//   if(c==57) /////////////////// D6
//   {if(bitRead(D, 5)==1){bitWrite(D,5,0);} else{bitWrite(D,5,1);}}
//   
//   if(c==48) /////////////////// D7
//   {if(bitRead(D, 6)==1){bitWrite(D,6,0);} else{bitWrite(D,6,1);}}
//   
//   if(c==45) /////////////////// D8
//   {if(bitRead(D, 7)==1){bitWrite(D,7,0);} else{bitWrite(D,7,1);}}  
//   /////////////
   
   //Effacement de la piste
//    if(c==1) /////////////////// F1 efface A
//   {A=0;}
//    if(c==2) /////////////////// F2 efface B
//   {B=0;}
//   if(c==3) /////////////////// F3 efface C
//   {C=0;}
//   if(c==4) /////////////////// F4 efface D
//   {D=0;} 
//   
//   //Preset 4 : 1/2step
//     if(c==5) /////////////////// F5 4 A
//   {A=85;}
//    if(c==6) /////////////////// F6 4 B
//   {B=85;}
//   if(c==7) /////////////////// F7 4 C
//   {C=85;}
//   if(c==8) /////////////////// F8 4 D
//   {D=85;} 
//   
//   //Preset 8 : full step
//     if(c==9) /////////////////// F9 8 A
//   {A=255;}
//    if(c==10) /////////////////// F10 8 B
//   {B=255;}
//   if(c==11) /////////////////// F11 8 C
//   {C=255;}
//   if(c==12) /////////////////// F12 8 D
//   {D=255;} 
//   
//     if(c==50) /////////////////// A++
//   {if(sa<4){sa++;}}
//    if(c==51) /////////////////// A--
//   {if(sa>1){sa--;}}
//   
//   if(c==53) /////////////////// B++
//  {if(sb<4){sb++;}}
//   if(c==54) /////////////////// B--
//   {if(sb>1){sb--;}}
//   
//     if(c==56) /////////////////// C++
//  {if(sc<4){sc++;}}
//    if(c==57) /////////////////// C--
//   {if(sc>1){sc--;}}
//   
//   if(c==47) /////////////////// D++
//   {if(sd<4){sd++;}}
//   if(c==42) /////////////////// D--
//   {if(sd>1){sd--;}}
//   
//  }
  
  }


