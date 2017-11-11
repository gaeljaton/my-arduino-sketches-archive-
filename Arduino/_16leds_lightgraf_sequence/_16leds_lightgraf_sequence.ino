int delo = 5;
int deli = 5;
int frame = 0;
int a;
int b;
int data = 1;

byte data1[ ] = {
0x00, 0x00, 0x38, 0x44, 0x42, 0x42, 0x42, 0x42, 0x82, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0,
0x00, 0x00, 0xE0, 0x40, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,
0xE0, 0x00, 0x00, 0xE0, 0x40, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x80, 0x40, 0x20, 0xA0, 0xC0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00,
0x80, 0x40, 0x20, 0x20, 0xE0, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x80, 0x40,
0x20, 0xA0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0xA0, 0xC0, 0x00, 0x00,
0xE0, 0x40, 0x20, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x40, 0x20, 0x20, 0xC0,
0x00, 0x00, 0x00, 0xE4, 0x00, 0x00, 0x60, 0x80, 0x00, 0x80, 0x60, 0x00, 0x80, 0x40, 0x20, 0xA0,
0xC0, 0x00, 0x00, 0xE0, 0x40, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0xE0,
0x00, 0x00, 0x00, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x80, 0x00, 0x80, 0x60, 0x00,
0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xFC, 0x20, 0x20, 0x00,
0xC0, 0x20, 0x20, 0x20, 0xC0, 0x00, 0x00, 0xE0, 0x40, 0x20, 0xE0, 0x40, 0x20, 0xC0, 0x00, 0x00,
0xFE, 0x40, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x80, 0x40, 0x20, 0xA0, 0xC0, 0x00, 0x00, 0xE0,
0x40, 0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x80, 0x40, 0x20,
0x20, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xFC, 0x26, 0x22, 0x02, 0x00, 0xC0,
0x20, 0x20, 0x20, 0xC0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x80, 0x40, 0x20,
0x20, 0x20, 0xFE, 0x00, 0x00, 0xE0, 0x40, 0x20, 0xE0, 0x00, 0x00, 0x80, 0x40, 0x20, 0xA0, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x03, 0x00, 0x00, 0x07, 0x08,
0x08, 0x08, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
0x08, 0x08, 0x08, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x07, 0x0B, 0x09,
0x09, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x08, 0x08, 0x08, 0x07, 0x00, 0x00, 0x00,
0x0F, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x07, 0x08, 0x00, 0x87, 0x88, 0x88, 0xC4, 0x3F, 0x00,
0x00, 0x07, 0x0B, 0x09, 0x09, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0B, 0x09, 0x09,
0x04, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00,
0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x01, 0x0E, 0x03, 0x00, 0x00, 0x07,
0x0B, 0x09, 0x09, 0x04, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00,
0x00, 0x00, 0x60, 0x80, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08,
0x08, 0x08, 0x07, 0x08, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0E,
0x03, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0x00, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x07, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00,
0x0F, 0x00, 0x00, 0x0F, 0x08, 0x08, 0x08, 0x04, 0x03, 0x00, 0x00, 0x07, 0x0B, 0x09, 0x09, 0x04,
0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
0x07, 0x08, 0x08, 0x08, 0x07, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x07, 0x00, 0x00, 0x07, 0x08, 0x08, 0x08, 0x0F, 0x00, 0x00,
0x07, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0B,
0x09, 0x09, 0x04, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};
byte data2[ ] = {136	,	8	,
184	,	59	,
32	,	34	,
238	,	238	,
138	,	136	,
186	,	187	,
34	,	162	,
238	,	238	,
};
byte data3[ ] = {114	,	156	,
230	,	206	,
206	,	231	,
156	,	115	,
56	,	57	,
114	,	156	,
230	,	206	,
204	,	231	,
156	,	115	,
56	,	57	,

};
byte data4[ ] = {254	,	255	,
0	,	128	,
254	,	191	,
2	,	160	,
250	,	175	,
10	,	168	,
234	,	171	,
42	,	170	,
170	,	171	,
170	,	168	,
170	,	175	,
42	,	160	,
234	,	191	,
10	,	128	,
250	,	255	,
2	,	0	,
};
byte data5[ ] = {127	,	254	,
1	,	128	,
125	,	190	,
69	,	162	,
93	,	186	,
81	,	138	,
95	,	250	,
64	,	2	,

};
byte data6[ ] = {170	,	170	,
224	,	224	,
68	,	68	,
14	,	14	,

};
byte data7[ ] = {0,0
};
byte data8[ ] = {253	,	127	,
69	,	64	,
85	,	95	,
85	,	65	,
81	,	125	,
95	,	65	,
65	,	95	,
125	,	81	,
1	,	85	,
255	,	85	,
17	,	84	,
213	,	87	,
69	,	68	,
125	,	125	,
1	,	65	,
255	,	95	,
17	,	64	,
213	,	127	,
85	,	64	,
85	,	95	,
85	,	80	,
213	,	87	,
21	,	80	,
245	,	95	,
5	,	65	,
125	,	125	,
65	,	65	,
95	,	95	,
65	,	64	,
253	,	127	,
65	,	68	,
95	,	85	,
81	,	85	,
85	,	85	,
69	,	85	,
125	,	85	,
1	,	85	,
255	,	85	,
17	,	84	,
149	,	87	,
21	,	80	,
245	,	95	,
69	,	68	,
93	,	117	,
81	,	69	,
87	,	93	,
81	,	65	,
93	,	127	,
81	,	68	,
215	,	85	,
17	,	81	,
125	,	95	,
65	,	64	,
223	,	127	,
81	,	64	,
85	,	95	,
85	,	81	,
69	,	85	,
125	,	84	,
193	,	87	,
95	,	80	,
65	,	95	,
125	,	65	,
65	,	125	,
95	,	65	,
81	,	95	,
85	,	80	,
213	,	87	,
69	,	80	,
125	,	95	,
1	,	81	,
255	,	85	,
17	,	85	,
69	,	68	,
};
byte data9[ ] = {255,255,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
byte data10[ ] = {
};
byte data11[ ] = {
};
byte data12[ ] = {
};
byte data13[ ] = {
};
byte data14[ ] = {
};
byte data15[ ] = {
};
byte data16[ ] = {
};
void setup()
{
  pinMode(0, INPUT); //data --
  pinMode(1, INPUT); //data ++
  pinMode(2, INPUT); // lancement séquence
  pinMode(3, INPUT); // *vide*
  pinMode(4, OUTPUT);  //led 1
  pinMode(5, OUTPUT);  //led 2 
  pinMode(6, OUTPUT);  //led 3
  pinMode(7, OUTPUT);  //led 4
  pinMode(8, OUTPUT);  //led 5
  pinMode(9, OUTPUT);  //led 6
  pinMode(10, OUTPUT); //led 7
  pinMode(11, OUTPUT); //led 8
  pinMode(12, OUTPUT); //led 9
  pinMode(13, OUTPUT); //led 10
  pinMode(14, OUTPUT); //led 11
  pinMode(15, OUTPUT); //led 12
  pinMode(16, OUTPUT); //led 13
  pinMode(17, OUTPUT); //led 14
  pinMode(18, OUTPUT); //led 15
  pinMode(19, OUTPUT); //led 16
  
//  Serial.begin(9600);
}

void loop()
{
  //selection n°data

  if (digitalRead(1)==0)
    {
      if(data==1){data=16;}
      else {data=data-1;};
      digitalWrite(data+3, HIGH); 
      delay(250);
      digitalWrite(data+3, LOW);
    };
    
  if (digitalRead(0)==0)
    {
      if(data==16){data=1;}
      else {data=data+1;};
      digitalWrite(data+3, HIGH); 
      delay(250);
      digitalWrite(data+3, LOW);
    };

  //selection data 1-16
//Serial.println(sizeof(data1)); 
 switch (data) { 
       case 1: if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data1)/2;)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data1[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + sizeof(data1)/2;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data1[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                             
                            frame = frame + 1 -sizeof(data1)/2;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
              //////////////////////////////////////////////
      case 2 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data2);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data2[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data2[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                             
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
              //////////////////////////////////////////////
      case 3 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data3);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data3[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data3[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
              ///////////////////////////////////////////////////
      case 4 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data4);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data4[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data4[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              } ;break;
              ////////////////////////////////////
      case 5 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data5);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data5[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data5[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
              /////////////////////////////////////////////
      case 6 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data6);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data6[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data6[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
              /////////////////////////////////////////////////////////
      case 7 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data7);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data7[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data7[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
      case 8 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data8);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data8[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data8[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
              /////////////////////////////////      
      case 9 : if (digitalRead(2)==1)
              {
                    frame = 0;
                    for (frame = 0; frame < sizeof(data9);)
                    {
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data9[frame], a)==1) 
                                   {digitalWrite(a+4, HIGH);};    //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            
                            for (a = 0; a < 8; a++)
                            {
                              if (bitRead(data9[frame], a)==1) 
                                  {digitalWrite(a+12, HIGH);};   //data8 à modifier
                            }
                            
                            frame = frame + 1;
                            delay(deli);
                            
                            for (b=4;b<20; b++)
                            {
                            digitalWrite(b, LOW);
                            }
                      
                      delay (delo);
                    }
              };break;
                    
      case 10: ;
      case 11: ;
      case 12: ;
      case 13: ;
      case 14: ;
      case 15: ;
      case 16: ;
  };
  
  //lecture séquence
  
//  if (digitalRead(2)==1)
//  {
//        frame = 0;
//        for (frame = 0; frame < sizeof(data8);)
//        {
//                for (a = 0; a < 8; a++)
//                {
//                  if (bitRead(data8[frame], a)==1) 
//                       {digitalWrite(a+4, HIGH);};    //data8 à modifier
//                }
//                
//                frame = frame + 1;
//                
//                for (a = 0; a < 8; a++)
//                {
//                  if (bitRead(data8[frame], a)==1) 
//                      {digitalWrite(a+12, HIGH);};   //data8 à modifier
//                }
//                
//                frame = frame + 1;
//                delay(deli);
//                
//                for (b=4;b<20; b++)
//                {
//                digitalWrite(b, LOW);
//                }
//          
//          delay (delo);
//        }
//    
//  }

}


