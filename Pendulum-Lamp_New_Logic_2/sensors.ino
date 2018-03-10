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

void protoChange ()
{
  lData = aData;
  for (byte i_ra = 0; i_ra < NSENSORS; i_ra++)//Buids the binary data variable to work with
  {
   if (bData [i_ra] < PROTOTH)//The threshold value determines wich value has to be written
    {
      bitClear (aData, i_ra);
    }
    else
    {
      bitSet (aData, i_ra);
    }
  }
}

