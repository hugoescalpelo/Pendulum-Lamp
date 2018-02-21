void startEngine ()
{
  for (int i = 0; i < 15; i++)
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

void impulse (char r)//R stands for richter
{
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
  int rr = r * 10;
  int r_wait = map (rr, 55, 87, 200, 10);
  delay (r_wait);
}

//void takeMeOut ()
//{
//  if (timeNow - timeLast > 2000)
//  {
//    Serial.println ("Take me out");
//    //myServo.write (angle);
//    timeLast = timeNow;
//
//    if (polar == 1)
//    {
//      angle = angle_b;
//      myServo.write (angle);
//      polar = 0;
//    }
//    else if (polar == 0)
//    {
//      angle = angle_a;
//      myServo.write (angle);
//      polar = 1;
//    }
//  }
//}

