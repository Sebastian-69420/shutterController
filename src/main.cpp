#include <Arduino.h>
#include <ezButton.h>
#include <ezOutput.h>

#include "wifi_connect.h"

// INPUTS
ezButton shutterButtonUp(34, INPUT_PULLDOWN);
ezButton shutterButtonDown(35, INPUT_PULLDOWN);
ezButton endstopUp(32, INPUT_PULLDOWN);
ezButton endstopDown(33, INPUT_PULLDOWN);
ezButton wifiButtonPin(25, INPUT_PULLDOWN);

// OUTPUTS
ezOutput ledPin(2);
ezOutput wifiConnectPin(15);
ezOutput shutterDriveUp(4);
ezOutput shutterDriveDown(0);

#define DEBOUNCE_TIME 50
wifi_connect wifi;
void setup()
{
  Serial.begin(9800);

  shutterButtonUp.setDebounceTime(DEBOUNCE_TIME);
  shutterButtonDown.setDebounceTime(DEBOUNCE_TIME);
  endstopUp.setDebounceTime(DEBOUNCE_TIME);
  endstopDown.setDebounceTime(DEBOUNCE_TIME);
  wifiButtonPin.setDebounceTime(DEBOUNCE_TIME);
}

void loop()
{
  shutterButtonUp.loop();
  shutterButtonDown.loop();
  endstopUp.loop();
  endstopDown.loop();
  wifiButtonPin.loop();
  shutterDriveUp.loop();
  shutterDriveDown.loop();
  wifiConnectPin.loop();

  if (wifiButtonPin.isPressed())
  {
    wifi.connectToWiFi();
  }
}