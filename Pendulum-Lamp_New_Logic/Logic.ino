void ignition (byte kignitionValue, float richterDegreesValue)
{
  servoCenter ();

  bool kicks = 0;
  while (kicks = 0)
  {
    readAll ();//Read all sensors
    promedier ();//Calculate average on/off levels
    movementDescriptor (richterDegreesValue, IGND);
    motorRender ();
  }
}

void promedier ()
{
  addPromedier ();//Adds all current values to promedier array
  //get the avg values on off. Detect on off
}

void addPromedier ()
{
  for (byte i_sp = 0; i_sp < LPROMEDIER - 1; i_sp++)//i_sp stands for shift promedier index variable
  {
    int bPromedier [NLASERS] = {};
    for (byte i_fb = 0; i_fb < NLASERS; i_fb++)//i_fb stands for fill buffer promedier index variable
    {
      bPromedier [i_fb] = promedierArray [i_fb][i_sp + 1];//Fill buffer with next row
    }
    for (byte i_fb = 0; i_fb < NLASERS; i_fb++)
    {
      promedierArray [i_fb][i_sp] = bPromedier [i_fb];//Fill the actual row with next row
    }
  }
  for (byte i_ap = 0; i_ap < NLASERS; i_ap++)//i_ap stands for add promedier index variable
  {
    promedierArray [i_ap][LPROMEDIER - 1] = bData [i_ap];
  }
}
void directionDetector ()
{
  //
}

void movementDescriptor (float richterValue, bool movementSet)
{
  //
}

void motorWatchdog ()
{
  //
}

