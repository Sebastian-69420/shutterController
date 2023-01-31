#include "wifi_connect.h"

void wifi_connect::connectToWiFi()
{
  extern ezOutput wifiConnectPin;
  const char *ssid = "YOUR_SSID";
  const char *password = "YOUR_PASSWORD";
  bool blinkInit = false;
  bool blinkStarted = false;

  if (blinkInit == false)
  {
    wifiConnectPin.blink(500, 500);
    blinkStarted = true;
    blinkInit = true;
    Serial.println("can i get here?");
  }

  WiFi.begin(ssid, password);
  int timeout = 5000;
  unsigned long startTime = millis();
  Serial.println("wifi start");
  if (blinkStarted)
  {
    Serial.println("Can I get here?");
    while (WiFi.status() != WL_CONNECTED)
    {
      if (timeout < millis() - startTime)
      {
        Serial.println("");
        Serial.println("Timeout reached, couldn't establish valid connection.");
        wifiConnectPin.low();
        break;
      }
    }

    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.print("Connected to ");
      Serial.println(ssid);
      wifiConnectPin.high();
    }
  }
}