void impulse (char r)//R stands for richter
{
  if (polar == 1 && pos_indx == 3)
  {
    angle = angle_b;
    myServo.write (angle);
    polar = 0;
  }
  if (polar == 0 && pos_indx == 6)
  {
    angle = angle_a;
    myServo.write (angle);
    polar = 1;
  }
  int rr = r * 10;
  int r_wait = map (rr, 55, 87, 200, 10);
  delay (r_wait);
}

