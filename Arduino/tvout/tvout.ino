#include <TVout.h>
int x;
int y;
TVout TV;
int o=0;
unsigned long  previousMillis;
int b;
void setup ()
{
  TV.begin(_PAL);

//  TV.clear_screen ();
//  TV.print_str (10, 10, "OUVREZ DU BONHEUR" );
//
//  TV.print_str (20, 20, "OUVREZ DU BONHEUR" );
//  TV.delay (20);
  TV.clear_screen ();
  delay(100);
  TV.fill(WHITE);

}

void loop ()
{  
}
