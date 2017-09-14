void espera()
{
  GD.ClearColorRGB(0xffffff); //fondo de pantalla
  GD.Clear();
  GD.ColorA(255);
  GD.ColorRGB(0x000000); GD.cmd_text(GD.w / 2, GD.h / 2, 27, OPT_CENTERX, "Iniciando sistema..."); 
  GD.swap(); 
}
