#ifndef ColorPicker_h
#define ColorPicker_h
#include <Arduino.h>
#include <Vector.h>
#include "Color.h"
#include "RgbLed.h"
#include "RgbSensor.h"
#include "CustomKeypad.h"


class ColorPicker
{
  public:
    ColorPicker ();
    RgbLed led;
    RgbSensor sensor;
    CustomKeypad keypad;

    Color getColor (int colorIndex);
    void setup ();
    void addColor(Color color);
    Color readColor();
    void listen();
  private:
    Color _colorStorage[10];
    Vector<Color> _colors;
};

#endif
