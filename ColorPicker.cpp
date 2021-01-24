#include <Streaming.h>
#include "ColorPicker.h"

ColorPicker::ColorPicker(){}

void ColorPicker::setup(){
	keypad = CustomKeypad();
	_colors.setStorage(_colorStorage);
	led = RgbLed(9, 10, 11);
}

Color ColorPicker::readColor(){
	return sensor.getColor();
	// return Color();
}

void ColorPicker::addColor (Color color){
	_colors.push_back(color);
}

Color ColorPicker::getColor (int index){
	return _colors[index];
}

void ColorPicker::listen(){
	Serial << "1) Calibrate\n2) Read color\n\n";
	char key;
	while(!(key = keypad.getKey())){}
	switch(key){
		case '1':
			Serial << "Calibration for white in ";
			Serial << "3, ";
			delay(1000);
			Serial << "2, ";
			delay(1000);
			Serial << "1...\n";
			delay(1000);
			sensor.calibrateColor(CALIBRATE_WHITE);
			Serial << "White calibrated\n";
			Serial << "Calibration for black in ";
			Serial << "3, ";
			delay(1000);
			Serial << "2, ";
			delay(1000);
			Serial << "1...\n";
			delay(1000);
			sensor.calibrateColor(CALIBRATE_BLACK);
			Serial << "Done calibrating\n";
			break;
		case '2':
			Color c = sensor.getColor();
			led.setColor(c);
			c.display();
			break;
	}
}