
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------1-----------------
void firstBall2(int speed){
  initializing();
  GoforWall(speed);
  turnAround(speed);
  GoforHome(speed);
  //release Ball2
  turnAround(speed); //come back to original position
}

//--------------2--------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up second Ball2 (Ball2 3)
//Route to pick up second Ball2 (Ball2 3)
void secondBall2(int speed){
  initializing(); 
  GoforIntersection(speed, 3, false);
  
  GoforWall(speed);
    
  turnAround(speed);
//  forward(speed);
//  delay(500);//skip the first one



    GoforIntersection(speed, 3, true);

  GoforHome(speed);
    
  turnAround(speed);
}



//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up third Ball2 (Ball2 10)
void thirdBall2(int speed){
  initializing();
  GoforIntersection(speed, 3, true);
  GoforIntersection(speed, 1, false);
  GoforWall(speed);
  turnAround(speed);

 
  GoforIntersection(speed, 2, true);
  GoforIntersection(speed, 1, false);
  GoforHome(speed);
  turnAround(speed);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth Ball2 (Ball2 6-0)
void fourthBall2(int speed){
  initializing();
  GoforIntersection(speed, 5, false);
  GoforIntersection(speed, 3, true);
  GoforWall(speed);
  turnAround(speed);


  GoforIntersection(speed, 1, false);
  GoforIntersection(speed, 1, true);
  GoforHome(speed);
  turnAround(speed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth Ball2 (Ball2 13)
void fifthBall2(int speed){

  initializing();
  GoforIntersection(speed, 3, true);
  GoforWall(speed);
  turnAround(speed);


  GoforIntersection(speed, 3, false);
  GoforHome(speed);
}

void position2(int speedi){
  firstBall2(speedi);
secondBall2(speedi);
thirdBall2(speedi);
fourthBall2(speedi);
fifthBall2(speedi);
return;
}
