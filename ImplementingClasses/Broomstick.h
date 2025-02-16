#pragma once
#include "AirTransport.h"

class Broomstick : public AirTransport{
public:
    Broomstick(int lengthPath, double speedObject = 20);
    double getTimeResult(int lengthPath, double speedObject);
};

