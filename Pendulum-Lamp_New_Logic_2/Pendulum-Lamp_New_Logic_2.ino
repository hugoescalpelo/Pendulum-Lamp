#include <Servo.h>

Servo pendulum;

const byte IGND = 15;
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
const byte LENGHTC1 = 16;

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

int travelTime;

volatile double timeNow;
volatile double targetTime;

volatile int c1 [NSENSORS][LENGHTC1] = {};
byte i_min_x [NSENSORS] = {};
volatile int c2 [NSENSORS][LENGHTC1] = {};
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
  listenPort ();

}
