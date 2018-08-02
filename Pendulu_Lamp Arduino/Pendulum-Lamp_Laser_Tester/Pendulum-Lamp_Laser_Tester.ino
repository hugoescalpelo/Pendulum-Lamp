const int c = 8;
int aData [c];
byte dData;
byte lData;
byte bData;
int th = 200;
void setup()
{
  Serial.begin (2000000);//Begin serial communication
  Serial.println ("inicio");
}

void loop ()
{
  lData = dData;
  aData [0] = analogRead (A0);
  aData [1] = analogRead (A1);
  aData [2] = analogRead (A2);
  aData [3] = analogRead (A3);
  aData [4] = analogRead (A4);
  aData [5] = analogRead (A5);
  aData [6] = analogRead (A6);
  aData [7] = analogRead (A7);

  for (int ir = 0; ir < c; ir ++)
  {
    //Serial.print (aData [ir]);
    //Serial.print (" ");
    if (aData [ir] < th)
    {
      bitClear (dData, ir);
    }
    else
    {
      bitSet (dData, ir);
    }
  }
  //Serial.println ();

  if (lData != dData && dData != 255)
  {
    
    Serial.print (dData, BIN);
    Serial.print (" ");
    Serial.print (dData);
    Serial.print (" ");
    if (bData < dData)
    {
      Serial.print ("der");
    }
    else
    {
      Serial.print ("izq");
    }
    Serial.println ();
    bData = dData;
  }



}
