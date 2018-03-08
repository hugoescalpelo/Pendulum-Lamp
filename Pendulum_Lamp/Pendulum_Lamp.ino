/*
   Iván Abreu Studio.

   6/3/2018

   The point of this program is to keep a pendulum lamp moving.

   To get that we read a sensor array and pull to the oposite side
   of the array. The array detects the lamp wire, ergo, pendulum positon.

   The max aplitud has to be sustanied.

   Other goals of future versions:
    -Feed of historic earthquakes behaviour
    -Contextual auto threshold sequence

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
   V4.4.3 Manual control of earthcuake intensity
   V4.5 Laser sensor array

   Team:

   Iván Abreu Ochoa
   Malitzin Cortez
   Beto Olguin
   Hugo Vargas
*/

//Libraries
//#include <Servo.h>//Manage servos

//Objects
//Servo myServo;//A servo object to manage our servo

//Constants
//const byte NLASERS = 8;
//const byte LPRMDR = 16;
const byte NIMPULSES = 5;

//Variables
byte pinSensor [NLASERS];//Array that holds pinset
byte lData;//Last cicle data readed
//byte aData;//This cicle data readed
//int bData [NLASERS];//Buffer data
int pos_bin;//Binary position
int pos_indx;//decimal position
int last_pos_indx;
int last_pos_bin;

//int threshold [NLASERS] = {};//Threshold value for detecting pendulum wire shadow
byte th_range = 10;//Threshold range, because of the noise
byte sampling = 20;//Sampling time for sensor read
int prmdr [NLASERS][LPRMDR] = {};//Promedier memory cache
int avg [NLASERS][2] = {};//An arral NLASERS longitud for every sensor and for on/off values
int dPrmdr [NLASERS][LPRMDR] = {};//Detect memory cache

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
  //Serial.begin (2000000);//Begin serial communication
  //Serial.println ("Inicio");

  myServo.attach (3);//Begin servo at pin 3

  //First call. Test the lecture
  readAll ();
  //printAllSensors ();

  //Ignition sequence
//  Serial.println ("Ignition sequence");
//  ignitionSequence (NIMPULSES);//The parameter sets the number of impuses
//  Serial.println ("Done");
  
  //thresholdPromedierInitializer;
  
  timeNow = millis ();
}

void loop ()
{
  //readAll ();
  aData = ~aData;//All bits inverted in order to detect the wire via lowByte

  if (lData != aData && aData != 0)//Whenever a change is detected and that changes isn't the inbetween position of the wire
  {
    last_pos_bin = pos_bin;//Historic, needed to tell the direction of the wire
    last_pos_indx = pos_indx;//We need to save this before get a new position and index
    pos_bin = lowByte (aData);//Returns the lowest set byte
    pos_indx = getPosition (pos_bin);//I worte this funny switch-case function to return the decimal position of pos_bin. I know there are fancier ways to do this, but couldnt find'em quick

    
    //This is the working soul of the code. Below is the code that gives stability to the readings and the one that I want to run only when detecting changes
    
    //addPromedier (ir, bData [ir]);
    trimAndAvg ();//Cuts detected value, max and min values from the promedier, then calculate the average value.

    printBinaries ();
    printAllSensors ();
  }

  impulse (intensity);//Impulse in 'intensity' proportion as sensor detects. This moves the servo

  //Here it can be added an asynchronous sequence to update de angle of the servos
  //as function of intensity.
  //An index of degrees to go and target degrees could do the thing

  timeNow = millis ();
  //takeMeOut ();
  if (last_pos_indx != pos_indx);//Keep track of stuck time
  {
    timeLast = timeNow;
  }

  lData = aData;//Sets a trace of readings

  //listenPort ();
}

