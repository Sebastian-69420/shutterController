#ifndef shutter_h
#define shutter_h

#include <Arduino.h>

class shutter
{
private:
    int inUp_;
    int inDown_;
    int inEndUp_;
    int inEndDown_;
    int outUp_;
    int outDown_;

    
public:
  void shutterInput(
    int inputPinUp,
    int inputPinDown,
    int inputPinEndstopUp,
    int intputPinEndstopDown);
    
  void shutterOutput(
    int outputPinUp,
    int outputPinDown);
  
  void stop(void);
  void driveUp(void);
  void driveDown(void);
};

#endif