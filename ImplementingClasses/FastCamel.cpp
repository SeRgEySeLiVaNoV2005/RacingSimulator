#include "FastCamel.h"

FastCamel::FastCamel(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) : GroundTransportation() {
	nameTranspost = "Верблюд-быстроход";
    time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double FastCamel::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
    double timeWithoutStops = lengthPath / speedObject;
    int StopCount = lengthPath / (speedObject * timeBeforeRest);
    return timeWithoutStops + timeRest + 6.5 + (StopCount - 2) * 8;
    /*if (StopCount > 0) {
        timeWithoutStops += timeRest;
        lengthPath / (speedObject * timeBeforeRest) != StopCount ? StopCount-- : StopCount -= 2;
    }
    if (StopCount > 1) {
        StopCount += 8;
    }
    if (StopCount > 2) {
        if (lengthPath / (speedObject * timeBeforeRest) == StopCount) StopCount--;
        StopCount *= 8;
    }

    return timeWithoutStops + StopCount;*/
}