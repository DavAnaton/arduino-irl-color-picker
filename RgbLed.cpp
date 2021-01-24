#include "RgbLed.h"
#include <Streaming.h>

// Default pins
#define RED 11
#define GREEN 10
#define BLUE 9

RgbLed::RgbLed(){
	redPin = RED;
	greenPin = GREEN;
	bluePin = BLUE;
	setPinsMode();
}
RgbLed::RgbLed(int _redPin, int _greenPin, int _bluePin){
	redPin = _redPin;
	greenPin = _greenPin;
	bluePin = _bluePin;
	setPinsMode();
}
void RgbLed::setPinsMode(){
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);
}

void RgbLed::setColor (Color color){
	analogWrite(redPin, color.getRed());
	analogWrite(greenPin, color.getGreen());
	analogWrite(bluePin, color.getBlue());
}

void RgbLed::setColor (int r, int g, int b){
	setColor(Color(r,g,b));
}
