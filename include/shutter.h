#include <Arduino.h>

bool inputShutterUpReading;
bool inputShutterDownReading;
bool inputEndstopUpReading;
bool inputEndstopDownReading;
bool lastShutterUpReading;
bool lastShutterDownReading;

void driveShutterUp(
    int shutterDriveUp, int endstopUp, int shutterButtonUp, int shutterDriveDown)
{
    digitalWrite(shutterDriveUp, HIGH);

    if (inputEndstopUpReading == HIGH)
    {
        digitalWrite((shutterDriveUp), LOW);
        return;
    }
}

void driveShutterDown(
    int shutterDriveDown, int endstopDown, int shutterButtonDown, int shutterDriveUp)
{
    while (digitalRead(endstopDown) == LOW)
    {
        digitalWrite(shutterDriveDown, HIGH);
    }
    digitalWrite((shutterDriveDown), LOW);
}