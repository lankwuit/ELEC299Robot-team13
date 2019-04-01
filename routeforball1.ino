//Route to pick up first ball (ball 7)
void firstBall(int speed){
  initializing();
  GoforWall(speed);
  turnAround(speed);
  GoforHome(speed);
  //release ball
  turnAround(speed); //come back to original position
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up second ball (ball 1)
void secondBall(int speed){
  initializing(); 
  GoforIntersection(speed, 1, false);
  
  GoforWall(speed);
    
  turnAround(speed);
  forward(speed);
  delay(500);//skip the first one
  sweep(); 
    GoforIntersection(speed, 1, true);
  
  //GoforIntersection(speed, 2, true);

  GoforHome(speed);
    
  turnAround(speed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up third ball (ball 4)
void thirdBall(int speed){
  initializing();
  GoforIntersection(speed, 5, false);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  sweep(); 
  GoforIntersection(speed, 2, true);
  GoforHome(speed);
  turnAround(speed);
  
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth ball (ball 11)
void fourthBall(int speed){
  initializing();
  GoforIntersection(speed, 6, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  sweep(); 
  GoforIntersection(speed, 3, false);
  GoforHome(speed);
  turnAround(speed);
  
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fifth ball (ball 14)
void fifthBall(int speed){
  initializing();
  GoforIntersection(speed, 3, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  sweep(); 
  GoforIntersection(speed, 3, false);
  GoforHome(speed);
  turnAround(speed);
}

//-----------------------------------------
void position1(int speedi){
  firstBall(speedi);
secondBall(speedi);
thirdBall(speedi);
fourthBall(speedi);
fifthBall(speedi);
return;
}
