// Adafruit IO Digital Output Example
// Tutorial Link: https://learn.adafruit.com/adafruit-io-basics-digital-output
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(12,14); // RX, TX


//String inputString="";




// digital pin 5
#define LED_PIN 4
#define LED_PIN1 5
String inputString="";
// set up the 'digital' feed
AdafruitIO_Feed *hospitalone = io.feed("hospitalone");
AdafruitIO_Feed *hospitaltwo = io.feed("hospitaltwo");
AdafruitIO_Feed *liveupdate = io.feed("liveupdate");

void setup() {

  // set led pin as a digital output
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_PIN1, OUTPUT);

  // start the serial connection
  Serial.begin(115200);
  mySerial.begin(9600);
  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'digital' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  hospitalone ->onMessage(handleMessage);
   hospitaltwo->onMessage(handleMessage1);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();
if(mySerial.available())
  {  
    
    inputString=mySerial.readString();
    Serial.println(inputString);
    liveupdate->save(inputString);
  }
//    Serial.println(inputString);
//    mycity->save("welcome");
    delay(3000);
}

// this function is called whenever an 'digital' feed message
// is received from Adafruit IO. it was attached to
// the 'digital' feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  if(data->toPinLevel() == HIGH)
    Serial.println("HIGH");
  else
    Serial.println("LOW");

  // write the current state to the led
  digitalWrite(LED_PIN, data->toPinLevel());

}

void handleMessage1(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  if(data->toPinLevel() == HIGH)
    Serial.println("HIGH");
  else
    Serial.println("LOW");

  // write the current state to the led
  digitalWrite(LED_PIN1, data->toPinLevel());

}
