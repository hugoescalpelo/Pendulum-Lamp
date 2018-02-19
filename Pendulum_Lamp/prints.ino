void printAllSensors ()
{
  for (int ip = 0; ip < 8; ip++)
  {
    Serial.print (dataSensor [ip]);
    Serial.print (" ");
  }
  Serial.println ();
}

