void ignition ()
{
  adjustRichter (richter);
  setServo ();
}

void setServo ()
{
  
  for (byte r = 0; r < LENGHT_SMOOTH; r++)//r stands for read
  {
    readAll ();
    add ();
  }
}

