void firstball(int speed){
  int bumpers = 0;
  do{
    followLine(speed, 10, false);
    bumpers = bumper();
  }while(bumpers == 0); 

  if(bumpers == 1){
    //grabs ball 
  }
  turnAround(speed);
  do{
    followLine(speed, 10, false);
    bumpers = bumper();
  }while(bumpers == 0);
  
  //release ball
  turnAround(speed); //come back to original position
    return;
}
