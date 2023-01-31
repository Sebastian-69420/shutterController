#include <shutter.h>

shutter::shutter(int pin)
{
    _outputPin = pin;
    _outputState = LOW;

    return;
}

void shutter::goUp(void)
{
    stop();
    return digitalWrite(_outputPin, HIGH);
}

void shutter::goDown(void)
{
    stop();
    return digitalWrite(_outputPin, HIGH);
}

void shutter::stop()
{
    return digitalWrite(_outputPin, LOW);
}