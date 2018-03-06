void printAllSensors ()
{
  for (int p_as = 0; p_as < NLASERS; p_as++)
  {
    Serial.print (bData [p_as]);
    Serial.print (" ");
  }
  Serial.println ();
}

void printBinaries ()
{
  Serial.print ("Bin ");
  Serial.print (aData, BIN);
  Serial.print (" last ");
  Serial.println (lData, BIN);
}

void printPositions ()
{
  Serial.print ("PosBin ");
  Serial.print (pos_bin);
  Serial.print (" PosIndex ");
  Serial.println (pos_indx);
}

