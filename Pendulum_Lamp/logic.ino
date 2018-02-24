void refreshRichter (float r)
{
  int rr = r * 10;

  r_wait = map (rr, min_r, max_r, rWaitMax, rWaitMin);

  angle_a = map (rr, min_r, max_r, min_a, max_a);
  angle_b = map (rr, min_r, max_r, min_b, max_b);
}

void listenPort ()
{
  if (Serial.available () > 0)//5.5 to 8
  {
    float data = Serial.parseFloat ();
    if (data < 10)
    {
      Serial.print ("Last intensity ");
      Serial.print (intensity, 1);
      intensity = data;
      Serial.print (" New intensity ");
      Serial.println (intensity, 1);
    }
    else if (data == 15)
    {
      takeMeOut ();
    }
  }

}

