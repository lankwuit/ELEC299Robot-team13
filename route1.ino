//Routes for position 1

//route to get first ball (ball 8)
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

//route for second ball (ball 2)
void secondBall(int speed){
  followLine(speed, 2, false);
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
  followLine(speed, 3, true);
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

//route for third ball (ball 5)
void thirdBall(int speed){
  followLine(speed, 6, false);
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
  followLine(speed, 3, true);
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

//route for fourth ball (ball 12)
void fourthBall(int speed){
  followLine(speed, 5, true);
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
  followLine(speed, 2, false);
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

//route for fifth ball
void  fifthBall(int speed){
    followLine(speed, 2, true);
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
  followLine(speed, 2, false);
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
