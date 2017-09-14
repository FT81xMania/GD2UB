#if defined(__arm__)
extern "C" char* sbrk(int incr);
static int FreeStack() {
  char top = 't';
  return &top - reinterpret_cast<char*>(sbrk(0));
}
#endif

char TXP[50];

void STM32a()
{
  ram = FreeStack();
  FRAM=ram;
  if(FRAM<=131072){SRAM=131072;}
              else{SRAM=196608;}
}

void STM32()
{
  GD.SaveContext();
  GD.ColorRGB(0x0000ff); sprintf(TXP,"F_CPU: %d MHz", (F_CPU/1000000));  GD.cmd_text(25, 465, 26, 0, TXP);
  //GD.ColorRGB(0x00ff00); 
  sprintf(TXP,"F_SDIO:  %d MHz", (FreqSDIO/1000000));  GD.cmd_text(175, 465, 26, 0, TXP);
  //GD.ColorRGB(0x00ff00); 
  sprintf(TXP,"F_SPI1:   %d MHz", (FreqSPI1/1000000));  GD.cmd_text(175, 425, 26, 0, TXP);
  //GD.ColorRGB(0x00ff00); 
  sprintf(TXP,"F_SPI3:   %d MHz", (FreqSPI2));  GD.cmd_text(175, 445, 26, 0, TXP);
  //GD.ColorRGB(0x00ff00); 
  sprintf(TXP,"F_RAM:  %d byte", (ram)); // GD.cmd_text(320, 465, 26, 0, TXP);

  GD.cmd_text(320, 425, 26, 0, "RAM:                   Kb");
  GD.printNfloat(402, 425, SRAM/1024, 0, 26);
  
  GD.cmd_text(320, 445, 26, 0, "F_RAM:               %");
  GD.printNfloat(390, 445, (100-100*(SRAM-FRAM)/SRAM), 2, 26);
  
  GD.cmd_text(320, 465, 26, 0, "U_RAM:               %");
  GD.printNfloat(390, 465, 100*(SRAM-FRAM)/SRAM, 2, 26);
  GD.RestoreContext();  
}
