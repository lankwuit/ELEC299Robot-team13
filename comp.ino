#include <Servo.h>
#include "QSerial.h"


//----------------------------------
#define rxpin 5    //where the initial IR sensor is connected to 开始位置定义的红接pin
#define txpin -1

//------------------------------above IR pins definition--------------

//#define pushpin // this may not even be necessary

//-----------------------------------------------BLCKLINE threshold definition------
#define BlackTHRESH 700

//-----------------------------------------motor phase
#define RDirection 7  // RIGHT MOTOR DIRECTION
#define RSpeed 6 // RIGHT MOTOR SPEED
#define LDirection 2 // LEFT MOTOR DIRECTION
#define LSpeed 3 // LEFT MOTOR SPEED

//------------------------------------------define line tracking IR pin settings--------------------------------------------------------------

#define LIRpin A0  //LEFT PIN FOR DETECTING BLACKLINE
#define MIRpin A2
#define RIRpin A1



//---------------------------------------------------pressure sensor definition------------------------------------
#define prespin 9

//---------------------------------------Bumper codes--------------
#define bumperpinleft 13
#define bumperpinright 5
//--------------------------------------------------Grippercodes
#define GripSensorpin A3
#define Elevatorpin 10
#define Gripperpin 11
#define HorizontalDrpin 8



Servo Elevator, Gripper, HorizontalDr;
QSerial myIRS;

void setup() {
//----------------------------------Serial begin for preseted 9600 refresh rate--------------------
  Serial.begin(9600);

  myIRS.attach(rxpin ,txpin);// attaching pins for receiving IR


//--------------------------------------pin definition for all the motors----------
  pinMode(RSpeed, OUTPUT);
  pinMode(LSpeed, OUTPUT);
  pinMode(RDirection, OUTPUT);
  pinMode(LDirection, OUTPUT); 
//---------------------------------wheel encoder codes
//  pinMode (WheelEncoderLeftpin, INPUT);  
// pinMode (WheelEncoderRightpin, INPUT); 
  pinMode (bumperpinleft, INPUT);
  pinMode (bumperpinright, INPUT);
  Elevator.attach(Elevatorpin);//myservo1 is for Elevator
  Gripper.attach(Gripperpin);// myservo2 is for Gripper
  HorizontalDr.attach(HorizontalDrpin);// Horizontal Dr is for the horizontal drive
}

void loop() {
 // put your main code here, to run repeatedly:
// Serial.print(bumper());
initializing();
// position1(160);
  firstBall(140);
  secondBall(140);
//Adjustment();
//homeinfront();
//grabbing();
//initializing();
//wallinfront();
//int    GripSense=analogRead(GripSensorpin);

//    Serial.println(GripSense);

//  turn(true, 100, true);
//    followLine(120, 2, false);
//    if(bumper()){
//      turnAround(120);
//    }
//  forward(100);


}
