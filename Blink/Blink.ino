/*
  mod 29 April 2015 - demo for RGB LED
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
  for the press-stud Lilypad the green LED is on p13
  Sun 10 Jan 10:18:01 AEDT 2021
*/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 9;  // red
int led2 = 13;  // red
int v1 = 50;
int v2 = 500;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(v1);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(v2);               // wait for a second
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(v1);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(v1);               // wait for a second
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(v1);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(v1);               // wait for a second
}
