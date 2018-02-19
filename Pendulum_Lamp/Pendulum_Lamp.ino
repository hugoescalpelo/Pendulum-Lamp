/*
 * Iván Abreu Studio.
 * 
 * 19/2/2018
 * 
 * The point of this program is to keep a pendulum lamp moving.
 * 
 * To get that we read a sensor array and pull to the oposite side
 * of the array. The array detects the lamp wire, ergo, pendulum positon.
 * 
 * The max aplitud has to be sustanied.
 * 
 * Other goals of future versions:
 *  -Manual control of earthquake intensity
 *  -Feed of historic earthquakes behaviour
 * 
 * V1. Micro servo
 * V2. Solenoid
 * V3. Micro reducer
 * V4. Mid Servo
 * V4.1. Sensor Array
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
Servo myServo;

 //Variables
 int pinSensor [8];
 volatile int dataSensor [8];


 //Setup
 void setup ()
 {
  Serial.begin (115200);
  Serial.println ("inicio");
  //pinset
  //myServo.attach (3);

  for (int i = 4; i <= 11; i++)
  {
    pinSensor [i - 4] = i;
    pinMode (pinSensor [i - 4], INPUT);
  }
  readAll ();
  printAllSensors ();
 }

void loop ()
{
  delay (10);
  readAll ();
  printAllSensors ();
}

