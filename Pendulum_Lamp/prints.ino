void printAllSensors ()
{
  Serial.println (aData, BIN);
  Serial.println (lData, BIN);
  Serial.println ();
}

void printBinaries ()
{
  Serial.print ("l= ");
  Serial.print (pos_bin);
  Serial.print (" p= ");
  Serial.println (pos_indx);
}

