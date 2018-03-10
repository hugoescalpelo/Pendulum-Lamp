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
      takeMeOut ();
    }
  }
}

void printValues ()
{
  for (int i = 0; i < NSENSORS; i++)
  {
    Serial.print (bData [i]);
    Serial.print (" ");
  }
  Serial.println ();
}

