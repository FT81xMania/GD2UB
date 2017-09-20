void setup()
{
  GD.begin();
    //GD.cmd_setrotate(0);
   // GD.self_calibrate(); 
  SD.begin(SD_CS, SD_SCK_MHZ(FreqSPI2));
  
  CobraSTM32();
}
void loop(){}
