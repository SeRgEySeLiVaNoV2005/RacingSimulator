#pragma once
#include "AirTransport.h"
class Eagle : public AirTransport{
public:
    Eagle(int lengthPath, double speedObject = 8);
    double getTimeResult(int lengthPath, double speedObject);
};