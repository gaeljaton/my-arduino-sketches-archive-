int delo = 5;
int deli = 5;
int frame = 0;
int a;
int data[] = {
127	,
64	,
95	,
81	,
93	,
69	,
125	,
1	,
127	,
64	,
127	,
1	,
127	,
64	,
92	,
87	,
81	,
119	,
4	,
124	,
64	,
127	,
1	,
125	,
69	,
119	,
16	,
119	,
69	,
125	,
1	,
119	,
84	,
87	,
81	,
95	,
64	,
127	,
1	,
31	,
16	,
119	,
69	,
125	,
1	,
127	,
64	,
127	,
1	,
125	,
71	,
112	,
31	,
1	,
125	,
69	,
117	,
21	,
119	,
64	,
127	,
1	,
125	,
69	,
93	,
81	,
95	,
64	,
127	,
1	,
125	,
69	,
117	,
21	,
117	,
69	,
119	,
16	,
31	,
1	,
127	,
64	,
95	,
81	,
87	,
84	,
87	,
81	,
119	,
4	,
124	,
64	,
127	,
1	,
127	,
64	,
95	,
81	,
87	,
84	,
87	,
113	,
1	,

};

void setup()
{
  pinMode(1, OUTPUT);   
 pinMode(2, OUTPUT);    
 pinMode(3, OUTPUT);    
 pinMode(4, OUTPUT);    
 pinMode(5, OUTPUT);    
 pinMode(6, OUTPUT);    
 pinMode(7, OUTPUT);     // met la broche numérique en sortie 
 //Serial.begin(9600); // initialisation de la connexion série à 9600 bauds
}

void loop()
{  for (a = 0; a < 7; a++)
	
        {
        if (bitRead(data[frame], a)==1) {digitalWrite(a+1, HIGH);} else {digitalWrite(a+1, LOW);}
        }

    delay(deli);
    digitalWrite(1, LOW);   digitalWrite(2, LOW);   digitalWrite(3, LOW);   digitalWrite(4, LOW);   digitalWrite(5, LOW);   digitalWrite(6, LOW);   digitalWrite(7, LOW);  
  delay(delo);   
if(frame >= (sizeof(data)/2-1)){frame = 0;} else {frame = frame+1;};
 Serial.print(frame);
}
