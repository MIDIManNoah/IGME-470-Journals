/*
 * Noah Richards
 * 9/27/2022
 * P1 Blink
 */


// Constants for the separate pins
const int ledPin = 5;
const int ledPin2 = 7;
const int switchPin = 2;
const int dialPin = A0;

// Store the reset value for the ledBlink value
const int ledBlinkMax = 1024*8;

int switchState = 0;
int ledBlink = ledBlinkMax;
volatile byte ledState = LOW;

// Setup the inputs and outputs
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(switchPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Get input values of both the potentiometer and the switch
  int sensorValue = analogRead(dialPin);
  switchState = digitalRead(switchPin);
  //Serial.println(sensorValue);

  // Divide the potentiometer input by 4 so the LEDs don't flash too much
  sensorValue = sensorValue / 4;
  sensorValue = 256 - sensorValue;
  if (sensorValue < 8) { 
    sensorValue = 8;
  }

  // Decrement the ledBlink counter by the potentiometer input value
  ledBlink -= sensorValue;

  // "Toggle" the LEDs when the counter hits 0 and reset the counter
  if (ledBlink <= 0) {
    ledState = !ledState;
    // Make the first LED flash
    digitalWrite(ledPin, ledState);

    // The switch controls whether the second LED should flash too
    if (switchState == HIGH) {
      // Make the second LED flash in the opposite pattern from the first LED
      digitalWrite(ledPin2, !ledState);
    } else {
      digitalWrite(ledPin2, LOW);
    }
    
    ledBlink = ledBlinkMax;
  }

  // Delay the loop by 1 millisecond to let the Arduino process the inputs
  delay(1);
}
