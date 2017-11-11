 #include <i2c_t3.h>

int accel_x_axis ;
int accel_y_axis ;
int accel_z_axis ;

byte buffer[6]; // Buffer contenant les 6 précieux octets qui nous intéresse
byte cnt = 0; // index courant de buffer 

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission (0x52); // Séquence d'initialisation
  Wire.write (0x40);
  Wire.write (0x00);
  Wire.endTransmission ();
  delay(30);
}

void handshake() // Handshack, merci captain obvious !
{
  Wire.beginTransmission (0x52);
  Wire.write (0x00);
  Wire.endTransmission ();
  delay(10);
}



void parse()
{
  byte joy_x_axis = buffer[0]; // joystick axe x (0-255)
  byte joy_y_axis = buffer[1]; // joystick axe y (0-255)
  int accel_x_axis = buffer[2] ; // accéléromètre axe x
  int accel_y_axis = buffer[3] ; // accéléromètre axe y
  int accel_z_axis = buffer[4] ; // accéléromètre axe z

  byte z_button = 1; // bouton Z
  byte c_button = 1; // bouton c


  if ((buffer[5] >> 0) & 1)
    z_button = 0;

  if ((buffer[5] >> 1) & 1)
    c_button = 0;
  if (z_button == 1)
    c_button = !c_button;


  if ((buffer[5] >> 2) & 1)
    accel_x_axis += 2;

  if ((buffer[5] >> 3) & 1)
    accel_x_axis += 1;

  if ((buffer[5] >> 4) & 1)
    accel_y_axis += 2;

  if ((buffer[5] >> 5) & 1)
    accel_y_axis += 1;

  if ((buffer[5] >> 6) & 1)
    accel_z_axis += 2;

  if ((buffer[5] >> 7) & 1)
    accel_z_axis += 1;

  Serial.print (joy_x_axis, DEC);
  Serial.print ("\t");

  Serial.print (joy_y_axis, DEC);
  Serial.print ("\t");

  Serial.print (accel_x_axis, DEC);
  Serial.print ("\t");

  Serial.print (accel_y_axis, DEC);
  Serial.print ("\t");

  Serial.print (accel_z_axis, DEC);
  Serial.print ("\t");

  Serial.print (z_button, DEC);
  Serial.print ("\t");

  Serial.print (c_button, DEC);
  Serial.print ("\t");

  Serial.println();
  //if(z_button == 1){analogWrite(9,accel_x_axis);  analogWrite(10,accel_y_axis);   analogWrite(11,accel_z_axis);}
}

void loop()
{

  Wire.requestFrom (0x52, 6);
  delay(10);
  while (Wire.available ())
  {
    buffer[cnt] = Wire.read();
    cnt++;

  }

  if (cnt >= 5)
    parse();
  
  cnt = 0;
  handshake();
  delay (20);
}
