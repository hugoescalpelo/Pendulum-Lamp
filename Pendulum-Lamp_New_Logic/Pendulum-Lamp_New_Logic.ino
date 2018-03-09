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
   V5.0 Logic correction to asyncronous movement

   Team:

   Iván Abreu Ochoa
   Malitzin Cortez
   Beto Olguin
   Hugo Vargas
*/

//Libraries
#include <Servo.h>//Handle servos

//Objects
Servo pendulum;//Represents the pendulum servo

//Constants
const byte NLASERS = 8;//Number of laser sensors
const byte KICKNITION = 15;//Number of ignition kicks
const byte SERVOCENTER = 90;//Centered servo position in degrees
const bool IGND = 0;//Ignition drive for movement descriptor function
const bool WRKD = 1;//Working drive for movement descriptor function
const byte LPROMEDIER = 16;
const byte MINRICHTER = 5.0;
const byte MAXRICHTER = 8.5;
const byte MINEXTENSION = 20;
const byte MAXEXTENSION = 70;
const int MINTRAVELTIME = 300;
const int MAXTRAVELTIME = 1200;

//Variables
int bData [NLASERS] = {};
byte aData;
byte lData;

int protoThreshold [NLASERS] = {};
int threshold [NLASERS] = {};
int protoTh = 400;
int promedierArray [NLASERS][LPROMEDIER] = {};
byte thRange = 10;
int thresholdArray [NLASERS][LPROMEDIER] = {};
int avg [NLASERS][2] = {};//0 off, 1 on

float richterDegrees = 7.5;
byte extensionF, extensionB;
byte movementLength;
bool servoDirection = 0;
byte dinamicPosition;
bool wFlag = 0;
bool lServoDirection = 0;
bool directionChanged = 0;

double timeLast, timeNow, targetTime;
int travelTime;


bool reached = 1;//Tells if servo has reached its target position. Initializes at 1 in order to be able to run ignition sequence

void setup() 
{
  Serial.begin (20000000);
  Serial.println ("Inicio");

  ignition (KICKNITION, richterDegrees);//Generates an initial suitable movement and set on/off values

  timeLast = millis ();
}

void loop() 
{
  readAll ();//Read all sensors
  movementDescriptor (richterDegrees, WRKD);//Determine movement type
  motorRender ();//Writes an asynchronous continuum soft transition or fast jump to de servo
  motorWatchdog ();//Prevents pendulum movement from breaking at low richterDegrees
  listenPort ();//Listens serial monitor and BT communication
}
