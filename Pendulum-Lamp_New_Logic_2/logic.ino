void adjustRichter (float rch)
{
  int rr = rch * 10;

  positionB = map (rr, MINRICHTER, MAXRICHTER, MINFRONT, MAXFRONT);
  positionF = map (rr, MINRICHTER, MAXRICHTER, MINBACK, MAXBACK);
  //printPositions ();
}

void getTargetTime ()
{
  int rr = richter * 10;
  travelTime = map (rr, MINRICHTER, MAXRICHTER, MAXTRAVELTIME, MINTRAVELTIME);
  targetTime = millis () + travelTime;
}



void checkDirection ()
{
  if (aData != lData && aData != 255)
  {
    printProtoChange ();
    //printValues ();
    if (~mData < ~aData)
    {
      lampDirection = 0;
    }
    else
    {
      lampDirection = 1;
    }
    mData = aData;
  }
}

void checkChangeDirection ()
{
  if (lLampDirection != lampDirection)
  {
    changeDirection = 1;
    //printDirection ();
    //printC1C2 ();
  }
  lLampDirection = lampDirection;
}


void toogleTargetPosition ()
{
  if (targetPosition > CENTERPOSITION)
  {
    targetPosition = positionF;
  }
  else if (targetPosition < CENTERPOSITION)
  {
    targetPosition = positionB;
  }
}

void add ()
{
  for (byte i_r = 0; i_r < LENGHTC1 - 1; i_r++)
  {
    int shiftAux [NSENSORS] = {};
    for (byte i_c = 0; i_c < NSENSORS; i_c++)
    {
      shiftAux [i_c] = c1 [i_c][i_r + 1];
    }
    for (byte i_c = 0; i_c < NSENSORS; i_c++)
    {
      c1 [i_c][i_r] = shiftAux [i_c];
    }
  }
  for (byte i_a = 0; i_a < NSENSORS; i_a++)//i_ap stands for add index
  {
    c1 [i_a][LENGHTC1 - 1] = bData [i_a];
  }
}

void extractDetect ()
{
  for (byte i_c = 0; i_c < NSENSORS; i_c++)
  {
    int minR = 1023;
    byte i_min = 0;
    int maxR = 0;
    byte i_max = 0;
    for (byte i_r = 0; i_r < LENGHTC1; i_r++)
    {
      if (c1 [i_c][i_r] < minR)
      {
        minR = c1 [i_c][i_r];
        i_min = i_r;
      }
      if (c1 [i_c][i_r] > maxR)
      {
        maxR = c1 [i_c][i_r];
        i_max = i_r;
      }
    }
    if (maxR != 0 || minR != 1023)
    {
      int bd = (maxR - minR) / 2;
      if (bd > diferentialThreshold)
      {
        dinamicThreshold [i_c] = bd;
      }
      if (c1 [i_c][LENGHTC1 - 1] < maxR - dinamicThreshold [i_c])
      {
        addDetect (i_c, c1 [i_c][LENGHTC1 - 1]);
      }
    }
    byte c = 0;
    int b = 0;
    for (int i_r = 0; i_r < LENGHTC1; i_r++)
    {
      if (c1 [i_c][i_r] > maxR - dinamicThreshold [i_c])
      {
        b += c1 [i_c][i_r];
        c++;
      }
    }
    avgArray [i_c][0] = b / c;
    b = 0;
    for (int i_r = 0; i_r < LENGHTC1; i_r++)
    {
      b += c2 [i_c][i_r];
    }
    avgArray [i_c][1] = b / LENGHTC1;
  }
  //printDinamicThreshold ();
  //printAvg ();
}

void addDetect (byte i_c_ad, int minRAD)
{
  for (byte i_r_ad = 0; i_r_ad < LENGHTC1 - 1; i_r_ad++)
  {
    int shiftAux_ad = c2 [i_c_ad][i_r_ad + 1];
    c2 [i_c_ad][i_r_ad] = shiftAux_ad;
  }
  c2 [i_c_ad][LENGHTC1 - 1] = minRAD;
}
void takeMeOut ()
{
  timeNow = millis ();
  if (timeNow > targetTime + 2000 && aData == lData)
  {
    changeDirection = 1;
    getTargetTime ();
    Serial.println ("Change Direction");
  }
}
