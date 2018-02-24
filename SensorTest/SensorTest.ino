int pinSensor [8];//Array that holds pinset
byte lData;//Last cicle data readed
byte aData;//This cicle data readed

void setup()
{
  Serial.begin (2000000);//Begin serial communication
  Serial.println ("inicio");

  for (int i = 0; i < 8; i++)//fancy way to set all pins as INPUT
  {
    pinSensor [i] = i + 4;
    pinMode (pinSensor [i], INPUT);
  }


}

void loop() 
{
  lData = aData;
  readAll ();
//  Serial.print (aData);
//  Serial.print (" ");
//  Serial.println (lData);
  
  if (aData != lData && aData != 255)
  {
    Serial.println (aData,DEC);
  }
  //delay (250);
}

void readAll ()
{
  for (int ir = 0; ir < 8; ir++)
  {
    bitWrite (aData, ir, digitalRead (pinSensor [ir]));
  }
}
