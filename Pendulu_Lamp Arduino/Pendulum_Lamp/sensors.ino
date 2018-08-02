//void readAll ()
//{
//  bData [0] = analogRead (A0);//Read all sensors
//  bData [1] = analogRead (A1);
//  bData [2] = analogRead (A2);
//  bData [3] = analogRead (A3);
//  bData [4] = analogRead (A4);
//  bData [5] = analogRead (A5);
//  bData [6] = analogRead (A6);
//  bData [7] = analogRead (A7);
//
//  for (byte ir = 0; ir < NLASERS; ir++)//Buids the binary data variable to work with
//  {
//   if (bData [ir] < threshold)//The threshold value determines wich value has to be written
//    {
//      bitClear (aData, ir);
//    }
//    else
//    {
//      bitSet (aData, ir);
//    }
//  }
//}

