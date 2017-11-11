void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  for (int i = 0; i<7; i++)
  {
analogWrite(9, 255);
analogWrite(10, 255);
analogWrite(11, 255);
delay (50);
analogWrite(9, 0);
analogWrite(10, 0);
analogWrite(11, 0);
delay (100);
}

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(3, HIGH);
  delay(5);
 digitalWrite(3, LOW);
  delay(50);
}
