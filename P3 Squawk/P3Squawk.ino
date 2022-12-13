/*
 Noah Richards
 P3 Squawk - Arduino Code
 Bits of code borrowed from these sources:
 - https://create.arduino.cc/editor/wmharris/01bb396f-6707-42c8-8c8f-8c167f599acb/preview
*/

#include "notes.h"
const int outpin = 2; // audio out to speaker
const int sensorPin1 = 3;  //sensor input pin
const int sensorPin2 = 4;  //sensor input pin
const int sensorPin3 = 5;  //sensor input pin

int R = 3; //REST pitch value

//rhythm values
int whq = 1280;
int wh = 1024;
int dh = 768;
int h  = 512;
int dq = 448;
int q = 256;
int qt = 170;
int de = 192;
int e = 128;
int et = 85;
int dsx = 96;
int sx = 64;
int thx = 32;

const int arrayLength = 6;

// Public Constants for music pitches
// source https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
int pitches[128];

int melody[] =  {
  NOTE_D4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_D5, NOTE_A4
};
int melody2[] =  {
  NOTE_FS4, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_FS5, NOTE_D5
};
int melody3[] =  {
  NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_A5, NOTE_FS5
};
int melodyDur[] = {
  q, q, q, q, q, q
};


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pitches[NOTE_D4] = 294;
  delay(1);
  pitches[NOTE_E4] = 330;
  delay(1);
  pitches[NOTE_FS4] = 370;
  delay(1);
  pitches[NOTE_G4] = 392;
  delay(1);
  pitches[NOTE_A4] = 440;
  delay(1);
  pitches[NOTE_B4] = 494;
  delay(1);
  pitches[NOTE_CS5] = 554;
  delay(1);
  pitches[NOTE_D5] = 587;
  delay(1);
  pitches[NOTE_E5] = 659;
  delay(1);
  pitches[NOTE_FS5] = 740;
  delay(1);
  pitches[NOTE_G5] = 784;
  delay(1);
  pitches[NOTE_A5] = 880;
  delay(10); // Give the Arduino a chance to breathe
}


void loop() {
  //int sensVal = 0;

  //Serial.print("1: " + sensVal1);
  //Serial.print(" 2: " + sensVal2);
  //Serial.println(" 3: " + sensVal3);

  //delay(5);

  for (int x = 0; x <  arrayLength; x++) { // loop over notes of a melody or multiple melodies
    int sensVal = digitalRead(sensorPin1);
    int sensVal2 = digitalRead(sensorPin2);
    int sensVal3 = digitalRead(sensorPin3);
    
    int divisor = sensVal + sensVal2 + sensVal3;
    if (divisor <= 0) {
      Serial.println("0\t0");
      break;
    }

    if (sensVal) {
      tone(outpin, 2*pitches[melody[x]], melodyDur[x]/divisor);
      Serial.print(melody[x]);
      Serial.print("\t");
      Serial.println(melodyDur[x]/divisor);
      delay(melodyDur[x]/divisor); 
    }
    
    if (sensVal2) {
      tone(outpin, 2*pitches[melody2[x]], melodyDur[x]/divisor);
      Serial.print(melody2[x]);
      Serial.print("\t");
      Serial.println(melodyDur[x]/divisor);
      delay(melodyDur[x]/divisor); 
    }

    if (sensVal3) {
      tone(outpin, 2*pitches[melody3[x]], melodyDur[x]/divisor);
      Serial.print(melody3[x]);
      Serial.print("\t");
      Serial.println(melodyDur[x]/divisor);
      delay(melodyDur[x]/divisor); 
    }
  }

  delay(5);
  //Serial.println(". ");
}
