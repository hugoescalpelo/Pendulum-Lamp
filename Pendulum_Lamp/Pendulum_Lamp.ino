/*
   Iván Abreu Studio.

   19/2/2018

   The point of this program is to keep a pendulum lamp moving.

   To get that we read a sensor array and pull to the oposite side
   of the array. The array detects the lamp wire, ergo, pendulum positon.

   The max aplitud has to be sustanied.

   Other goals of future versions:
    -Manual control of earthquake intensity
    -Feed of historic earthquakes behaviour

   V1. Micro servo
   V2. Solenoid
   V3. Micro reducer
   V4. Mid Servo
   V4.1. Sensor Array

   Team:

   Iván Abreu Ochoa
   Malitzin Cortez
   Beto Olguin
   Hugo Vargas
*/

//Libraries
#include <Servo.h>//Manage servos

//Objects
Servo myServo;//A servo object to manage our servo

//Variables
int pinSensor [8];//Array that holds pinset
byte lData;//Last cicle data readed
byte aData;//This cicle data readed
int pos_bin;//Binary position
int pos_indx;//decimal position


//Setup
void setup ()
{
  Serial.begin (115200);//Begin serial communication
  Serial.println ("inicio");
  myServo.attach (3);//Begin servo at pin 3

  for (int i = 0; i < 8; i++)//fancy way to set all pins as INPUT
  {
    pinSensor [i] = i + 4;
    pinMode (pinSensor [i], INPUT);
  }

  //First call. Test the lecture
  readAll ();
  printAllSensors ();
}

void loop ()
{
  if (lData != aData)
  {
    pos_bin = lowByte (aData);
    pos_indx = getPosition (pos_bin);
    Serial.print ("l= ");
    Serial.print (pos_bin);
    Serial.print (" p= ");
    Serial.println (pos_indx);
    lData = aData;//Sets a trace of readings
  }
  readAll ();
  aData = ~aData;
  printAllSensors ();
  delay (100);
}

