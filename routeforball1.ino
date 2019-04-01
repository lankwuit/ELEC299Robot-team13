//routes0
//Route to pick up first ball (ball 7)
void firstBall0(int speed){
  initializing();
  GoforWall(speed);
  turnAround(speed);
  GoforHome(speed);
  //release ball
  turnAround(speed); //come back to original position
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up second ball (ball 1)
void secondBall0(int speed){
  initializing(); 
  GoforIntersection(speed, 1, false);
  
  GoforWall(speed);
    
  turnAround(speed);
  forward(speed);
  delay(500);//skip the first one
  sweep();pause(); 
    GoforIntersection(speed, 1, true);
  
  //GoforIntersection(speed, 2, true);

  GoforHome(speed);
    
  turnAround(speed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up third ball (ball 4)
void thirdBall0(int speed){
  initializing();
  GoforIntersection(speed, 5, false);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  delay(500);
  sweep();pause(); 
  GoforIntersection(speed, 2, true);
  GoforHome(speed);
  turnAround(speed);
  
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth ball (ball 11)
void fourthBall0(int speed){
  initializing();
  GoforIntersection(speed, 6, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  delay(500);
  sweep();pause(); 
  GoforIntersection(speed, 3, false);
  GoforHome(speed);
  turnAround(speed);
  
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fifth ball (ball 14)
void fifthBall0(int speed){
  initializing();
  GoforIntersection(speed, 3, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed);
  delay(500); 
  sweep();pause(); 
  GoforIntersection(speed, 3, false);
  GoforHome(speed);
  turnAround(speed);
}

//-----------------------------------------
void position0(int speedi){
  firstBall0(speedi);
secondBall0(speedi);
thirdBall0(speedi);
fourthBall0(speedi);
fifthBall0(speedi);
return;
}
