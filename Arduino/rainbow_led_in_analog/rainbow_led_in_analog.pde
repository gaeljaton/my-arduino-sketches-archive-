int r;
int b;
int v;
int i;
void setup()
{

}

void loop()  
{ 
  i = analogRead(5);    
if (i < 256)
{
    r = i;
    v = 0;
    b = 255-i;
    analogWrite(11, r);
    analogWrite(10, v); 
    analogWrite(9, b); 
}
else if (i > 511)
{
   r = 0;
    v = 767-i;
    b = i-512;
    analogWrite(11, r);
    analogWrite(10, v); 
    analogWrite(9, b); 
}
else
{
    r = 511-i;
    v = i-256;
    b = 0;
    analogWrite(11, r);
    analogWrite(10, v); 
    analogWrite(9, b); 
}
delayMicroseconds(1000);

//if (i>766)
//{
 // i=0;
  //analogWrite(11, 0);
    //analogWrite(10, 0); 
   // analogWrite(9, 0); 
   // delay (20);
//}
 // else
//{
    //i=i+1;
//}

}


