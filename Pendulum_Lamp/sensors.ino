void readAll ()
{
  for (int ir = 0; ir <= 8; ir++)
  {
    dataSensor [ir] = digitalRead (pinSensor [ir]);
  }
}

