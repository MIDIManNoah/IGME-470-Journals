/*
 Noah Richards
 P2 Move - Arduino Code
 Bits of code borrowed from these sources:
 - https://create.arduino.cc/editor/wmharris/411cdb7c-3c68-4c38-9162-6686ca95db31/preview
 - https://docs.arduino.cc/learn/electronics/servo-motors

 Required libraries:
 - Servo
 - RunningAverage
 (Both of these should be available under "Manage Libraries")
*/

#include <Servo.h>
#include <RunningAverage.h>

// Make an object that stores 8 floats at a time
// Use addValue to add values to it
// Use this to calculate the average input
RunningAverage average = RunningAverage(8);

Servo myServo; // Create an object for controlling the servo
const int servoPin = 5;

// Define pin numbers used by and for the distance sensor
const int trigPin = 3;
const int echoPin = 2;

// Store the distance and previous distance in two variables
unsigned long oldDist = 0;
unsigned long duration = 0;

// Setup the pins and serial communication
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
  delay(200); // breathe
}

void loop() {
  duration = getSonar();

  // Reduce jitter by getting the average of 10 values
  average.addValue(float(duration));
  duration = average.getAverage();
  
  // Only print duration if oldDist does not equal it
  if (oldDist != duration) {
    oldDist = duration;
    duration = duration;

    Serial.println(duration);
  }

  // Lift the servo up if the distance check is low enough
  int servoVal = 180;
  if (duration < 500) {
    servoVal = 0;
  }
  myServo.write(servoVal);
  
  delay(15);
}

/** getSonar: read sonar sensor and return echo duration
 * @return {unsigned long} duration of sonar pulse
 */
unsigned long getSonar() {
  //if (debug) {
    //digitalWrite(debugLed, HIGH);
  //}
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Read sonar value without getting interrupted
  noInterrupts();
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  unsigned long duration = pulseIn(echoPin, HIGH);
  
  interrupts(); //okay to interrupt now
  
  return duration;
}
