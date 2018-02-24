void readAll ()
{
  for (int ir = 0; ir < 8; ir++)
  {
    bitWrite (aData, ir, digitalRead (pinSensor [ir]));
  }
}

int readDirection ()
{
  return (aData-lData);
}

