#include <Arduino.h>
#include <Stepper.h>
#include <Adafruit_VCNL4010.h>

Adafruit_VCNL4010 proximity;

// Define number of steps per rotation:
const int stepsPerRevolution = 512;
int prevProx;
int prevAmb;
int counter = 0;

Stepper myStepper = Stepper(stepsPerRevolution, 3, 5, 4, 6);

void setup() {
  Serial.begin(9600);

   if (! proximity.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  } else {
    Serial.println("Found vcnl4010");
  }

  Serial.println("Initializing stepper");
  myStepper.setSpeed(10);
  prevProx = proximity.readProximity();
}
void loop() {

  int prox = proximity.readProximity();
  Serial.print("Proximity: "); Serial.println(prox);

  int proxDiff = abs(prox - prevProx);
  Serial.println(proxDiff);
  if (proxDiff >= 100) {
    Serial.println("Dispensing...");
    myStepper.step(stepsPerRevolution);

    delay(5000);
  }

  counter++;
  if (counter >= 12) {
    prevProx = prox;
    counter = 0;
  }
  
  delay(100);
}
