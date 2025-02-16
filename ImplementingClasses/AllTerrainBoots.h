#pragma once
#include "GroundTransportation.h"

class AllTerrainBoots : public GroundTransportation {
public:
	AllTerrainBoots(int lengthPath, double speedObject = 6, double timeRest = 10, double timeBeforeRest = 60);
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
}; 
