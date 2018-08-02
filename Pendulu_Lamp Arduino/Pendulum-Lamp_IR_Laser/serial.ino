void printTargetTime ()
{
  Serial.print (travelTime);
  Serial.print (" ");
  Serial.print (timeNow);
  Serial.print (" ");
  Serial.println (targetTime);
}


void printIgnitionMotorMonitor ()
{
  Serial.print (targetPosition);
  Serial.print (" ");
  Serial.print (timeNow);
  Serial.print (" ");
  Serial.println (targetTime);
}

void printPositions ()
{
  Serial.print (positionF);
  Serial.print (" ");
  Serial.println (positionB);
}

void printProtoChange ()
{
  Serial.println (aData, BIN);
}

void printDirection ()
{
  if (lampDirection == 1)
  {
    Serial.println ("Der");
  }
  else
  {
    Serial.println ("Izq");
  }
}

void listenPort ()
{
  if (Serial.available () > 0)//5.5 to 8
  {
    float data = Serial.parseFloat ();
    if (data < 10)
    {
      Serial.print ("Last intensity ");
      Serial.print (richter, 1);
      richter = data;
      Serial.print (" New intensity ");
      Serial.println (richter, 1);
    }
    else if (data == 15)
    {
      poke ();
    }
  }
}

void printValues ()
{
  for (byte i = 0; i < NSENSORS; i++)
  {
    Serial.print (bData [i]);
    Serial.print (" ");
  }
  Serial.println ();
}

//void printC1C2 ()
//{
//  Serial.println("Readings");
//  for (byte i_r = 0; i_r < LENGTHC1; i_r++)
//  {
//    for (byte i_c = 0; i_c < NSENSORS; i_c++)
//    {
//      Serial.print (c1 [i_c][i_r]);
//      Serial.print (" ");
//    }
//    Serial.println ();
//  }
//  Serial.println ("Detect");
//  for (byte i_r = 0; i_r < LENGTHC1; i_r++)
//  {
//    for (byte i_c = 0; i_c < NSENSORS; i_c++)
//    {
//      Serial.print (c2 [i_c][i_r]);
//      Serial.print (" ");
//    }
//    Serial.println ();
//  }
//  Serial.println ();
//}

void printDinamicThreshold ()
{
  Serial.println ("Dinamic Threshold");
  for (byte i_c = 0; i_c < NSENSORS; i_c++)
  {
    Serial.print (dinamicThreshold [i_c]);
    Serial.print (" ");
  }
  Serial.println ();
}

void printAvg ()
{
  Serial.println ("Avgs");
  for (byte i_r = 0; i_r < 2; i_r++)
  {
    for (byte i_c = 0; i_c < NSENSORS; i_c++)
    {
      Serial.print (avgArray [i_c][i_r]);
      Serial.print (" ");      
    }
    Serial.println ();
  }
  Serial.println ();
}

