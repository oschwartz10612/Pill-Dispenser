#include <Stepper.h>
#include "Adafruit_VCNL4010.h"

Adafruit_VCNL4010 proximity;

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(stepsPerRevolution, 3, 5, 4, 6);

void setup() {

 
  Serial.begin(9600);

   if (! vcnl.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.println("Found VCNL4010");
  Serial.println("Initializing stepper");
  myStepper.setSpeed(5);
}
void loop() {
  // Step one revolution in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);
  
  // Step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);

  Serial.print("Ambient: "); Serial.println(vcnl.readAmbient());
  Serial.print("Proximity: "); Serial.println(vcnl.readProximity());
}
