#include <shutter.h>

shutter::shutter(int pin) : shutter(pin, OUTPUT){};

shutter::shutter(int pin, int mode)
{
    outPin = pin;

    pinMode(outPin, mode);
}

void shutter::goUp(void)
{
}

void shutter::goDown(void)
{
}

void shutter::stop()
{
}

void shutter::loop(void)
{
}