//Routes for position 1

//route to get first Ball1 (Ball1 8)
void firstBall1(int speed){
  initializing();
  GoforWall(speed);
  turnAround(speed);
  GoforHome(speed);
  //release Ball1
  turnAround(speed); //come back to original position
} 

//route for second Ball1 (Ball1 2)
void secondBall1(int speed){
  initializing();
  GoforIntersection(speed, 2, false);
  GoforWall(speed);
  turnAround(speed);

  GoforIntersection(speed, 2, true);
  GoforHome(speed);
  turnAround(speed);
}

//route for third Ball1 (Ball1 5)
void thirdBall1(int speed){
  initializing();
  GoforIntersection(speed, 5, false);
  GoforWall(speed);
  turnAround(speed);

  GoforIntersection(speed, 2, true);
  GoforHome(speed);
  turnAround(speed);
}

//route for fourth Ball1 (Ball1 12)
void fourthBall1(int speed){
  initializing();
  GoforIntersection(speed, 4, true);
  GoforWall(speed);
  turnAround(speed);

  GoforIntersection(speed, 1, false);
  GoforHome(speed);
  turnAround(speed);
}

//route for fifth Ball1
void  fifthBall1(int speed){
  initializing();
  GoforIntersection(speed, 1, true);
  GoforWall(speed);
  turnAround(speed);

  GoforIntersection(speed, 1, false);
  GoforHome(speed);
  turnAround(speed);
}

void position1(int speedi){
  firstBall1(speedi);
secondBall1(speedi);
thirdBall1(speedi);
fourthBall1(speedi);
fifthBall1(speedi);
return;
}
