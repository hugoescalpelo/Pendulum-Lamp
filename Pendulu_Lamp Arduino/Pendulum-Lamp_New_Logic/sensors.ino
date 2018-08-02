void readAll ()
{
  bData [0] = analogRead (A0);//Read all sensors
  bData [1] = analogRead (A1);
  bData [2] = analogRead (A2);
  bData [3] = analogRead (A3);
  bData [4] = analogRead (A4);
  bData [5] = analogRead (A5);
  bData [6] = analogRead (A6);
  bData [7] = analogRead (A7);    
}

void protoThresholdFiller ()
{
  for (byte i_pf = 0; i_pf < NLASERS; i_pf++)//i_pf stands for proto threshold filler index variable
  {
    protoThreshold [i_pf] = protoTh;
  }
}

void protoChange ()
{
  nData = mData;
  mData = lData;
  lData = aData;
  for (byte i_ra = 0; i_ra < NLASERS; i_ra++)//Buids the binary data variable to work with
  {
   if (bData [i_ra] < protoThreshold [i_ra])//The threshold value determines wich value has to be written
    {
      bitClear (aData, i_ra);
    }
    else
    {
      bitSet (aData, i_ra);
    }
  }
}

