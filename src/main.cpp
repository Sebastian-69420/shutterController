#include <Arduino.h>
#include <WiFi.h>
#include <ezButton.h>

// My own files
#include "wifi_connect.h"
#include "shutter.h"

// INPUTS
ezButton shutterButtonUp(34, INPUT_PULLDOWN);
ezButton shutterButtonDown(35, INPUT_PULLDOWN);
ezButton endstopUp(32, INPUT_PULLDOWN);
ezButton endstopDown(33, INPUT_PULLDOWN);
ezButton buttonPin(25, INPUT_PULLDOWN);
ezButton wifiButtonPin(26, INPUT_PULLDOWN);

// OUTPUTS
#define ledPin 2
#define wifiConnectPin 15

#define shutterDriveUp 4
#define shutterDriveDown 0

#define DEBOUNCE_TIME 50

void setup()
{

  // Just for testing.
  pinMode(ledPin, OUTPUT);

  // Actually needed.
  pinMode(wifiConnectPin, OUTPUT);
  pinMode(shutterDriveUp, OUTPUT);
  pinMode(shutterDriveDown, OUTPUT);

  Serial.begin(9800);
  connectToWiFi(wifiConnectPin);

  shutterButtonUp.setDebounceTime(DEBOUNCE_TIME);
  shutterButtonDown.setDebounceTime(DEBOUNCE_TIME);
  endstopUp.setDebounceTime(DEBOUNCE_TIME);
  endstopDown.setDebounceTime(DEBOUNCE_TIME);
  buttonPin.setDebounceTime(DEBOUNCE_TIME);
  wifiButtonPin.setDebounceTime(DEBOUNCE_TIME);
}

void loop()
{
  shutterButtonUp.loop();
  shutterButtonDown.loop();
  endstopUp.loop();
  endstopDown.loop();
  buttonPin.loop();
  wifiButtonPin.loop();

  if (shutterButtonUp.isPressed())
    Serial.println("The button 1 is pressed");

  if (shutterButtonUp.isReleased())
    Serial.println("The button 1 is released");

  if (shutterButtonDown.isPressed())
    Serial.println("The button 2 is pressed");

  if (shutterButtonDown.isReleased())
    Serial.println("The button 2 is released");

  if (endstopUp.isPressed())
    Serial.println("The button 3 is pressed");

  if (endstopUp.isReleased())
    Serial.println("The button 3 is released");

  if (endstopDown.isPressed())
    Serial.println("The button 4 is pressed");

  if (endstopDown.isReleased())
    Serial.println("The button 4 is released");

  if (buttonPin.isPressed())
    Serial.println("The button 5 is pressed");

  if (buttonPin.isReleased())
    Serial.println("The button 5 is released");

  if (wifiButtonPin.isPressed())
    Serial.println("The button 6 is pressed");

  if (wifiButtonPin.isReleased())
    Serial.println("The button 6 is released");
}