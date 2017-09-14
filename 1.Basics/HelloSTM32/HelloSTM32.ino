#include <GD2UB.h>

Bitmap SaidHello;

//Cortina
int PIx=0, VX=-10, velP=VX, AvanceC=1;
//Cortina

void setup()
{
  GD.begin();
  espera();
   delay(1500);
  SaidHello.fromtext(31, "FT8XX on STM32F");
}

int ANG=0;

  int minX = 0, minY = 0;
  int maxX = 800 - minX, maxY = 480 - minY;
  int startX = maxX / 2, startY = maxY / 2;
  int deltaX = 2, deltaY = 2;

void loop()
{
  ANG = ANG + 1;
  if (ANG>=360){ANG=0;}

   startX = startX + deltaX;   startY = startY + deltaY;
   if (startX >= maxX)
       deltaX = -deltaX;
   if (startX <= minX)
       deltaX = abs(deltaX);
   if (startY >= maxY)
       deltaY = -deltaY;
   if (startY <= minY)
       deltaY = abs(deltaY);
  
  GD.ClearColorRGB(0x000055);
  GD.Clear();
  
  GD.ColorRGB(0xffffff); SaidHello.draw(startX, startY, DEGREES(ANG));

  Cortina();
  GD.swap();
}
