
//Route to pick up first ball (ball 7)
void firstBall(int speed){
  do{
    followLine(speed, 10, false);
  }while(!bumper()); 

  wallinfront();
  turnAround(speed);
  do{
    followLine(speed, 10, false);
  }while(!bumper());
  homeinfront();
  //release ball
  turnAround(speed); //come back to original position
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up second ball (ball 1)
void secondBall(int speed){
  followLine(speed, 1, false);
  do{
    if (bumper()){
      //grab ball
      wallinfront();
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
  turnAround(speed);
  followLine(speed, 2, true);
  do{
    if(bumper()){
      homeinfront();
      turnAround(speed); //come back to original position
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up third ball (ball 4)
void thirdBall(int speed){
  followLine(speed, 5, false);
  do{
    if (bumper()){
      //grab ball
      wallinfront();
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
  turnAround(speed);
  followLine(speed, 2, true);
  do{
    if(bumper()){
      homeinfront();
      turnAround(speed); //come back to original position
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth ball (ball 11)
void fourthBall(int speed){
  followLine(speed, 6, true);
  do{
    if (bumper()){
      //grab ball
      wallinfront();
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
  turnAround(speed);
  followLine(speed, 3, false);
  do{
    if(bumper()){
      homeinfront();
      turnAround(speed); //come back to original position
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Route to pick up fourth ball (ball 14)
void fifthBall(int speed){
  followLine(speed, 3, true); //starting from position 1 not 0
  do{
    if (bumper()){
      //grab ball
      wallinfront();
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
  turnAround(speed);
  followLine(speed, 3, false);
  do{
    if(bumper()){
      homeinfront();
      turnAround(speed); //come back to original position
    }
    else{
      followLine(speed, 10, false);
    }
  }while(!bumper());
}
