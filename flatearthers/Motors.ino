
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
  int speed = 0;
  for (speed = 0; speed <= 45; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(speed);
    delay(30);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(speed);
    motors.setM2Speed(speed);
    delay(30);
  }
  delay(2000);
}

// ============================================================ //
void turn180() {
  int speed = 0;
  for (speed = 0; speed <= 52; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(20);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(25);
  }
  delay(2000);
}

// ============================================================ //
void turnRight() {
  int speed = 0;
  for (speed = 0; speed <= 40; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(20);
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
  for (speed = 0; speed <= 40; speed++) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(20);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(25);
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
    return analogRead(LEFT) >= 150;
}

bool rightAvailable(){
    return analogRead(RIGHT) >= 150;
}
