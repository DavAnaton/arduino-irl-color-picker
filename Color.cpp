#include <Streaming.h>
#include "Color.h"

Color::Color()
{
  _red = random(0, 255);
  _green = random(0, 255);
  _blue = random(0, 255);
}
Color::Color(int red, int green, int blue)
{
  _red = red;
  _green = green;
  _blue = blue;
}
void Color::display()
{
  Serial << "{" 
    << _red << ","
    << _green << "," 
    <<_blue 
  << "}\n";
}
Color Color::operator+(Color color){
  return Color(
    _red + color._red,
    _green + color._green,
    _blue + color._blue
  );
}
Color Color::operator*(double multiplier){
  return Color(
    int(_red * multiplier),
    int(_green * multiplier),
    int(_blue * multiplier)
  );
}
Color Color::operator/(double divider){
  return *this * (1.0/divider);
}

int Color::getRed(){return _red;}
int Color::getGreen(){return _green;}
int Color::getBlue(){return _blue;}
