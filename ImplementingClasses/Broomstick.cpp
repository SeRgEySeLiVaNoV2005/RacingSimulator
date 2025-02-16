#include "Broomstick.h"

Broomstick::Broomstick(int lengthPath, double speedObject) : AirTransport() {
	nameTranspost = "Метла";
	distanse = lengthPath;
	speedTranspost = speedObject;
	time = getTimeResult(lengthPath, speedObject);
}

double Broomstick::getTimeResult(int lengthPath, double speedObject) {
	distanceReductionRatio = (0.01 * int(lengthPath / 1000));
	return (lengthPath - lengthPath * distanceReductionRatio) / speedObject;
}