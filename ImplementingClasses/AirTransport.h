#pragma once
#include "TransportVehicle.h"
//Класс воздушных ТС
class AirTransport : public TransportVehicle {
public:
	AirTransport();
	double distanceReductionRatio;
};