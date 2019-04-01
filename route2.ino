
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

------------------1-----------------
void firstBall(int speed){
  initializing();
  GoforWall(speed);
  turnAround(speed);
  GoforHome(speed);
  //release ball
  turnAround(speed); //come back to original position
}

//--------------2--------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up second ball (ball 3)
//Route to pick up second ball (ball 3)
void secondBall(int speed){
  initializing(); 
  GoforIntersection(speed, 3, false);
  
  GoforWall(speed);
    
  turnAround(speed);
  forward(speed);
<<<<<<< HEAD
=======
  sweep();
  pause();
>>>>>>> 5c603e2caca06b54da6789da95084903589d7ab2
  delay(500);//skip the first one
  sweep();pause();


    GoforIntersection(speed, 2, true);

  GoforHome(speed);
    
  turnAround(speed);
}



//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up third ball (ball 10)
void thirdBall(int speed){
  initializing();
  GoforIntersection(speed, 3, true);
  GoforIntersection(speed, 1, false);
  GoforWall(speed);
  turnAround(speed);
  forward(speed);
<<<<<<< HEAD
   delay(500);
  sweep();pause();
 
=======
  sweep();
  pause();
  delay(500);
>>>>>>> 5c603e2caca06b54da6789da95084903589d7ab2
  GoforIntersection(speed, 3, true);
  GoforIntersection(speed, 1, false);
  GoforHome(speed);
  turnAround(speed);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth ball (ball 6-0)
void fourthBall(int speed){
  initializing();
  GoforIntersection(speed, 2, false);
  GoforIntersection(speed, 3, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed);
<<<<<<< HEAD
    delay(500);
  sweep();pause();

=======
  sweep();
  pause();
  delay(500)
>>>>>>> 5c603e2caca06b54da6789da95084903589d7ab2
  GoforIntersection(speed, 4, false);
  GoforIntersection(speed, 1, true);
  GoforHome(speed);
  turnAround(speed);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth ball (ball 13)
void fifthBall(int speed){

  initializing();
  GoforIntersection(speed, 3, true);
  GoforWall(speed);
  turnAround(speed);
  forward(speed);
<<<<<<< HEAD
=======
  sweep();
  pause();
>>>>>>> 5c603e2caca06b54da6789da95084903589d7ab2
  delay(500);
  sweep();pause();

  GoforIntersection(speed, 3, false);
  GoforHome(speed);
}
