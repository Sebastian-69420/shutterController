#include <shutter.h>

shutter::shutter(int pin) : shutter(pin, OUTPUT){};

shutter::shutter(int pin, int mode)
{
    outPin = pin;

    pinMode(outPin, mode);
}

bool shutter::goUp(void)
{
    direction = true;
    return direction;
}

bool shutter::goDown(void)
{
    direction = false;
    return direction;
}

void shutter::stop()
{
    return;
}

void shutter::loop(void)
{
    return;
}