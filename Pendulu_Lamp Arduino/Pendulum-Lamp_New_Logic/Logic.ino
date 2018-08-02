void ignition (byte kignitionValue, float richterDegreesValue)
{
  //Serial.println ("Ignition Started");
  pendulum.write (45);
  delay (1000);
  servoCenter ();
  delay (2000);
  //Serial.println ("Servo forced");
  
  protoThresholdFiller ();
  //printProtoThresholdFiller ();

  kicks = 0;
  while (kicks < kignitionValue)
  {
    //printKickCounter ();
    readAll ();//Read all sensors
    //printReadAll ();
    protoChange ();//calls a function that rudimentarily checks changes in motion
    //printProtoChange();
    if (aData != lData)
    {
      printProtoChange();
      promedier ();//Calculate average on/off levels
    }
    
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
        i_th = i_lv;
        addThresholdAux (i_lv, promedierArray [i_vp][i_th]);
        avgThresholdAux ();
      }
      else if (promedierArray [i_vp][i_lv] > maxR)
      {
        i_max = i_lv;
        maxR = promedierArray [i_vp][i_max];
      }
      else if (promedierArray [i_vp][i_lv] < minR)
      {
        i_min = i_lv;
        minR = promedierArray [i_vp][i_min];
      }
    }
    int bAvg = 0;
    for (byte i_dv = 0; i_dv < LPROMEDIER; i_dv++)//i_dv stands for discriminated values fill array sequence index
    {
      if (i_dv != i_th && i_dv != i_max && i_dv != i_min)
      {
        bAvg += promedierArray [i_vp][i_dv];
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
        i_max = i_ar;
        maxR = thresholdArray [i_at][i_max];
      }
      else if (thresholdArray [i_at][i_ar] < minR)
      {
        i_min = i_ar;
        minR = thresholdArray [i_at][i_min];
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
    avg [i_at][1] = bThr / (LPROMEDIER - 2);
  }
}

void movementDescriptor (float richterValue, bool movementSet)
{
  if (reached == 1 && movementSet == WRKD)
  {
    //
  }
  else if (r1 == 1 && movementSet == IGND)
  {
    //Serial.println ("Movement Descriptor ignition ");
    extensionF = SERVOCENTER + map (richterValue, MINRICHTER, MAXRICHTER, MINEXTENSION, MAXEXTENSION);//Extension front
    extensionB = SERVOCENTER - map (richterValue, MINRICHTER, MAXRICHTER, MINEXTENSION, MAXEXTENSION);//Extension back
    travelTime = map (richterValue, MINRICHTER, MAXRICHTER, MAXTRAVELTIME, MINTRAVELTIME);
    movementLength = extensionF - extensionB;
    toogleDirection ();
    reached = 0;
    r1 = 0;
    wFlag = 0;
    targetTime = millis () + travelTime;
    printMovementDescriptor ();
  }
}

void toogleDirection ()
{
  lServoDirection = servoDirection;
  if (servoDirection == 1)
  {
    servoDirection = 0;
  }
  else
  {
    servoDirection = 1;
  }
  if (lServoDirection != servoDirection)
  {
    directionChanged = 1;
  }
}

void motorRender ()
{
  timeNow = millis ();
//  Serial.print ("tN ");
//  Serial.print (timeNow);
//  Serial.print (" sD ");
//  Serial.println (servoDirection);
  if (timeNow < targetTime && servoDirection == 1 && r1 == 0)
  {
    //Serial.println ("Movin servo direction 1");
    dinamicPosition = map (targetTime - timeNow, 0, travelTime, extensionF, extensionB);
    pendulum.write (dinamicPosition);
  }
  else if (timeNow > targetTime && servoDirection == 1 && r1 == 0)
  {
    pendulum.write (extensionF);
    r1 = 1;
    Serial.println ("dP reached 1");
  }
  else if (timeNow < targetTime && servoDirection == 0 && r1 == 0)
  {
    //Serial.println ("Movin servo direction 0");
    dinamicPosition = map (targetTime - timeNow, 0, travelTime, extensionB, extensionF);
    pendulum.write (dinamicPosition);
  }
  else if (timeNow > targetTime && servoDirection == 0 && r1 == 0)
  {
    pendulum.write (extensionF);
    r1 = 1;
    Serial.println ("dP reached 0");
  }
    
  if (directionChanged == 1 && reached == 0)
  {
    directionChanged = 0;
    Serial.println ("dC");
  }

  lc = lampChangeDirection ();
  if (directionChanged == 0 && lc == 1)
  {
    //reached = 1;
    lc = 0;
    //kicks++;
    //Serial.print ("kicks ");
    //Serial.println (kicks);
  }
  
}

bool lampChangeDirection ()
{
  
  if (aData == mData && lData == 255)
  {
    //Serial.println ("dc1");
    return (1);
  }
  else if (lData == nData && mData == 255)
  {
    //Serial.println ("dc2");
    return (1);
  }
  else
  {
    return (0);
  }
}
void motorWatchdog ()
{
  //
}

