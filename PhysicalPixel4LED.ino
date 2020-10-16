/*
  Physical Pixel

  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.

  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.

  The circuit:
  - LED connected from digital pin 13 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/PhysicalPixel

  Added support for 4 LEDs. 
*/

const int REDledPin = 12; // the pin that the LED is attached to
const int GREENledPin = 11; // the pin that the LED is attached to
const int BLUEledPin = 7; // the pin that the LED is attached to
const int YELLOWledPin = 6; // the pin that the LED is attached to


int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(REDledPin, OUTPUT);
  pinMode(GREENledPin, OUTPUT);
  pinMode(BLUEledPin, OUTPUT);
  pinMode(YELLOWledPin, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    // recieves byte from flask server form request
    incomingByte = Serial.read();

    
    // if it's an R (ASCII 76) turn on the Red LED:
    // if it's an r (ASCII 76) turn off the Red LED:
    if (incomingByte == 'R') {
      digitalWrite(REDledPin, HIGH);
    }
    if (incomingByte == 'r') {
      digitalWrite(REDledPin, LOW);
    }


    // if it's an G (ASCII 76) turn on the Green LED:
    // if it's an g (ASCII 76) turn off the Green LED:
    if (incomingByte == 'G') {
      digitalWrite(GREENledPin, HIGH);
    }
    if (incomingByte == 'g') {
      digitalWrite(GREENledPin, LOW);
    }


    // if it's an B (ASCII 76) turn on the Blue LED:
    // if it's an b (ASCII 76) turn off the Blue LED:
    if (incomingByte == 'B') {
      digitalWrite(BLUEledPin, HIGH);
    }
    if (incomingByte == 'b') {
      digitalWrite(BLUEledPin, LOW);
    }


    // if it's an Y (ASCII 76) turn on the Yellow LED:
    // if it's an y (ASCII 76) turn off the Yellow LED:
    if (incomingByte == 'Y') {
      digitalWrite(YELLOWledPin, HIGH);
    }
    if (incomingByte == 'y') {
      digitalWrite(YELLOWledPin, LOW);
    }    

    // if it's an O (ASCII 76) turn on all LEDs:
    // if it's an o (ASCII 76) turn off all LEDs:
    if (incomingByte == 'O') {
      digitalWrite(REDledPin, HIGH);
      digitalWrite(GREENledPin, HIGH);
      digitalWrite(BLUEledPin, HIGH);
      digitalWrite(YELLOWledPin, HIGH);
     }    

    if (incomingByte == 'o') {
      digitalWrite(REDledPin, LOW);
      digitalWrite(GREENledPin, LOW);
      digitalWrite(BLUEledPin, LOW);
      digitalWrite(YELLOWledPin, LOW);
    }    
    
  }
}
