#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet(int lengthPath, double speedObject) : AirTransport() {
	nameTranspost = "Ковёр-самолёт";
	distanse = lengthPath;
	speedTranspost = speedObject;
	time = getTimeResult(lengthPath, speedObject);
}
double FlyingCarpet::getTimeResult(int lengthPath, double speedObject) {
	distanceReductionRatio = (lengthPath < 1000 ? 0 : lengthPath < 5000 ? 0.03 : lengthPath < 10000 ? 0.1 : 0.05);
	return (lengthPath - lengthPath * distanceReductionRatio) / speedObject;
}