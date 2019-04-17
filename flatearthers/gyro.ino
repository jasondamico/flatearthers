
//Adafruit_L3GD20 gyro();
Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
void gyroSetup() {
  if (!gyro.begin()) {//Can change sampling rate
    Serial.println("Oops ... unable to initialize the L3GD20. Check your wiring!"); while (1);
  }
}

void gyroLoop() {
  //gyro.read();
  sensors_event_t event; 
  gyro.getEvent(&event);
  Serial.println("Z: "); Serial.print(event.gyro.z); Serial.print("  rad/s");
}

double getNetMovement(){
  double x = getXAngularSpeed();
  double y = getYAngularSpeed();
  double z = getZAngularSpeed();
  return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); 
}

double gyroIntegrate(double currentAngle, double samplingTime, double angularSpeed){
  //Ignore the noise
  if(angularSpeed < 0.05 && angularSpeed > -0.05){
    return currentAngle;
  }
  if(angularSpeed > 0){
    angularSpeed *= 1.12;//1.57/1.36;
  }
  else{
    angularSpeed *= 1.57/1.36;
  }
  double deltaAngle = samplingTime * angularSpeed;
  return currentAngle + deltaAngle;
}

//Return deltaT in second
double calcTimeDifference(unsigned long lastTime){
  int deltaTI = millis() - lastTime;
  
  double deltaTD = deltaTI * 0.001;
  return deltaTD;
}

double compute(){
  double deltaT = calcTimeDifference(currentTime);
  currentTime = millis();
//  double angularSpeed = getNetMovement();
//  if (getZAngularSpeed() < 0){
//     angularSpeed*=-1;
//  }
  currentAngle =  gyroIntegrate(currentAngle,deltaT, getZAngularSpeed());
  return currentAngle;
}

float getZAngularSpeed(){
  sensors_event_t event; 
  gyro.getEvent(&event);
  return event.gyro.z;
}

float getXAngularSpeed(){
  sensors_event_t event; 
  gyro.getEvent(&event);
  return event.gyro.x;
}

float getYAngularSpeed(){
  sensors_event_t event; 
  gyro.getEvent(&event);
  return event.gyro.y;
}
