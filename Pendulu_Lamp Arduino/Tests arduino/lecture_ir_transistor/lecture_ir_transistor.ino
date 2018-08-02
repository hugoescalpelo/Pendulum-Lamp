int lecture [8];

void setup() {
  pinMode (9, OUTPUT);
  Serial.begin (2000000);
  digitalWrite (9, HIGH);
  // put your setup code here, to run once:

}

void loop() {
  for (int i = 0; i < 8; i++) {
    lecture [i] = analogRead (i + 14);
  }

  for (int j = 0; j < 8; j++) {
    Serial.print (lecture [j]);
    Serial.print (" ");
  }
  Serial.println ();
  delay (100);
  // put your main code here, to run repeatedly:

}
