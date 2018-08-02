void listenPort ()
{
  //
}

void printProtoThresholdFiller ()
{
  for (byte i_pf = 0; i_pf < NLASERS; i_pf++)//i_pf stands for proto threshold filler index variable
  {
    Serial.print (protoThreshold [i_pf]);
    Serial.print (" ");
  }
  Serial.println ();
}

void printKickCounter ()
{
  Serial.print ("Kick no. ");
  Serial.println (kicks);
}

void printReadAll ()
{
  for (byte i_pr = 0; i_pr < NLASERS; i_pr++)
  {
    Serial.print (bData [i_pr]);
    Serial.print (" ");
  }
  Serial.println ();
}

void printProtoChange ()
{
  Serial.print (aData, BIN);
  Serial.print (" ");
  Serial.println (aData);
}

void printMovementDescriptor ()
{
  Serial.print ("eF ");
  Serial.print (extensionF);
  Serial.print (" eB ");
  Serial.print (extensionB);
  Serial.print (" tT ");
  Serial.print (travelTime);
  Serial.print (" mL ");
  Serial.print (movementLength);
  Serial.print (" tn ");
  Serial.print (millis ());
  Serial.print (" tr ");
  Serial.println (targetTime);
}

