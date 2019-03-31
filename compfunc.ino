
#include "QSerial.h"
int linecounter=0;


//function file for competition

//pushbutton is no longer expected to be used
/*int pushbutton(int pushpin){// input the pushpin
  int val =0, sw=0;
  while(1){
  val = digitalRead(pushpin);    //push button for starting
  if (val == HIGH){}           // button is released
  else{
    delay(1000);
    if(val == LOW){             // button is pressed
      sw = sw+1;  // increment of sw when the button is pressed and released
      }
    }
  }
  return sw;
}*/



//-------------------------------------------------------------------------------------------------------------------------------------------------
int receiver(QSerial myIRS){
  int val = myIRS.receive(200);
  delay(100);
  if(val== 0 ){
  return val;
  }
}
//----------------------------------------------------------------------------------------------------------------------
/*int countEncoderLEFT(){// input the revolution counter pin and reutn how much 60 degrees has been experienced
  int store = 0;
  int rev1 = digitalRead(WheelEncoderLeftpin);
  if (rev1==HIGH){
    store = store+1;
    while(rev1==HIGH){
   rev1 = digitalRead(WheelEncoderLeftpin);}
  }
  return ;
}

int countEncoderRIGHT(){// input the revolution counter pin and reutn how much 60 degrees has been experienced
  int store = 0;
  int rev1 = digitalRead(WheelEncoderRightpin);
  if (rev1==HIGH){
    store = store+1;
    while(rev1==HIGH){
   rev1 = digitalRead(WheelEncoderRightpin);}
  }
  return ;
}
*/
//-----------------------------------------------------------------------------------------------------------------------
int IRReading(int ir){
  int readval=analogRead(ir);
  return readval;
}

//-------------------------------------------------------
void forward(int targetspeed){//input the pin for motor direction, speed etc pins)
      digitalWrite (RDirection, LOW);//left wheel direction
      analogWrite (RSpeed, targetspeed);//left wheel speed
      digitalWrite (LDirection, HIGH);//right wheel direction 
      analogWrite (LSpeed, targetspeed);//right wheel speed
      return;//           THIS IS UNIQUE TO OUR ROBOT, PLS DONT COPY DIRECTLY
      
}
void reverse(int targetspeed){//input the pin for motor direction, speed etc pins)
      digitalWrite (RDirection, HIGH);//left wheel direction backword
      analogWrite (RSpeed, targetspeed);//left wheel speed
      digitalWrite (LDirection, LOW);//right wheel direction backward 
      analogWrite (LSpeed, targetspeed);//right wheel speed
      return;//           THIS IS UNIQUE TO OUR ROBOT, PLS DONT COPY DIRECTLY
}

void palse(){
     int left_speed =0, right_speed = 0;
      forward(0);
    delay(1000);
    return;
}

//----------------------------turnaround codes-------
void turnAround(int currentSpeed){
  reverse(100);
  delay(800);
  stationaryturn(true, currentSpeed);
  delay(1000);
  int centerSensorValue;
    do{ centerSensorValue = analogRead(MIRpin);
        stationaryturn(true, currentSpeed);
    }while(centerSensorValue<BlackTHRESH);
    return;
}

//-------------------------------------------------
int isBluetooth(){
  Serial.begin(115200);
  int checkAvailable = Serial.available();
  int checkRead = Serial.read();
  Serial.begin(9600);
  return checkRead;
}
//---------------------------------rrcode-----------------

void followLine(int currentSpeed, int intersectThresh, boolean dir) {

  // Get the sensor readings
  int leftSensorValue = analogRead(LIRpin);
  int centerSensorValue = analogRead(MIRpin);
  int rightSensorValue = analogRead(RIRpin);
  testing( centerSensorValue, leftSensorValue, rightSensorValue);

  // If only the middle sensor is over the line, drive forward
  if (centerSensorValue >= BlackTHRESH && leftSensorValue < BlackTHRESH && rightSensorValue < BlackTHRESH) { //forward
    forward(currentSpeed);
  } 

  // If the right sensor is over the line, turn right
 else if (leftSensorValue < BlackTHRESH && rightSensorValue >= BlackTHRESH) {
    turn(true, currentSpeed, false); //RIGHT means 1 LEFT means 0
  }

  // If the left sensor is over the line, turn left
  else if (leftSensorValue >= BlackTHRESH && rightSensorValue < BlackTHRESH) {
    turn(false, currentSpeed, false);
  }
  else if (centerSensorValue >= BlackTHRESH && leftSensorValue >= BlackTHRESH && rightSensorValue >= BlackTHRESH){
//    delay(500);
//      leftSensorValue = analogRead(LIRpin);
//      centerSensorValue = analogRead(MIRpin);
//      rightSensorValue = analogRead(RIRpin);
 
//      testing( centerSensorValue, leftSensorValue, rightSensorValue);
//    if (centerSensorValue >= BlackTHRESH && leftSensorValue >= BlackTHRESH && rightSensorValue >= BlackTHRESH){// double if to prevent miss recognition
           Serial.println("Intersection recognized");
   intersect( intersectThresh, dir, currentSpeed);
   return;
//    }else{
 //     return;
//    }
 }
 Serial.print("linecounter                     ");
 Serial.println(linecounter);
  return;
  }

//-------------------------intersection------------------------ 
void intersect( int intersectThresh , boolean dir, int currentSpeed){
  linecounter = linecounter +1;
  int leftSensorValue = analogRead(LIRpin);
  int centerSensorValue = analogRead(MIRpin);
  int rightSensorValue = analogRead(RIRpin);
  while(1){  
    forward(currentSpeed);
   leftSensorValue = analogRead(LIRpin);
   centerSensorValue = analogRead(MIRpin);
   rightSensorValue = analogRead(RIRpin);
  testing( centerSensorValue, leftSensorValue, rightSensorValue);
  if(leftSensorValue <BlackTHRESH || centerSensorValue<BlackTHRESH || rightSensorValue<BlackTHRESH){
    break;
  }
  Serial.print("in the intersection checking loop");
  }
  if (linecounter >=intersectThresh){
    Serial.println("time to turn");
            turn(dir, currentSpeed, true);
            delay(500);
    do{ centerSensorValue = analogRead(MIRpin);
        testing( centerSensorValue, leftSensorValue, rightSensorValue);
        turn(dir, currentSpeed, true);
    }while(centerSensorValue<BlackTHRESH);

  }
    return;

}

// ---------------------------------------------


void turn(boolean dir, int Speed, boolean aggressive) {

  // Set the motors to go forward
      forward(Speed);

  // If turning right is true
  if (dir) {
    analogWrite(RSpeed, aggressive ? (Speed / 10) : (Speed / 2));
    analogWrite(LSpeed, Speed);
  }

  // turning left is false
  else {
    analogWrite(RSpeed, Speed);
    analogWrite(LSpeed, aggressive ? (Speed / 10) : (Speed / 2));
  }
return;
}

//-------------------------------------------

void stationaryturn(boolean dir, int Speed) {

  // Set the motors to go forward
      forward(Speed);

  // If turning right is true
  if (dir) {
      digitalWrite (RDirection, LOW);//left wheel direction
      digitalWrite (LDirection, LOW);//right wheel direction 
    analogWrite(RSpeed, Speed);
    analogWrite(LSpeed, Speed);
  }

  // turning left is false
  else {
    digitalWrite (RDirection, HIGH);//left wheel direction
    digitalWrite (LDirection, HIGH);//right wheel direction 
    analogWrite(RSpeed, Speed);
    analogWrite(LSpeed, Speed);
  }
return;
}

//---------------------------bumper codes---------------
int bumper(){ //--------bumper shows 1 when clicked, shows 0 when released
  int bumperLeftStatus= digitalRead(bumperpinleft);
  int bumperRightStatus= digitalRead(bumperpinright);
 if(!bumperLeftStatus || !bumperRightStatus) {
  return 1;
 }else{
  return 0;
 }

}



//------------------------------void testing
void testing(int centerSensorValue, int leftSensorValue, int rightSensorValue){
    Serial.print("center         ");
  Serial.println(centerSensorValue);
    Serial.print("left         ");
    Serial.println(leftSensorValue);
      Serial.print("right         ");
      Serial.println(rightSensorValue);
      return;
}
//-----------------------------------------------------WALL AND GRIPPING DETECTION----------------------------------

void wallinfront(){
  if(bumper()){
    BallCatching();
  }
  return;
}

void homeinfront(){
  if(bumper()){
    BallDropping();
  }
  return;
}

//-----------------------------------------------------gripper---------

int grabbing(){
  int GripSense = analogRead(GripSensorpin);
  int graforce=10;
  while(GripSense>240){
    Gripper.write(graforce++);
    GripSense=analogRead(GripSensorpin);
    delay(20);
    Serial.println(GripSense);
  }
  Serial.println("grabbbbbed");
  return 1;
}

void BallCatching(){
  Serial.println("ball catching");
  Elevator.write(90);
  Gripper.write(10);
  if(grabbing()){
    Elevator.write(180);
  }
  return;
}

void BallDropping(){
  Serial.println("ball dropping");
  Elevator.write(90);
  delay(1000);
  Gripper.write(10);
  Serial.println("dropped");
}

//-------------------------------gripper initializing-----------------------------------------
void initializing(){
  Elevator.write(180);
  Gripper.write(10);
  return;
}
