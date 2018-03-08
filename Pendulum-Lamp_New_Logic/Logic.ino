void ignition (byte kignitionValue, float richterDegreesValue)
{
  servoCenter ();

  bool kicks = 0;
  while (kicks == 0)
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
  avgPromedier ();
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

//promedierArray [numero de sensor][Largo de promediado]
void avgPromedier ()
{
  for (byte i_vp = 0; i_vp < NLASERS; i_vp++)//i_vp stands for view promedier index variable
  {
    int minR = 1023;//Registry variables and its index variables to select the max, min and threshold value
    byte i_min = 0;
    int maxR = 0;
    byte i_max = 0;
    byte i_th = 0;
    for (byte i_lv = 0; i_lv < LPROMEDIER; i_lv++)//i_lv stands for look for min, max and shadow values in promedier index variable
    {
      //Search for max, min and on values
      if (promedierArray [i_vp][i_lv] < threshold [i_vp] + thRange && promedierArray [i_vp][i_lv] > threshold [i_vp] - thRange)//If in range
      {
        addThresholdAux (i_lv, promedierArray [i_vp][i_lv]);
        avgThresholdAux ();
        i_th = i_lv;
      }
      else if (promedierArray [i_vp][i_lv] > maxR)
      {
        maxR = promedierArray [i_vp][i_lv];
        i_max = i_lv;
      }
      else if (promedierArray [i_vp][i_lv] < minR)
      {
        minR = promedierArray [i_vp][i_lv];
        i_min = i_lv;
      }
    }
    int bAvg = 0;
    for (byte i_dv = 0; i_dv < LPROMEDIER; i_dv++)//i_dv stands for discriminated values fill array sequence index
    {
      if (i_dv != i_th && i_dv != i_max && i_dv != i_min)
      {
        bAvg += promedierArray [i_vp][i_lv];
      }
    }
    avg [i_vp][0] = bAvg / (LPROMEDIER - 3);
  }
  //Medium value calculations to fill threshold [x]
}

void addThresholdAux (byte i_ts, int thValue)//i_st stands for thershold save value index variable, thValue stands for theshold value found in promedier array
{
  for (byte i_sp = 0; i_sp < LPROMEDIER - 1; i_sp++)//i_sp stands for shift promedier index variable
  {
    int bThreshold = thresholdArray [i_ts][i_sp + 1]; //Fill buffer with next row
    thresholdArray [i_ts][i_sp] = bThreshold;
  }
  thresholdArray [i_ts][LPROMEDIER - 1] = thValue;
}

void avgThresholdAux ()
{
  for (byte i_at = 0; i_at < NLASERS; i_at++)
  {
    int minR = 1023;//Registry variables and its index variables to select the max, min and threshold value
    byte i_min = 0;
    int maxR = 0;
    byte i_max = 0;
    for (byte i_ar = 0; i_ar < LPROMEDIER; i_ar++)//i_ar stands for average reading threshold array index value
    {
      if (thresholdArray [i_at][i_ar] > maxR)
      {
        maxR = thresholdArray [i_at][i_ar];
        i_max = i_lv;
      }
      else if (thresholdArray [i_at][i_ar] < minR)
      {
        minR = thresholdArray [i_at][i_ar];
        i_min = i_lv;
      }
    }
    int bThr = 0;//Stands for buffer threshold
    for (byte i_dv = 0; i_dv < LPROMEDIER; i_dv++)//i_dv stands for discriminated values fill array sequence index
    {
      if (i_dv != i_max && i_dv != i_min)
      {
        bThr += thresholdArray [i_at][i_dv];
      }
    }
    avg [i_vp][1] = bThr / (LPROMEDIER - 2);
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

