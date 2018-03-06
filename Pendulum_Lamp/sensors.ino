void readAll ()
{
  bData [0] = analogRead (A0);
  bData [1] = analogRead (A1);
  bData [2] = analogRead (A2);
  bData [3] = analogRead (A3);
  bData [4] = analogRead (A4);
  bData [5] = analogRead (A5);
  bData [6] = analogRead (A6);
  bData [7] = analogRead (A7);
  
  for (int ir = 0; ir < NLASERS; ir++)
  {
    Serial.print (bData [ir]);
    Serial.print (" ");
    if (bData [ir] < threshold)
    {
      bitClear (aData, ir);
    }
    else
    {
      bitSet (aData, ir);
    }
  }
  Serial.println ();
  Serial.println (aData, BIN);
}

