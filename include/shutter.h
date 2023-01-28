#ifndef shutter_h
#define shutter_h

#include <Arduino.h>

// #define stuff

class shutter
{
private:
    bool direction;
    int outPin;

public:
    shutter(int pin);
    shutter(int pin, int mode);
    void goUp(void);
    void goDown(void);
    void stop(void);
    void loop(void);
};

#endif