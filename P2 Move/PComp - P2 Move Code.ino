/*
 Noah Richards
 P2 Move - Arduino Code
 Bits of code borrowed from these sources:
 - https://create.arduino.cc/editor/wmharris/411cdb7c-3c68-4c38-9162-6686ca95db31/preview
 - https://docs.arduino.cc/learn/electronics/servo-motors
*/

#include <Servo.h>
#include <RunningAverage.h>

RunningAverage average = RunningAverage(10);

Servo myServo; // Create an object for controlling the servo
const int servoPin = 5;

const int trigPin = 3;
const int echoPin = 2;

unsigned long oldDist = 0;
unsigned long duration = 0;

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
