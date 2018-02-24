/*
   Iván Abreu Studio.

   23/2/2018

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
   v4.4.1 Added proportional servo movement
   V4.4.2 Fix to takeMeOut sequence

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
int last_pos_indx;
int last_pos_bin;

int angle_a = 40; //Ignition angle by right
int max_a = 20;//Limits
int min_a = 75;

int angle_b = 140;//Ingnition angle by left
int max_b = 160;//Limits
int min_b = 115;

int angle = angle_a;//First asociation

float intensity = 8.5;//5.5 to 8.7 richter degree
float min_r = 55;//Limits
float max_r = 87;

bool polar = 0;//0 right, 1 left. Indicates whic side the wire is

int rWaitMax = 220;//Wait before move servo
int rWaitMin = 10;
int r_wait;

double timeLast, timeNow;//Time tracking variables

//Setup
void setup ()
{
  Serial.begin (2000000);//Begin serial communication
  Serial.println ("inicio");

  myServo.attach (3);//Begin servo at pin 3

  for (int i = 0; i < 8; i++)//fancy way to set all pins as INPUT
  {
    pinSensor [i] = i + 4;
    pinMode (pinSensor [i], INPUT);
  }

  //First call. Test the lecture
  readAll ();
  //printAllSensors ();

  //Ignition sequence
  myServo.write (90);
  delay (2000);
  startEngine ();
  timeNow = millis ();
}

void loop ()
{

  readAll ();
  aData = ~aData;//Not to all bits

  if (lData != aData && aData != 0)
  {
    last_pos_bin = pos_bin;
    last_pos_indx = pos_indx;
    pos_bin = lowByte (aData);
    pos_indx = getPosition (pos_bin);

    //printBinaries ();
    //printAllSensors ();

    impulse (intensity);//Impulse in 'intensity' proportion assensor detects
  }

  //Here it can be added an asynchronous sequence to update de angle of the servos
  //as function of intensity.
  //An index of degrees to go and target degrees could do the thing

  timeNow = millis ();
  takeMeOut ();
  if (last_pos_indx != pos_indx);//Keep track of stuck time
  {
    timeLast = timeNow;
  }

  lData = aData;//Sets a trace of readings

  listenPort ();
  //delay (100);
}

