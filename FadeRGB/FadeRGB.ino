/*
  Fade

  This example shows how to fade an LED on pin 9
  using the analogWrite() function.

  This example code is in the public domain.
  Demo Sample code to create light effects on a single three colour LED.   part number xxxx
  Modified 28 November 2014  by Mike Hewitt
  Very poor - inefficient code - need to rewrite to perform ALL single, dual and triple combinations.

  uploaded to git 29 April 2015
// revived 18 Dec 2021
*/

#define led  9           // RED the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

enum colours { redLED = 9, blueLED, greenLED };

#define ledR   9  // red 
#define ledG  11    // green
#define ledB  10   // blue

//int loopCount;
int maxFade = 250;

class LEDbright {
    // need to modify this to allow 3 pins to be faded a.o.t. just the one: colourPin
  private:   int loopC;
  public:
    int colourPin1; // RGB LED has three internal LEDs each on it's own pin
    int brightness;
    int fadeAmount;
    int delayCount;

    // LEDbright() {
    // }
    LEDbright(int x, int y, int z, int dc) {
      colourPin1  = x;
      brightness = y;
      fadeAmount = z;
      delayCount = dc;

      for ( loopC = 0; loopC < maxFade; loopC++) {
        analogWrite (colourPin1, brightness);    // changed to use enum
        // could add two more colourPins here with same brightness 
        // and add two more arguments 
        brightness = brightness + fadeAmount;
        //   Serial.print("brightness ");
        if (brightness <= 0 || brightness > maxFade) {
          fadeAmount = -fadeAmount ;
        }
        delay(30);
      }
    }
};



// the setup routine runs once when you press reset:
void setup()  {
  // declare pin 9 to be an output:
  pinMode(redLED, OUTPUT);  // red
  pinMode(greenLED, OUTPUT);  // green
  pinMode(blueLED, OUTPUT);  // blue
}

// the loop routine runs over and over again forever:
void loop()  {
  //  // set the brightness of pin 9:
  //  analogWrite(led,     brightness);
  ////  analogWrite(led+1,   255-brightness);
  ////  analogWrite(led+2,   brightness);
  //
  //  // change the brightness for next time through the loop:
  //  brightness = brightness + fadeAmount;
  //
  //  // reverse the direction of the fading at the ends of the fade:
  //  if (brightness <= 0 || brightness == 255) {
  //    fadeAmount = -fadeAmount ;
  //  }
  //  // wait for 30 milliseconds to see the dimming effect
  //  delay(30);
  //  red();
  //  blue();

  Serial.begin(9600);
  // LEDbright red();
  //      colourPin  = x;
  //      brightness = y;
  //      fadeAmount = z;
  //      delayCount = dc;
  LEDbright   red(redLED,   0, 2, 30);
  LEDbright green(greenLED, 0, 2, 30);
  LEDbright  blue(blueLED,  0, 2, 30);
  //  ledRGB();
  //
  //  yellow2();
  //  green2();
  //  red2();
  //
  //  blue2();
  //  ledRB();
  //  ledGB();

}

void red() {
  int maxFade = 255; // a constant ?
  int brightness = 0;
  int fadeAmount = 5;
  int loopcount;
  for ( loopcount = 0; loopcount < maxFade; loopcount++) {
    analogWrite (redLED, brightness);    // changed to use enum
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    delay(30);
  }
}

void blue() {
  int maxFade = 255; // a constant ?
  int brightness = 0;
  int fadeAmount = 5;
  int loopcount;
  for ( loopcount = 0; loopcount < maxFade; loopcount++) {
    analogWrite (ledB, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    delay(30);
  }
}

void green() {
  int maxFade = 255; // a constant ?
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;
  for ( loopcount = 0; loopcount < maxFade; loopcount++) {
    analogWrite (ledG, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    delay(30);
  }
}

void green2() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (ledG, brightness);
    brightness = brightness + fadeAmount;
    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}


void red2() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (ledR, brightness);
    brightness = brightness + fadeAmount;
    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}

void blue2() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (ledB, brightness);
    brightness = brightness + fadeAmount;
    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}


void yellow2() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (ledR, brightness);
    analogWrite (ledG, brightness);
    brightness = brightness + fadeAmount;
    Serial.print("brightness ");
    Serial.println(brightness);

    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}

void ledRB() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (ledR, brightness);
    analogWrite (ledB, brightness);
    brightness = brightness + fadeAmount;
    Serial.print("brightness ");
    Serial.println(brightness);

    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}

void ledGB() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (ledG, brightness);
    analogWrite (ledB, brightness);
    brightness = brightness + fadeAmount;
    Serial.print("brightness ");
    Serial.println(brightness);

    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}

void ledRGB() {
  int incycle;
  int maxFade = 250; // a constant ? reduced for debug
  int brightness = 0;
  int fadeAmount = 2;
  int loopcount;

  incycle = 1;
  while ( incycle == 1) {
    analogWrite (redLED, brightness);
    analogWrite (greenLED, brightness);
    analogWrite (blueLED, brightness);
    analogWrite (ledB, brightness);
    //  analogWrite (ledB, brightness);
    brightness = brightness + fadeAmount;
    Serial.print("brightness ");
    Serial.println(brightness);

    if ( brightness > maxFade) {
      fadeAmount = -fadeAmount ;
    }
    if (brightness < 0 ) {
      //    fadeAmount = -fadeAmount ;
      incycle = 0;
    }
    delay(30);

  }

}
