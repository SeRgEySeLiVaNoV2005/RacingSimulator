#pragma once
#include "GroundTransportation.h"

class Centaur : public GroundTransportation {
public:
	Centaur(int lengthPath, double speedObject = 15, double timeRest = 2, double timeBeforeRest = 8);
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
}; 
