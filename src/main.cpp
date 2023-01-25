#include <Arduino.h>
#include <WiFi.h>

// My own files
#include "wifi_connect.h"

#define ledPin 14
#define buttonPin 32
#define wifiButtonPin 33
#define wifiConnectPin 27

bool buttonReading;
bool buttonState;
bool ledState;
bool lastButtonState = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);
  pinMode(wifiButtonPin, INPUT_PULLDOWN);
  pinMode(wifiConnectPin, OUTPUT);

  Serial.begin(9800);
  connectToWiFi(wifiConnectPin);
  Serial.println("Setup done.");
}

void loop()
{
  if (digitalRead(wifiButtonPin) == HIGH)
  {

    connectToWiFi(wifiConnectPin);
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