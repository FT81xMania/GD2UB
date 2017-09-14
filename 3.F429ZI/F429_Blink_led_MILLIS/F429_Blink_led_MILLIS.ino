//#include <EEPROM.h> 
#include <SPI.h>
#include <GD23STM32U.h>

#define LEDP1      PG13
#define LEDP2      PG14

long previousMillisLED = 0; 
long intervalLED = 1000; 

static uint16_t options = LOW;

void setup()
{
  pinMode(LEDP1, OUTPUT); //HIGH
  //digitalWrite(LEDP1,options);
  digitalWrite(LEDP1,HIGH);
  
  pinMode(LEDP2, OUTPUT); //HIGH
  digitalWrite(LEDP2,options);

  GD.begin();
}

void loop()
{
  GD.ClearColorRGB(0x002000);
  GD.Clear();
  GD.cmd_text(GD.w / 2, GD.h / 2, 31, OPT_CENTER, "Hello world");
  
  Leds();
  //Led1();
  //Led2();

  GD.swap();
}
