#include "Centaur.h"

Centaur::Centaur(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) : GroundTransportation() {
	nameTranspost = "Кентавр";
	time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double Centaur::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
	return int(lengthPath / speedObject) + int(lengthPath / (speedObject * timeBeforeRest)) * timeRest;
}