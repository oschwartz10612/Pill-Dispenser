#include <Arduino.h>
#include <Stepper.h>
#include <Adafruit_VCNL4010.h>

Adafruit_VCNL4010 proximity;

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(stepsPerRevolution, 3, 5, 4, 6);

void setup() {

 
  Serial.begin(9600);

   if (! proximity.begin()){
    Serial.println("Sensor not found :(");
    //while (1);
  } else {
    Serial.println("Found vcnl4010");
  }

  Serial.println("Initializing stepper");
  myStepper.setSpeed(10);
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

  // Serial.print("Ambient: "); Serial.println(proximity.readAmbient());
  // Serial.print("Proximity: "); Serial.println(proximity.readProximity());
}
