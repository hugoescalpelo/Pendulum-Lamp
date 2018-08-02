void ignition ()
{
  adjustRichter (richter);
  setServo ();
  timeNow = millis ();
  getTargetTime ();
  targetPosition = positionF;
  //printTargetTime ();
  while (kicks < IGND)
  {
    //printIgnitionMotorMonitor ();
    readAll ();
    add ();
    extractDetect ();

    //printValues();
    protoChange ();
    if (lData != aData && aData != 255)
    {
      printProtoChange ();
      printDinamicThreshold ();
      printAvg ();

      checkDirection ();
      checkChangeDirection ();
    }
    if (timeNow > targetTime)
    {
      pendulum.write (targetPosition);
      toogleTargetPosition ();
      getTargetTime ();
      kicks++;
    }

    timeNow = millis ();
  }
}

void motorDrive ()
{
  if (changeDirection == 1)
  {
    mData = aData;
    changeDirection = 0;
    adjustRichter (richter);
    toogleTargetPosition ();
    pendulum.write (targetPosition);
  }
}

void setServo ()
{
  for (byte r = 0; r < LENGHTC1; r++)
  {
    readAll ();
    add ();
  }
  for (byte i_c = 0; i_c < NSENSORS; i_c++)
  {
    int avgAux = 0;
    for (byte i_r = 0; i_r < LENGHTC1; i_r++)
    {
      avgAux += c1 [i_c][i_r];
    }
    avgArray [i_c][0] = avgAux / LENGHTC1;
    dinamicThreshold [i_c] = diferentialThreshold / 2;
  }
  pendulum.write (45);
  delay (1000);
  pendulum.write (CENTERPOSITION);
  delay (1000);
}

