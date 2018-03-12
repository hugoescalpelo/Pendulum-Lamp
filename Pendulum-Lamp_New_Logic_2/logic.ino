void adjustRichter (float rch)
{
  int rr = rch * 10;

  positionB = map (rr, MINRICHTER, MAXRICHTER, MINFRONT, MAXFRONT);
  positionF = map (rr, MINRICHTER, MAXRICHTER, MINBACK, MAXBACK);
  //printPositions ();
}

void getTargetTime ()
{
  int rr= richter * 10;
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
  for (byte i_r = 0; i_r < LENGHTC1; i_r++)
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
