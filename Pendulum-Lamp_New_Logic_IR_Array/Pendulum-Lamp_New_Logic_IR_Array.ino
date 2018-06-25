/*
   Iván Abreu Studio.

   22/5/2018

   The point of this program is to keep a pendulum lamp moving.

   To get that, we read a sensor array to know where the lamps' wire
   is and then its pulled to the oposite side to keep it moving

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
   V6 Logic changed to work with IR sensor again, like version 4.4

   Notes:
   Constants: UPPER_SNAKE_CASE
   variables: camelCase
   Functions: camelCase
   index: snake_case

   Team:

   Iván Abreu Ochoa
   Malitzin Cortez
   Beto Olguin
   Hugo Vargas
*/

//Libraries
#include <Servo.h>

//Objects
Servo pendulum;

//Constants
const byte SERVO_PIN = 3;
const int MIN_RICHTER = 50;//In a tenth factor, to avoid write float map
const int MAX_RICHTER = 85;
const int FRONT_EXTENSION = 180;
const int BACK_EXTENSION = 0;
const int CENTER_POSITION = ((FRONT_EXTENSION - BACK_EXTENSION) / 2) + BACK_EXTENSION;
const int CENTER_GAP = 10;
const int OUTER_GAP = 10;
const int MIN_FRONT = CENTER_POSITION + CENTER_GAP;
const int MAX_FRONT = FRONT_EXTENSION - OUTER_GAP;
const int MIN_BACK = CENTER_POSITION - CENTER_GAP;
const int MAX_BACK = BACK_EXTENSION + OUTER_GAP;
const byte LENGHT_SMOOTH = 16;
const byte NSENSORS = 8;

//Variables
int richter = 84;//Start intensity, drives ignition
int positionBack, positionFront;
bool sensorData [] = {0,0,0,0,0,0,0,0};

void setup() 
{
  Serial.begin (2000000);//Highest speed selected, so debug doesnt interfere with operation
  Serial.println ();
  Serial.println("Inicio");
  
  pendulum.attach (SERVO_PIN);//Begin servo

  for (byte set_pins = 0; set_pins < NSENSORS; set_pins++)
  {
    pinMode (set_pins + 4, INPUT);
  }

  ignition ();//This function handles the startup and first readings

}

void loop() {
  // put your main code here, to run repeatedly:

}
