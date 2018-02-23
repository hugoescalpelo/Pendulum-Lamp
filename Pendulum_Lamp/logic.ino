void refreshRichter (float r)
{
  int rr = r * 10;
  
  r_wait = map (rr, min_r, max_r, rWaitMax, rWaitMin);
  
  angle_a = map (rr, min_r, max_r, min_a, max_a);
  angle_b = map (rr, min_r, max_r, min_b, max_b);
}

