#include <Arduino.h>
#include <WiFi.h>
#include <ezButton.h>
#include <ezOutput.h>

// My own files
#include "wifi_connect.h"
#include "shutter.h"

// INPUTS
ezButton inputPinUp(34, INPUT_PULLDOWN);
ezButton inputPinDown(35, INPUT_PULLDOWN);
ezButton inputPinEndstopUp(32, INPUT_PULLDOWN);
ezButton inputPinEndstopDown(33, INPUT_PULLDOWN);
ezButton wifiButtonPin(25, INPUT_PULLDOWN);

// OUTPUTS
ezOutput outputPinUp(4);
ezOutput outputPinDown(0);
#define ledPin 2
#define wifiConnectPin 15

#define DEBOUNCE_TIME 50

void setup()
{
  // Just for testing.
  pinMode(ledPin, OUTPUT);

  // Actually needed.
  pinMode(wifiConnectPin, OUTPUT);

  Serial.begin(9800);
  connectToWiFi(wifiConnectPin);

  inputPinUp.setDebounceTime(DEBOUNCE_TIME);
  inputPinDown.setDebounceTime(DEBOUNCE_TIME);
  inputPinEndstopUp.setDebounceTime(DEBOUNCE_TIME);
  inputPinEndstopDown.setDebounceTime(DEBOUNCE_TIME);
  wifiButtonPin.setDebounceTime(DEBOUNCE_TIME);
}

void loop()
{
  inputPinUp.loop();
  inputPinDown.loop();
  inputPinEndstopUp.loop();
  inputPinEndstopDown.loop();
  wifiButtonPin.loop();

  inputPinUp.loop();
  inputPinDown.loop();


  if (inputPinUp.isPressed())
    shutter driveUp();

  else if (inputPinDown.isPressed())
    shutter driveDown();
  
  else if (inputPinEndstopUp.isPressed() || inputPinEndstopDown.isPressed())
    shutter stop();

  if (inputPinUp.isPressed())
    Serial.println("The button 1 is pressed");

  if (inputPinDown.isPressed())
    Serial.println("The button 2 is pressed");

  if (inputPinEndstopUp.isPressed())
    Serial.println("The button 3 is pressed");

  if (inputPinEndstopDown.isPressed())
    Serial.println("The button 4 is pressed");

  if (wifiButtonPin.isPressed())
    Serial.println("The button 5 is pressed");

}