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
void addPromedier (byte i_data, int pData)//i_data stands for index data laser, pData stands for promedier data
{
  for (byte p_shift = 0; p_shift < LPRMDR - 1; p_shift++)//p_shift stands for promedier shift index
  {
    int bPromedier = prmdr [i_data][p_shift + 1];//bPromedier stands for buffer promedier
    prmdr [i_data][LPRMDR] = bPromedier;//Here and the before line pass the next data into the array
  }
  prmdr [i_data][LPRMDR - 1] = pData;//Add the actual value this function was called for to the bottom of the array
}

void trimAndAvg ()
{
  for (byte t_nl = 0; t_nl < NLASERS; t_nl++)//t_nl stands for trimmer for the number of lasers index
  {
    int minR = 1023;//Registry variables and its index variables to select the max, min and threshold value
    byte min_i = 0;
    int maxR = 0;
    byte max_i = 0;
    byte th_i = 0;
    for (byte t_lp = 0; t_lp < LPRMDR; t_lp++)//t_lp stands for trimmer promedier longitude index
    {
      if (prmdr [t_nl][t_lp] < threshold [t_nl] + th_range && prmdr [t_nl][t_lp] > threshold [t_nl] -th_range)
      {
        addDetectPromedier (t_nl, prmdr [t_nl][t_lp]);
        detectTrimAndAvg ();
        th_i = t_lp;
      }
      else if (prmdr [t_nl][t_lp] > max_r)
      {
        maxR = prmdr [t_nl][t_lp];
        max_i = t_lp;
      }
      else if (prmdr [t_nl][t_lp] < min_r)
      {
        minR = prmdr [t_nl][t_lp];
        min_i = t_lp;
      }
    }
    int bAvg = 0;//Stands for buffer average auxiliar variable
    for (byte avg_i = 0; avg_i < LPRMDR; avg_i++)//avg_i stands for average index variable
    {
      if (avg_i != th_i && avg_i != max_i && avg_i != min_i)
      {
        bAvg += prmdr [t_nl][avg_i];
      }
    }
    avg [t_nl][0] = bAvg / (LPRMDR - 3);
  }
}

void addDetectPromedier (byte d_ln, int thDet)//d_ln stands for detect laser number, thDet stands for detecht threshold
{
  for (byte d_shift = 0; d_shift < LPRMDR - 1; d_shift++)//d_shift stands for detect shift index
  {
    int bDetect= dPrmdr [d_ln][d_shift + 1];//bDetect stands for buffer detect promedier
    dPrmdr [d_ln][LPRMDR] = bDetect;//Here and the before line pass the next data into the array
  }
  dPrmdr [d_ln][LPRMDR - 1] = thDet;//Add the actual value this function wass called for to the bottom of the array
}

void detectTrimAndAvg ()
{
  //for (byte t_dtct = 0; t_dtct < NLASERS;
  //
  for (byte t_nl = 0; t_nl < NLASERS; t_nl++)//t_nl stands for trimmer for the number of lasers index
  {
    int minR = 1023;//Registry variables and its index variables to select the max, min and threshold value
    byte min_i = 0;
    int maxR = 0;
    byte max_i = 0;
    byte th_i = 0;
    for (byte t_lp = 0; t_lp < LPRMDR; t_lp++)//t_lp stands for trimmer promedier longitude index
    {
      if (prmdr [t_nl][t_lp] < threshold [t_nl] + th_range && prmdr [t_nl][t_lp] > threshold [t_nl] -th_range)
      {
        addDetectPromedier (t_nl, prmdr [t_nl][t_lp]);
        detectTrimAndAvg ();
        th_i = t_lp;
      }
      else if (prmdr [t_nl][t_lp] > max_r)
      {
        maxR = prmdr [t_nl][t_lp];
        max_i = t_lp;
      }
      else if (prmdr [t_nl][t_lp] < min_r)
      {
        minR = prmdr [t_nl][t_lp];
        min_i = t_lp;
      }
    }
    int bAvg = 0;//Stands for buffer average auxiliar variable
    for (byte avg_i = 0; avg_i < LPRMDR; avg_i++)//avg_i stands for average index variable
    {
      if (avg_i != th_i && avg_i != max_i && avg_i != min_i)
      {
        bAvg += prmdr [t_nl][avg_i];
      }
    }
    avg [t_nl][0] = bAvg / (LPRMDR - 3);
  }
}

