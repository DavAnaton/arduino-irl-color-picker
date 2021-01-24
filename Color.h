/*
  Color.h - Library for color management.
  Created by David A.
*/
#ifndef Color_h
#define Color_h
#include "Arduino.h"

class Color
{
  public:
    Color ();
    Color (int red, int green, int blue);
    void display ();
    int getRed();
    int getGreen();
    int getBlue();
    Color operator+ (Color c);
    Color operator* (double multiplier);
    Color operator/ (double divider);
  private:
    int _red;
    int _green;
    int _blue;
};

#endif
