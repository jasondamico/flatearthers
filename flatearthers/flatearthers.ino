#include <AutoPID.h>
#include <StackArray.h>
#include <QueueArray.h>
#include <DRV8835MotorShield.h>

// Sensors
#define RIGHT     A1
#define RIGHT_D   A2
#define FRONT     A3
#define LEFT_D    A4
#define LEFT      A5

// Motors
#define M1A 1
#define M1B 2
#define M2A 3
#define M2B 4

// PID
#define MIN 0
#define MAX 225
#define KP .12
#define KI .0003
#define KD 0

double motorSpeed, setPoint, outputVal;
AutoPID myPID(&motorSpeed, &setPoint, &outputVal, MIN, MAX, KP, KI, KD);
DRV8835MotorShield motors;

//struct for a coordinate
typedef struct _coord{
  byte x;
  byte y;
} coord;

//struct for a cell in a maze
typedef struct _entry{
  int distance;
  byte walls;
} entry;

//struct for a command
typedef struct _command{
  int orientation;
} command;

//navigation command for the robot
//implement by a queue to simulate recursion on the robots
QueueArray<command> commands;

int orientation[] = {1,2,4,8};

//maze constant
#define X 16
#define Y 16

entry maze[X][Y];

byte globalHeading = 4;
coord globalCoord = {0,0};
coord globalEnd = {0,0};


void setup() {
  Serial.begin(9600);
  sensorSetup();
  motorSetup();
  pidSetup();
}

void debug(String Name, int Value) {
  Serial.print(Name);
  Serial.print(": ");
  Serial.println(Value);
}


void loop() {

  //  forwardOneBlock();
  //  turn180();
  //  turnRight();
  //  turnLeft();
  //  delay(500);

}
