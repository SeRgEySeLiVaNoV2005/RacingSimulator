#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) :  GroundTransportation() {
	nameTranspost = "Ботинки-вездеходы";
	time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double AllTerrainBoots::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
    double timeWithoutStops = lengthPath / speedObject;
    int StopCount = lengthPath / (speedObject * timeBeforeRest);
    return timeWithoutStops + timeRest + (StopCount - 1) * 5;
    /*if (StopCount > 0) {
        timeWithoutStops += timeRest;
        lengthPath / (speedObject * timeBeforeRest) != StopCount ? StopCount-- : StopCount -= 2;
    }
    if (StopCount > 1) {
        StopCount *= 5;
    }

    return timeWithoutStops + StopCount;*/
}