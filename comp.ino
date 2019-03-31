
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
//------------------------------------------------------wheel encoders---------------------------------------
#define WheelEncoderLeftpin 12
#define WheelEncoderRightpin 13


//---------------------------------------------------pressure sensor definition------------------------------------
#define prespin 9

//---------------------------------------Bumper codes--------------
#define bumperpinleft 13
#define bumperpinright 5


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
  pinMode (WheelEncoderLeftpin, INPUT);  
  pinMode (WheelEncoderRightpin, INPUT); 
  pinMode (bumperpinleft, INPUT);
  pinMode (bumperpinright, INPUT);
}

void loop() {
 // put your main code here, to run repeatedly:
// Serial.print(bumper());


//  turn(true, 100, true);
    followLine(120, 2, false);
    if(bumper()){
      turnAround(120);
    }
//  forward(100);


}
