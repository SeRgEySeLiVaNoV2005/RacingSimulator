#pragma once
#include "TransportVehicle.h"
//����� ��������� ��
class AirTransport : public TransportVehicle {
public:
	AirTransport();
	double distanceReductionRatio;
};