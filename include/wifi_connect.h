#ifndef WIFI_H
#define WIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <ezOutput.h>

class wifi_connect
{
private:
  int timeout;
  int blinkWaitTime;
  unsigned long startingTime;
  unsigned long blinkStartingTime;

public:
  void connectToWiFi(void);
};

#endif
