
#define DATAOUT 11 //MOSI
#define DATAIN 12 //MISO - not used, but part of builtin SPI
#define SPICLOCK 13 //sck
#define SLAVESELECT 10 //ss

char spi_transfer( char data)
{
  SPDR = data;                    // Start the transmission
  while (!(SPSR & (1 << SPIF)))   // Wait the end of the transmission
  {
  };
  return SPDR;                    // return the received byte
}

byte ledcode[10] = {
  B00111111, // = 0
  B00000110, // = 1
  B01011011, // = 2
  B01001111, // = 3
  B01100110, // = 4
  B01101101, // = 5
  B01111101, // = 6
  B00000111, // = 7
  B01111111, // = 8
  B01101111 // = 9
};
unsigned long nextsecond = 0;
byte s = 0;
byte ss = 0;
byte m = 0;
byte mm = 0;

void setup()
{

  pinMode(DATAOUT, OUTPUT);
  pinMode(DATAIN, INPUT);
  pinMode(SPICLOCK, OUTPUT);
  pinMode(SLAVESELECT, OUTPUT);
  digitalWrite(SLAVESELECT, HIGH); //disable device
  //sample on leading edge of clk,system clock/64
  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR1);
  delay(100);
  digitalWrite(SLAVESELECT, LOW);
  delay(10);
  spi_transfer(ledcode[0]);            // 4th Digit
  spi_transfer(ledcode[0]);            // 3th Digit O
  spi_transfer(ledcode[0] + 128);      // 2th Digit O
  spi_transfer(ledcode[0] );           // 1th Digit C
  digitalWrite(SLAVESELECT, HIGH);
  delay(10);
}

void loop()
{
  if (millis() >= nextsecond) ///////// CHRONOMETRE //////////////
  { digitalWrite(SLAVESELECT, LOW);
    delay(10);
    spi_transfer(ledcode[s]);            // 4th Digit
    spi_transfer(ledcode[ss]);            // 3th Digit O
    spi_transfer(ledcode[m] + 128);      // 2th Digit O
    spi_transfer(ledcode[mm] );           // 1th Digit C
    digitalWrite(SLAVESELECT, HIGH);
    delay(10);
    nextsecond = nextsecond + 1000; ++s; if (s > 9)
    { s = 0; ++ss; if (ss > 5)
      { ss = 0; ++m; if (m > 9)
        {
          m = 0;
          ++mm;
          if (mm > 9) {}
        }
      }
    }
  }
}



