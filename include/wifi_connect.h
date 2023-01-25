#include <WiFi.h>

#ifndef WIFI_H
#define WIFI_H

const char *ssid = "YOUR_SSID";
const char *password = "YOUR_PASSWORD";

void connectToWiFi(int wifiConnectPin)
{
    WiFi.begin(ssid, password);
    int timeout = 10;
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        digitalWrite(wifiConnectPin, HIGH);
        delay(500);
        digitalWrite(wifiConnectPin, LOW);
        timeout--;
        if (timeout <= 0)
        {
            Serial.println("Timeout reached, no WiFi connection available");
            digitalWrite(wifiConnectPin, LOW);
            break;
        }
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("Connected to WiFi");
        digitalWrite(wifiConnectPin, HIGH);
    }
}

#endif
