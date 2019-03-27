
#include "QSerial.h"




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
  Serial.println("error");
  }else{
  Serial.println((char)val);
  return val;
  }
}
//----------------------------------------------------------------------------------------------------------------------
int countEncoderLEFT(){// input the revolution counter pin and reutn how much 60 degrees has been experienced
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

//-----------------------------------------------------------------------------------------------------------------------
int IRblackReading(int ir){
  int readval=analogRead(ir);
  return readval;
}

//-------------------------------------------------------
void forward(int targetspeed){//input the pin for motor direction, speed etc pins)
      digitalWrite (RDirection, HIGH);//left wheel direction
      analogWrite (RSpeed, targetspeed);//left wheel speed
      digitalWrite (LDirection, HIGH);//right wheel direction
      analogWrite (LSpeed, targetspeed);//right wheel speed
      return;
}
void palse(){
     int left_speed =0, right_speed = 0;
      forward(0);
    delay(1000);
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

void followLine(int currentSpeed, boolean aggressive) {

  // Get the sensor readings
  int leftSensorValue = analogRead(LIRpin);
  int centerSensorValue = analogRead(MIRpin);
  int rightSensorValue = analogRead(RIRpin);
  Serial.print("left");
  Serial.println(leftSensorValue);
  Serial.print("middle");
  Serial.println(centerSensorValue);
    Serial.print("right");
  Serial.println(rightSensorValue);

  // If only the middle sensor is over the line, drive forward
  if (centerSensorValue >= BlackTHRESH && leftSensorValue < BlackTHRESH && rightSensorValue < BlackTHRESH) { //forward
    forward(currentSpeed);

  }

  // If the right sensor is over the line, turn right
  if (leftSensorValue < BlackTHRESH && rightSensorValue >= BlackTHRESH) {
    turn(true, currentSpeed, aggressive); //RIGHT means 1 LEFT means 0

  }

  // If the left sensor is over the line, turn left
  else if (leftSensorValue >= BlackTHRESH && rightSensorValue < BlackTHRESH) {
    turn(!true, currentSpeed, aggressive);

  }

}

// ---------------------------------------------


void turn(boolean dir, int Speed, boolean aggressive) {

  // Set the motors to go forward
      forward(Speed);

  // If turning right
  if (dir) {
    analogWrite(RSpeed, aggressive ? (Speed / 4) : (Speed / 2));
    analogWrite(LSpeed, Speed);
  }

  // turrning left
  else {
    analogWrite(RSpeed, Speed);
    analogWrite(LSpeed, aggressive ? (Speed / 4) : (Speed / 2));
  }

}
