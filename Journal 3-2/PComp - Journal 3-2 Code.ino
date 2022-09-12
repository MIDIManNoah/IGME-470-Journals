/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPin2 = 9;
const int ledPin =  5;      // the number of the LED pin
const int ledPin2 = 7;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
//int ledState = 0;            // variable for reading the first led

void setup() {
  // initialize the LED pins as outputs:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  //ledState = digitalRead(ledPin);
  buttonState2 = digitalRead(buttonPin2);

  if ((buttonState == HIGH) && (buttonState2 == HIGH)) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if ((buttonState == HIGH) ^ (buttonState2 == HIGH)) {
    // turn LED2 on
    digitalWrite(ledPin2, HIGH);
  } else {
    // turn LED2 off:
    digitalWrite(ledPin2, LOW);
  }
}
