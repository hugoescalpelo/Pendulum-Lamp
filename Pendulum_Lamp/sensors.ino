void readAll ()
{
  for (int ir = 0; ir < NLASERS; ir++)
  {
    if (aData [ir] < threshold)
    {
      bitClear (dData, ir);
    }
    else
    {
      bitSet (dData, ir);
    }
  }
}

