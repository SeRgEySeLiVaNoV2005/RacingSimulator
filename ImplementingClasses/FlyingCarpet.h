#pragma once
#include "AirTransport.h"

class FlyingCarpet : public AirTransport {
public:
    FlyingCarpet(int lengthPath, double speedObject = 10);
    double getTimeResult(int lengthPath, double speedObject);
};