#include <Stepper.h>
// Define number of steps per rotation:
const int stepsPerRevolution = 2048;

Stepper myStepper = Stepper(stepsPerRevolution, 3, 5, 4, 6);

void setup() {

  myStepper.setSpeed(5);

  Serial.begin(9600);
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
}
