void adjustRichter (float rch)
{
  int rr = rch * 10;

  positionB = map (rr, MINRICHTER, MAXRICHTER, MINFRONT, MAXFRONT);
  positionF = map (rr, MINRICHTER, MAXRICHTER, MINBACK, MAXBACK);
  //printPositions ();
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

