#ifndef RgbLed_h
#define RgbLed_h
#include "Arduino.h"
#include "Color.h"

class RgbLed{
  public:
    RgbLed();
    RgbLed(int _redPin, int _greenPin, int _bluePin);
    void setColor (Color color);
    void setColor (int r, int g, int b);
  private:
    int redPin;
    int greenPin;
    int bluePin;
    void setPinsMode();
};

#endif
