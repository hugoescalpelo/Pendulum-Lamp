void ignition ()
{
  pendulum.write (45);
  delay (1000);
  pendulum.write (CENTERPOSITION);
  delay (2000);
  adjustRichter (richter);
  
  timeNow = millis ();
  getTargetTime ();
  targetPosition = positionF;
  //printTargetTime ();
  while (kicks < IGND)
  {
    //printIgnitionMotorMonitor ();
    readAll ();
    //printValues();
    protoChange ();
    if (lData != aData && aData != 255)
    {
      printProtoChange ();
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
    changeDirection = 0;
    adjustRichter (richter);
    toogleTargetPosition ();
    pendulum.write (targetPosition);
  }
}

void takeMeOut ()
{
  //
}

