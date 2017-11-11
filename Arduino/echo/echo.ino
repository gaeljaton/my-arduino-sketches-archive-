const int trig = 9;
const int echo = 10;
long time, dist;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite (8, HIGH);
  digitalWrite (11, LOW);
  digitalWrite (12, LOW);
  delay (20);
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  dist = (time / 2) / 2.91;

  if (dist > 50000 or dist == 0) Serial.println("Out of Range");
  else {
    Serial.print(dist);
    Serial.println(" mm");
  }

  delay(10);
}
