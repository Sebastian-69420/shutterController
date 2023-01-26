#include <Arduino.h>
#include <WiFi.h>

// My own files
#include "wifi_connect.h"

// INPUTS
#define buttonPin 32
#define wifiButtonPin 33

#define shutterButtonUp 17
#define shutterButtonDown 16
#define endstopUp 26
#define endstopDown 25

// OUTPUTS
#define ledPin 14
#define wifiConnectPin 27

#define shutterDriveUp 4
#define shutterDriveDown 2

bool buttonReading;
bool buttonState;
bool ledState;
bool lastButtonState = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup()
{

  // Just for testing.
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);

  // Actually needed.
  pinMode(wifiButtonPin, INPUT_PULLDOWN);
  pinMode(wifiConnectPin, OUTPUT);

  pinMode(shutterButtonUp, INPUT_PULLDOWN);
  pinMode(shutterButtonDown, INPUT_PULLDOWN);
  pinMode(endstopUp, INPUT_PULLDOWN);
  pinMode(endstopDown, INPUT_PULLDOWN);

  pinMode(shutterDriveUp, OUTPUT);
  pinMode(shutterDriveDown, OUTPUT);

  Serial.begin(9800);
  connectToWiFi(wifiConnectPin);
  Serial.println("Setup done.");
}

void driveShutterUp()
{
  digitalWrite(shutterDriveUp, HIGH);
  delay(50);

  while (digitalRead(endstopUp) == LOW)
  {
    if (digitalRead(shutterButtonUp) == HIGH || digitalRead(shutterDriveDown) == HIGH)
    {
      delay(50);
      break;
    }
  }
  digitalWrite((shutterDriveUp), LOW);
}

void driveShutterDown()
{
  while (digitalRead(endstopDown) == LOW)
  {
    digitalWrite(shutterDriveDown, HIGH);
  }
  digitalWrite((shutterDriveDown), LOW);
}

void loop()
{
  if (digitalRead(wifiButtonPin) == HIGH)
  {

    connectToWiFi(wifiConnectPin);
  }

  if (digitalRead(shutterButtonUp) == HIGH)
  {
    driveShutterUp();
  }
  else if (digitalRead(shutterButtonDown) == HIGH)
  {
    driveShutterDown();
  }

  buttonReading = digitalRead(buttonPin);
  if (buttonReading != lastButtonState)
  {
    lastDebounceTime = millis();
  }
  lastButtonState = buttonReading;
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (buttonReading != buttonState)
    {
      buttonState = buttonReading;
      if (buttonState == HIGH)
      {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
}