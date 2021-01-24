#ifndef RgbSensor_h
#define RgbSensor_h
#include "Arduino.h"
#include "Color.h"

#define CALIBRATE_WHITE 1
#define CALIBRATE_BLACK 0

enum FILTER_MODE{
	FILTER_RED,
	FILTER_BLUE,
	FILTER_CLEAR,
	FILTER_GREEN
};

enum SCALER_MODE{
	SCALER_POWER_DOWN,
	SCALER_TWO,
	SCALER_TWENTY,
	SCALER_HUNDRED
};

class RgbSensor{
  public:
    RgbSensor();
    Color getColor();
    void calibrateColor(bool white);
    void setFilterMode(int mode);
    void setScalerMode(int mode);
  private:
  	enum FILTER_MODE filterMode;
  	enum SCALER_MODE scalerMode;
  	uint16_t calibration[4][2]; 
  	void stopAll();
    uint16_t* getFrequencies();
};

#endif
