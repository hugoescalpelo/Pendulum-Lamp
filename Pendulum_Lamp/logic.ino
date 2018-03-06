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

//prmdr [NLASERS][LPRMDR]
void addPromedier (byte i_data, byte pData)//i_data stands for index data laser, pData stands for promedier data
{
  for (int p_shift = 0; p_shift < LPRMDR - 1; p_shift++)//p_shift stands for promedier shift index
  {
    byte bPromedier = prmdr [i_data][p_shift + 1];//bPromedier stands for buffer promedier
    prmdr [i_data][LPRMDR] = bPromedier;//Here and the before line pass the next data into the array
  }
  prmdr [NLASERS][pData] = pData;//Add the actual value this function was called for to the bottom of the array
}

void trimPromedier ()
{
  for (int t_nl = 0; t_nl < NLASERS; t_nl++)//t_nl stands for trimmer for the number of lasers index
  {
    byte min_r = 255;//Registry variables and its index variables to select the max, min and threshold value
    byte min_i = 0;
    byte max_r = 0;
    byte max_i = 0;
    byte th_i = 0;
    for (int t_lp = 0; t_lp < LPRMDR; t_lp++)//t_lp stands for trimmer promedier longitude index
    {
      if (prmdr [t_nl][t_lp] < threshold [t_nl] + th_range && prmdr [t_nl][t_lp] > threshold [t_nl] -th_range)
      {
        //addDetectPromedier (t_nl, prmdr [t_nl][t_lp]);
        th_i = t_lp;
      }
      else if (prmdr [t_nl][t_lp] > max_r)
      {
        max_r = prmdr [t_nl][t_lp];
        max_i = t_lp;
      }
      else if (prmdr [t_nl][t_lp] < min_r)
      {
        min_r = prmdr [t_nl][t_lp];
        min_i = t_lp;
      }
    }
  }
}

