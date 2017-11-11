int i;
int r;
int v;
int b;
int s;
long t;


int rdm=80;
void setup()
{
pinMode(9, OUTPUT); 
pinMode(10, OUTPUT); 
pinMode(11, OUTPUT); 
}

void loop()  
{ 

    digitalWrite(11, LOW);
    digitalWrite(9, HIGH); 
    
s = analogRead(0);
delay(s);
t = analogRead(1);
delayMicroseconds(10*t+8);
r = random(0 , analogRead(2));
delay(r);


    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH); 
 
s = analogRead(0);
delay(s);
t = analogRead(1);
delayMicroseconds(10*t+8);
r = random(0 , analogRead(2));
delay(r);

    digitalWrite(10, LOW); 
    digitalWrite(11, HIGH);
   
s = analogRead(0);
delay(s);
t = analogRead(1);
delayMicroseconds(10*t+8);
r = random(0 , analogRead(2));
delay(r);

}

