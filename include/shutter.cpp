#include <shutter.h>

shutter::shutter(int pin) : shutter(pin, OUTPUT){};

shutter::shutter(int pin, int mode)
{
    outPin = pin;

    pinMode(outPin, mode);
}

void shutter::loop(void)
{
}