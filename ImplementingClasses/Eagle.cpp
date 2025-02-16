#include "Eagle.h"

Eagle::Eagle(int lengthPath, double speedObject) : AirTransport() {
	nameTranspost = "Îð¸ë";
	distanse = lengthPath;
	speedTranspost = speedObject;
	time = getTimeResult(lengthPath, speedObject);
}

double Eagle::getTimeResult(int lengthPath, double speedObject) {
	distanceReductionRatio = 6;
	return (lengthPath - lengthPath * (distanceReductionRatio/100)) / speedObject;
}