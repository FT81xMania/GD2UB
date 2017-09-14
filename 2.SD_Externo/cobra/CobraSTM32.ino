void CobraSTM32()
{
  GAsset4 = SD.open(STRAsset4); 
  LOAD_ASSETS4();
  
  GD.BitmapHandle(BACKGROUND_HANDLE);
  GD.BitmapSize(BILINEAR, REPEAT, REPEAT, 800, 480);

  while(1)
  {
  GD.Begin(BITMAPS);
  GD.SaveContext();
  GD.BitmapHandle(BACKGROUND_HANDLE);
  GD.cmd_translate(-(long)t << 14, (long)t << 13);
  GD.cmd_rotate(3312);
  GD.cmd_setmatrix();
  GD.Vertex2ii(0, 0, 0, 0);
  GD.RestoreContext();

  int et = t - 720;
  int sun_x = (800 * 16) - (et << 2),
      sun_y = (100 * 16) + (et << 1);
  GD.SaveContext();
  GD.PointSize(52 * 16);
  GD.ColorRGB(0x000000);
  GD.Begin(POINTS);
  GD.Vertex2f(sun_x, sun_y);
  GD.RestoreContext();

  GD.SaveContext();
  GD.Begin(BITMAPS);
  GD.BlendFunc(ONE, ONE);
  GD.BitmapHandle(SUN_HANDLE);
  GD.ColorRGB(0xb0a090);
  draw_sun(sun_x, sun_y, t << 6);
  draw_sun(sun_x, sun_y, -t << 6);
  GD.RestoreContext();

  GD.get_inputs();
  byte touching = (GD.inputs.x != -32768);
  if (!prev_touching && touching)
    startMotion(GD.inputs.x, GD.inputs.y);
  else if (touching)
    trackMotion(GD.inputs.x, GD.inputs.y);
  prev_touching = touching;

  unsigned long t0 = micros();

  if (angle != 0.0f)
    rotation(angle, axis);

  project(0);
  draw_navlight(1);
  draw_faces();
  GD.RestoreContext();
  draw_edges();
  draw_navlight(0);
  GD.RestoreContext();

  STM32a();
  STM32();

  GD.swap();

  t++;
  }
}
