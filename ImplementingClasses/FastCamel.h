#pragma once
#include "GroundTransportation.h"

class FastCamel : public GroundTransportation {
public:
public:
	FastCamel(int lengthPath, double speedObject = 40, double timeRest = 5, double timeBeforeRest = 10);
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
};