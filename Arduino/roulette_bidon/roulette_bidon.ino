int i;
int r;
int v;
int b;
int t;
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
    
t = analogRead(0);
delay(t);
t = analogRead(1);
delayMicroseconds(t);

    digitalWrite(9, LOW); 
    digitalWrite(10, HIGH); 
 
t = analogRead(0);
delay(t);
t = analogRead(1);
delayMicroseconds(t);

    digitalWrite(10, LOW); 
    digitalWrite(11, HIGH);
   

t = analogRead(0);
delay(t);
t = analogRead(1);
delayMicroseconds(t);

}


