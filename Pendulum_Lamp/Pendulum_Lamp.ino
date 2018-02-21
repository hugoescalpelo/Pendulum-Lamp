/*
   Iván Abreu Studio.

   20/2/2018

   The point of this program is to keep a pendulum lamp moving.

   To get that we read a sensor array and pull to the oposite side
   of the array. The array detects the lamp wire, ergo, pendulum positon.

   The max aplitud has to be sustanied.

   Other goals of future versions:
    -Manual control of earthquake intensity
    -Feed of historic earthquakes behaviour

   ChangeLog
   V1. Micro servo
   V2. Solenoid
   V3. Micro reducer
   V4. Mid Servo
   V4.1. Sensor Array
   V4.2. Binary lecture
   V4.3. Servo sync
   V4.4. Succesful auto sync

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

const int angle_a = 40;
const int angle_b = 140;
int angle = angle_a;
char intensity = 8.1;
bool polar = 0;//0 right, 1 left

//double timeLast, timeNow;

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

  //First impulse
  myServo.write (90);
  delay (2000);
  startEngine ();
  //timeNow = millis ();
}

void loop ()
{
  if (lData != aData && aData != 0)
  {
    pos_bin = lowByte (aData);
    pos_indx = getPosition (pos_bin);

    printBinaries ();
    //printAllSensors ();

    impulse (intensity);//Impulse in 'intensity' proportion assensor detects

    
    //timeLast = timeNow;
  }
  readAll ();
  lData = aData;//Sets a trace of readings
  aData = ~aData;
  //timeNow = millis ();
  //takeMeOut ();
  
  //delay (100);
}

