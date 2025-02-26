#include "AllTerrainBoots.h"

AllTerrainBoots::AllTerrainBoots(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) :  GroundTransportation() {
	nameTranspost = "Ботинки-вездеходы";
	time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double AllTerrainBoots::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
    double timeWithoutStops = lengthPath / speedObject;
    double timeWithStops = lengthPath / (speedObject * timeBeforeRest);

    if (timeWithStops > 0) {
        timeWithoutStops += timeRest;
        lengthPath / (speedObject * timeBeforeRest) != timeWithStops ? timeWithStops-- : timeWithStops -= 2;
    }
    if (timeWithStops > 1) {
        timeWithStops *= 5;
    }

    return timeWithoutStops + timeWithStops;
}