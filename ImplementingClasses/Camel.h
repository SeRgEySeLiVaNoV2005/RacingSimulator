#pragma once
#include "GroundTransportation.h"

class Camel : public GroundTransportation {
public:
	Camel(int lengthPath, double speedObject = 10, double timeRest = 5, double timeBeforeRest = 30);
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
};