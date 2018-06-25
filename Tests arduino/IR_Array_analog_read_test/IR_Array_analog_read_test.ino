int bData [8] = {};

void setup() 
{
  Serial.begin (2000000);
  Serial.println ("Inicio");
  delay (1000);
  
  digitalWrite (14, HIGH);
  digitalWrite (15, HIGH);
  digitalWrite (16, HIGH);
  digitalWrite (17, HIGH);
  digitalWrite (18, HIGH);
  digitalWrite (19, HIGH);
  digitalWrite (20, HIGH);
  digitalWrite (21, HIGH);
  // put your setup code here, to run once:

}

void loop() 
{
  bData [0] = analogRead (A0);//Read all sensors
  bData [1] = analogRead (A1);
  bData [2] = analogRead (A2);
  bData [3] = analogRead (A3);
  bData [4] = analogRead (A4);
  bData [5] = analogRead (A5);
  bData [6] = analogRead (A6);
  bData [7] = analogRead (A7);

  for (int i = 0; i < 8; i++)
  {
    Serial.print (bData [i]);
    Serial.print (" ");
  }
  Serial.println ();

  delay (50);

}
