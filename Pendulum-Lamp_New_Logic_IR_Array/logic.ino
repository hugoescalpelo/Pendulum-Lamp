void adjustRichter (float rch)
{
  positionBack = map (rch, MIN_RICHTER, MAX_RICHTER, MIN_FRONT, MAX_FRONT);
  positionFront = map (rch, MIN_RICHTER, MAX_RICHTER, MIN_BACK, MAX_BACK);
}

void add ()
{
  //
}

