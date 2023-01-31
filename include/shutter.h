#ifndef shutter_h
#define shutter_h

#include <Arduino.h>

// #define stuff

class shutter
{
private:
    int _outputPin;
    int _outputState;

public:
    shutter(int pin);
    void goUp(void);
    void goDown(void);
    void stop(void);
};

#endif