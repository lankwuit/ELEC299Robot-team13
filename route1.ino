//Routes for position 1

//route to get first ball (ball 8)
void firstBall(int speed){
  initializing();
  GoforWall(speed);
  turnAround(speed);
  GoforHome(speed);
  //release ball
  turnAround(speed); //come back to original position
} 

//route for second ball (ball 2)
void secondBall(int speed){
  initializing();
  GoforIntersection(speed, 2, false);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  sweep(); 
  GoforIntersection(speed, 3, true);
  GoforHome(speed);
  turnAround(speed);
}

//route for third ball (ball 5)
void thirdBall(int speed){
  initializing();
  GoforIntersection(speed, 6, false);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  sweep(); 
  GoforIntersection(speed, 3, true);
  GoforHome(speed);
  turnAround(speed);
}

//route for fourth ball (ball 12)
void fourthBall(int speed){
  initializing();
  GoforIntersection(speed, 5, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed); 
  sweep(); 
  GoforIntersection(speed, 2, false);
  GoforHome(speed);
  turnAround(speed);
}

//route for fifth ball
void  fifthBall(int speed){
  initializing();
  GoforIntersection(speed, 2, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed);
  sweep(); 
  GoforIntersection(speed, 2, false);
  GoforHome(speed);
  turnAround(speed);
}
