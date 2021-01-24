#include "Color.h"
#include "ColorPicker.h"
#include <Streaming.h>

ColorPicker cp;

void setup() {
	Serial.begin(9600);
	cp.setup();
}

void loop() {
	cp.listen();
}
