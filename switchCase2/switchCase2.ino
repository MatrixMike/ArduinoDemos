/*
  Switch statement with serial input

  Demonstrates the use of a switch statement. The switch statement allows you
  to choose from among a set of discrete values of a variable. It's like a
  series of if statements.

  To see this sketch in action, open the Serial monitor and send any character.
  The characters a, b, c, d, and e, will turn on LEDs. Any other character will
  turn the LEDs off.

  The circuit:
  - five LEDs attached to digital pins 2 through 6 through 220 ohm resistors

  created 1 Jul 2009
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/SwitchCase2
*/

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pins:
  for (int thisPin = 8; thisPin < 8+5; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    // do something different depending on the character received.
    // The switch statement expects single number values for each case; in this
    // example, though, you're using single quotes to tell the controller to get
    // the ASCII value for the character. For example 'a' = 97, 'b' = 98,
    // and so forth:

    switch (inByte) {
      case 'a':
        digitalWrite(8, HIGH);  // use enum is possible
        break;
      case 'b':
        digitalWrite(9, HIGH);
        break;
      case 'c':
        digitalWrite(10, HIGH);
        break;
      case 'd':
        digitalWrite(11, HIGH);
        break;
      case 'e':
        digitalWrite(12, HIGH);
        break;
      default:
        // turn all the LEDs off:
  for (int thisPin = 8; thisPin < 8+5; thisPin++) {
          digitalWrite(thisPin, LOW);
        }
    }
  }
}
