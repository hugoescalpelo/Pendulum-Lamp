/*
 * Iván Abreu Studio.
 * 
 * 12/2/2018
 * 
 * The point of this program is to keep a pendulum moving.
 * 
 * To get that, is needed to begin the movement to a big amplitude
 * The increase of amplitude has to be gradual.
 * 
 * Then, when max amplitude is reached, the period of the pendulum
 * is changed by a sinusoidal factor.
 * 
 * Team:
 * 
 * Iván Abreu Ochoa
 * Malitzin Cortez
 * Beto Olguin
 * Hugo Vargas
 */

 //Libraries
 #include <Servo.h>

 //Objects
 Servo myservo;

 //Variables
 int pos = 0;
 int posA = 150;
 int posB = 30;

 long timeNow = 0;
 long timeLast = millis ();
 int timeStep = 1000;
 int threshold = 850;
 int cutStageZero = 10;

 bool pingPong = 0;
 byte stage = 0;

 float angle = 0.5;
 int adrf = 30; //Stands for anti destructive resonace factor

void setup() {

  //Servo initializer
  myservo.attach (9);

  Serial.begin (115200);

}

void loop() {
  timeNow = millis ();
  if (timeNow - timeLast >= timeStep){
    if (pingPong == 0){
      myservo.write (posA);
      pingPong = 1;
      timeLast = timeNow;
    }
    else{
      myservo.write (posB);
      pingPong = 0;
      timeLast = timeNow;
    }
    if (stage == 0){
      if (timeStep > threshold){
        timeStep -= cutStageZero;
      }
      else{
        stage = 1;
      }
    }
    else{
      timeStep = timeStep + (adrf* cos (angle));
      angle += 0.5;
    }
    Serial.println (timeStep);
  }
}
