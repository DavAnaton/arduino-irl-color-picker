#include "RgbSensor.h"
#include <Streaming.h>

// Default pins
// #define OE, GN => GND
// #define VCC => 5V
#define S0 2
#define S1 3 
#define S2 4
#define S3 5
#define OUT 6


void setPinsMode(){
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(OUT, INPUT);
}

int normalize(uint16_t freq, uint16_t calibration[]){
	int value = map(freq, calibration[CALIBRATE_WHITE], calibration[CALIBRATE_BLACK], 255, 0);
	if(value < 0){
		value = 0;
	} 
	if(value > 255){
		value = 255;
	}
	return value;
}

void setScaler(enum SCALER_MODE scalerMode) {
	switch(scalerMode){
		case(SCALER_POWER_DOWN):
			digitalWrite(S0, LOW);
			digitalWrite(S1, LOW);
			break;
		case(SCALER_TWO):
			digitalWrite(S0, LOW);
			digitalWrite(S1, HIGH);
			break;
		case(SCALER_TWENTY):
			digitalWrite(S0, HIGH);
			digitalWrite(S1, LOW);
			break;
		case(SCALER_HUNDRED):
			digitalWrite(S0, HIGH);
			digitalWrite(S1, HIGH);
			break;
	}
	delay(400);
}

void setFilter(int filterMode) {
	switch(filterMode){
		case(FILTER_RED):
			digitalWrite(S2, LOW);
			digitalWrite(S3, LOW);
			break;
		case(FILTER_BLUE):
			digitalWrite(S2, LOW);
			digitalWrite(S3, HIGH);
			break;
		case(FILTER_CLEAR):
			digitalWrite(S2, HIGH);
			digitalWrite(S3, LOW);
			break;
		case(FILTER_GREEN):
			digitalWrite(S2, HIGH);
			digitalWrite(S3, HIGH);
			break;
	}
	delay(400);
}

void stop_all() {
	digitalWrite(S0, LOW);
	digitalWrite(S1, LOW);
	digitalWrite(S2, LOW);
	digitalWrite(S3, LOW);
}

RgbSensor::RgbSensor(){
	setPinsMode();
	scalerMode = SCALER_TWENTY;
}

void RgbSensor::calibrateColor(bool blackOrWhite){
	uint16_t* frequencies = getFrequencies();
	for(int filter = FILTER_RED; filter <= FILTER_GREEN; filter++){
		calibration[filter][blackOrWhite] = frequencies[filter];
	}
}

Color RgbSensor::getColor (){
	uint16_t* frequencies = getFrequencies();
	return Color(
		normalize(frequencies[FILTER_RED], calibration[FILTER_RED]), 
		normalize(frequencies[FILTER_GREEN], calibration[FILTER_GREEN]), 
		normalize(frequencies[FILTER_BLUE], calibration[FILTER_BLUE])
	);
}

uint16_t* RgbSensor::getFrequencies(){
	uint16_t* frequencies = new uint16_t[4];
	setScaler(scalerMode);
	for(int filter = FILTER_RED; filter <= FILTER_GREEN; filter++){
		setFilter(filter);
		frequencies[filter] = pulseIn(OUT, LOW);
		Serial << frequencies[filter];
		if(filter != FILTER_GREEN){Serial << ", ";}
		else {Serial << '\n';}
	}
	stop_all();
	return frequencies;
}