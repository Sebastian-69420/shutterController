#include "shutter.h"

// Internal state variables:
bool moving_;  // 'True' indicates that the shutter is currently moving.

// Initialize all inputs.
// This function must be called during the setup() before the shutter loop().
void shutter::shutterInput(
  int inputPinUp,
  int inputPinDown,
  int inputPinEndstopUp,
  int inputPinEndstopDown)
{
  int inUp_ = inputPinUp;
  int inDown_ = inputPinDown;
  int inEndUp_ = inputPinEndstopUp;
  int inEndDown_ = inputPinEndstopDown;
}

// Initialize all outputs.
// This function must be called during the setup() before the shutter loop().
void shutter::shutterOutput(
  int outputPinUp,
  int outputPinDown)
{
  int outUp_ = outputPinUp;
  int outDown_ = outputPinDown;
}

// Stops the shutter.
void shutter::stop(void)
{
  digitalWrite(outUp_, LOW);
  digitalWrite(outDown_, LOW);
  moving_ = false;
}

// Drives the shutter upwards.
void shutter::driveUp(void)
{
  if (moving_ == true)
  {
    stop();
    return;
  }
  digitalWrite(outUp_, HIGH);
  moving_ = true;

}

// Drives the shutter downwards.
void shutter::driveDown(void)
{
    if (moving_ == true)
  {
    stop();
    return;
  }
  digitalWrite(outDown_, HIGH);
  moving_ = true;
}