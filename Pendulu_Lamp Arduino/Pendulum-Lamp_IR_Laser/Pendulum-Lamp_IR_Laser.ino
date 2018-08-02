   /*
   Iván Abreu Studio.

   13/3/2018

   The point of this program is to keep a pendulum lamp moving.

   To get that, we read a sensor array and pull to the oposite side
   of the array. The array detects the lamp wire, ergo, pendulum positon.

   The max aplitude has to be sustanied. The pendular movement shall no
   stop, no mather what.

   Other goals of future versions:
    -Feed of historic earthquakes behaviour
    -Bluetooth configuration
    -Zombie mode
    -Fine slow motion

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
   V5.0.1 New direction checker
   V5.0.2 New direction toogle function
   V5.1 Asynchronous ignition
   V5.2 Target position philosophy added
   V5.3 Sensor lecture starts with ignition sequence
   V5.4 16 samples saved
   V5.4.1 Dinamic theshold sequence
   V5.4.2 Dinamic discriminator.
   V5.4.3 Dinamic detected value adder
   V5.4.4 Non detec average value
   V5.4.5 Detect value average
   V5.4.6 Mid range dinamic protoChange
   V5.4.7 Continuos average ignition readings
   V5.4.8 Average readengs begin befor ignition
   V5.4.9 Reliable ignition sequence, average based, detect readings fedback
   V5.5 Motor drive continuos form added. First light changin stable version achieved
   V5.6 Poke sequence prevents stop at missreadng
   

   Team:

   Iván Abreu Ochoa
   Malitzin Cortez
   Beto Olguin
   Hugo Vargas
*/

#include <Servo.h>

Servo pendulum;

const byte IGND = 18;
const byte CENTERPOSITION = 90;
const byte MAXD = 80;
const byte MIND = 10;
const float MINRICHTER = 50;
const float MAXRICHTER = 85;
const byte MINFRONT = CENTERPOSITION + MIND;
const byte MAXFRONT = CENTERPOSITION + MAXD;
const byte MINBACK = CENTERPOSITION - MIND;
const byte MAXBACK = CENTERPOSITION - MAXD;
const int MINTRAVELTIME = 750;
const int MAXTRAVELTIME = 1500;
const byte NSENSORS = 8;
const int PROTOTH = 550;
const byte LENGTHC1 = 16;

byte richter = 8.4;
byte positionB, positionF;
bool lampDirection = 0;
byte targetPosition;
byte kicks = 0;
int mData;
bool lLampDirection, changeDirection;
byte diferentialThreshold = 100;

volatile int bData [NSENSORS] = {};
byte aData, lData;

volatile double timeNow;
volatile int travelTime;
volatile double targetTime;

volatile int c1 [NSENSORS][LENGTHC1] = {};
byte i_min_x [NSENSORS] = {};
volatile int c2 [NSENSORS][LENGTHC1] = {};
volatile int dinamicThreshold [NSENSORS]= {};
volatile int avgArray [NSENSORS][2] = {};

void setup() 
{
  Serial.begin (2000000);
  Serial.println ();
  Serial.println ("Inicio");

  pendulum.attach (3);

  ignition ();

}

void loop() 
{
  readAll ();
  protoChange ();
  checkDirection ();
  checkChangeDirection ();
  motorDrive ();
  poke ();
  listenPort ();

}
