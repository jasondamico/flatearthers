// Sensors
#define RIGHT     A1
//#define RIGHT_D   A2
#define FRONT     A3
//#define LEFT_D    A4
#define LEFT      A5

void motorSetup() {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, INPUT);
  pinMode(M2A, INPUT);
  pinMode(M2B, INPUT);

  // To reverse the polarity of the motor
  motors.flipM1(true);
  motors.flipM2(false);
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

  while (i < 53 && analogRead(FRONT) < 390) {
    if (leftAvailable()) {
      if (analogRead(LEFT) > 360) {
        if (speed1 < 40) {
          speed1 += 2;
          speed2 -= 2;
        }
      }
      else if (analogRead(LEFT) < 240) {
        if (speed1 > 30) {
          speed1 -= 2;
          speed2 += 2;
        }
      }

      if (analogRead(LEFT) > 310) {
        if (speed1 < 40) {
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
      else if (analogRead(LEFT) < 290) {
        if (speed1 > 30) {
          speed1--;
          speed2++;
        }
        //              else if(speed2 < 40){
        //                speed2++;
        //              }
        //speed1 = 40;
        //i += 1;
      }
      else {
        speed1 = 35;
        speed2 = 35;
      }
    }
    else if (rightAvailable()) {
      if (analogRead(RIGHT) > 360) {
        if (speed1 < 40) {
          speed1 -= 2;
          speed2 += 2;
        }
      }
      else if (analogRead(RIGHT) < 240) {
        if (speed1 > 30) {
          speed1 += 2;
          speed2 -= 2;
        }
      }
      if (analogRead(RIGHT) > 310) {
        if (speed1 > 30) {
          speed1--;
          speed2++;
        }
        //              else if(speed2 < 40){
        //                speed2++;
        //              }
        //speed1 = 40;
        //i += 1;;
      }
      else if (analogRead(RIGHT) < 290) {
        if (speed1 < 40) {
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
    else {
      speed1 = 35;
      speed2 = 35;
    }
    i++;
    motors.setM1Speed(speed1);
    motors.setM2Speed(speed2);

    delay(15);
  }

  while (analogRead(FRONT) > 150 && analogRead(FRONT) < 390) {
    if (leftAvailable()) {
      if (analogRead(LEFT) > 360) {
        if (speed1 < 40) {
          speed1 += 2;
          speed2 -= 2;
        }
      }
      else if (analogRead(LEFT) < 240) {
        if (speed1 > 30) {
          speed1 -= 2;
          speed2 += 2;
        }
      }

      if (analogRead(LEFT) > 310) {
        if (speed1 < 40) {
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
      else if (analogRead(LEFT) < 290) {
        if (speed1 > 30) {
          speed1--;
          speed2++;
        }
        //              else if(speed2 < 40){
        //                speed2++;
        //              }
        //speed1 = 40;
        //i += 1;
      }
      else {
        speed1 = 35;
        speed2 = 35;
      }
    }
    else if (rightAvailable()) {
      if (analogRead(RIGHT) > 360) {
        if (speed1 < 40) {
          speed1 -= 2;
          speed2 += 2;
        }
      }
      else if (analogRead(RIGHT) < 240) {
        if (speed1 > 30) {
          speed1 += 2;
          speed2 -= 2;
        }
      }
      if (analogRead(RIGHT) > 310) {
        if (speed1 > 30) {
          speed1--;
          speed2++;
        }
        //              else if(speed2 < 40){
        //                speed2++;
        //              }
        //speed1 = 40;
        //i += 1;;
      }
      else if (analogRead(RIGHT) < 290) {
        if (speed1 < 40) {
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
    else {
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
  //  delay(2000);
}












// ============================================================ //
void turn180() {
  int speed = 0;
  for (speed = 0; speed <= 35; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(42);
  }
  for (speed = speed; speed >= 0; speed--) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(51);
  }
  //  delay(2000);
}

void turn1802() {
  int speed, speed1, speed2;
  for (speed = 0; speed <= 25; speed++) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(20);
  }
  speed1 = speed;
  speed2 = speed;
  int i = 0;

  while (i < 107) {
    motors.setM1Speed(-speed1);
    motors.setM2Speed(+speed2);
    i++;
    delay(15);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
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
  //  delay(2000);
}

void turnRight2() {
  int speed, speed1, speed2;
  for (speed = 0; speed <= 25; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(20);
  }
  speed1 = speed;
  speed2 = speed;
  int i = 0;

  while (i < 54) {
    motors.setM1Speed(speed1);
    motors.setM2Speed(-speed2);
    i++;
    delay(15);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
}

void turnRight2Over() {
  int speed, speed1, speed2;
  for (speed = 0; speed <= 25; speed++) {
    motors.setM1Speed(speed);
    motors.setM2Speed(-speed);
    delay(20);
  }
  speed1 = speed;
  speed2 = speed;
  int i = 0;

  while (i < 58) {
    motors.setM1Speed(speed1);
    motors.setM2Speed(-speed2);
    i++;
    delay(15);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
}


void turnRight4() {
  currentAngle =0;
  double expactedAngle = currentAngle - 1.54; //-1.45;
  while (currentAngle > expactedAngle) {
    Serial.print("Current Angle");
    Serial.print(currentAngle);
    Serial.print("expacted Angle");
    Serial.println(expactedAngle);
    motors.setM1Speed(30);
    motors.setM2Speed(-30);
    compute();
    delay(50);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
}

void turnLeft4() {
  currentAngle =0;
  double expactedAngle = currentAngle + 1.54;//1.40;
  while (currentAngle < expactedAngle) {
    Serial.print("Current Angle");
    Serial.print(currentAngle);
    Serial.print("expacted Angle");
    Serial.println(expactedAngle);
    motors.setM1Speed(-30);
    motors.setM2Speed(30);
    compute();
    delay(50);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
}

void turn1804() {
  turnRight4();
  delay(1000);
  turnRight4();
  
  motors.setM1Speed(0);
  motors.setM2Speed(0);
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
  //  delay(2000);
}

void turnLeft2() {
  int speed, speed1, speed2;
  for (speed = 0; speed <= 25; speed++) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(20);
  }
  speed1 = speed;
  speed2 = speed;
  int i = 0;

  while (i < 51) {
    motors.setM1Speed(-speed1);
    motors.setM2Speed(+speed2);
    i++;
    delay(15);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
}

void turnLeft2Over() {
  int speed, speed1, speed2;
  for (speed = 0; speed <= 25; speed++) {
    motors.setM1Speed(-speed);
    motors.setM2Speed(speed);
    delay(20);
  }
  speed1 = speed;
  speed2 = speed;
  int i = 0;

  while (i < 60) {
    motors.setM1Speed(-speed1);
    motors.setM2Speed(+speed2);
    i++;
    delay(15);
  }
  motors.setM1Speed(0);
  motors.setM2Speed(0);
}

void turnLeftTwice() {
  turnLeft2();
  turnLeft2();
}

// ============================================================ //
void correctSpeed(int M1, double target) {
  motorSpeed = analogRead(M1A);
  setPoint = target;
  myPID.run();
  analogWrite(M1A, outputVal);
}

void forwardOneBlockFaster() {

}


void testMotors() {
//  forwardOneBlock();
//  forwardOneBlock();
  turnRight2();
  turnRight2();
  delay(2000);
  turnLeft2();
  turnLeft2();
  delay(2000);
  turn1802();
  delay(2000);
}

bool leftAvailable() {
  //"Perfect reading" for the sensor at dead center is 275
  return analogRead(LEFT) >= 150;
}

bool rightAvailable() {
  return analogRead(RIGHT) >= 150;
}
