// Sensors
#define RIGHT     A1
#define RIGHT_D   A2
#define FRONT     A3
#define LEFT_D    A4
#define LEFT      A5

void motorSetup() {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, INPUT);
  pinMode(M2A, INPUT);
  pinMode(M2B, INPUT);

  // To reverse the polarity of the motor
  motors.flipM1(true);
  motors.flipM2(true);
}

// ============================================================ //
void forwardOneBlock() {
  int speed;
  int speed1, speed2;
  for (speed = 0; speed <= 35; speed++) {

    motors.setM1Speed(speed);
    motors.setM2Speed(speed);
    delay(30);
  }
  speed1 = speed;
  speed2 = speed;
  int i = 0;

  while(i < 60 && analogRead(FRONT) < 435){
        if(leftAvailable()){
           if(analogRead(LEFT) > 290){
              if(speed1 < 40){
                speed1++;
                speed2--;
              }
              //else if(speed2 >30){
                //speed2--;
              //}
              //speed1 = 50; // Assume the 1 is left
              //if(speed2 <= 40
              //i += 1;
              }
           else if(analogRead(LEFT) < 270){
              if(speed1 > 30){
                speed1--;
                speed2++;
              }
//              else if(speed2 < 40){
//                speed2++;
//              }
              //speed1 = 40;
              //i += 1;
           }
           else{
            speed1 = 35;
            speed2 = 35;
          }
        }
        else if(rightAvailable()){
           if(analogRead(RIGHT) > 290){
              if(speed1 > 30){
                speed1--;
                speed2++;
              }
//              else if(speed2 < 40){
//                speed2++;
//              }
              //speed1 = 40;
              //i += 1;;
           }
           else if(analogRead(RIGHT) < 270){
            if(speed1 < 40){
                speed1++;
                speed2--;
              }
//              else if(speed2 >30){
//                speed2--;
//              }
              //speed1 = 50;
              //i += 1;
           }
        }
        else{
          speed1 = 35;
          speed2 = 35;
        }
        i++;
        motors.setM1Speed(speed1);
        motors.setM2Speed(speed2);
        
        delay(15);
    }

  motors.setM1Speed(0);
  motors.setM2Speed(0);
  //for (speed = speed; speed >= 0; speed--) {
  //  motors.setM1Speed(speed);
  //  motors.setM2Speed(speed);
  //  delay(30);
  //}
  delay(2000);
}

// ============================================================ //
void turn180() {
  int speed = 0;
  for (speed = 0; speed <= 34; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(40);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(51);
  }
  delay(2000);
}

// ============================================================ //
void turnRight() {
  int speed = 0;
  for (speed = 0; speed <= 34; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(23);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(25);
  }
  delay(2000);
}

// ============================================================ //
void turnLeft() {
  int speed = 0;
  for (speed = 0; speed <= 35; speed++) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(20);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(24);
  }
  delay(2000);
}

// ============================================================ //
void correctSpeed(int M1, double target) {
  motorSpeed = analogRead(M1A);
  setPoint = target;
  myPID.run();
  analogWrite(M1A, outputVal);
}

void forwardOneBlockFaster(){
  
}


bool leftAvailable(){
    //"Perfect reading" for the sensor at dead center is 275
    return analogRead(LEFT) >= 150;
}

bool rightAvailable(){
    return analogRead(RIGHT) >= 150;
}
