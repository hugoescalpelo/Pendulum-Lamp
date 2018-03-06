void ignitionSequence (byte igntnStps)
{
  myServo.write (90);
  delay (2000);
  refreshRichter (intensity);
  for (int i = 0; i < igntnStps; i++)
  {
    if (polar == 0)
    {
      myServo.write (angle);
      angle = angle_b;
      polar = 1;
    }
    else if (polar == 1)
    {
      myServo.write (angle);
      angle = angle_a;
      polar = 0;
    }
    delay (800);
  }
}

void impulse (float ri)//ri stands for richter impulse
{
  refreshRichter (ri);
  
  delay (r_wait);
  
  if (polar == 1 && pos_indx <= 4)
  {
    angle = angle_b;
    myServo.write (angle);
    polar = 0;
  }
  else if (polar == 0 && pos_indx >= 5)
  {
    angle = angle_a;
    myServo.write (angle);
    polar = 1;
  }
  
  
}

void takeMeOut ()
{
  if (timeNow - timeLast > 2000)
  {
    if (polar == 1)
    {
      angle = angle_b;
      myServo.write (angle);
      polar = 0;
    }
    else if (polar == 0)
    {
      angle = angle_a;
      myServo.write (angle);
      polar = 1;
    }
    Serial.println ("Take me out");
    myServo.write (angle);
    timeLast = timeNow;
  }
}

