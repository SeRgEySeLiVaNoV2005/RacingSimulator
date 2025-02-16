#include "Camel.h"

Camel::Camel(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) : GroundTransportation() {
	nameTranspost = "Вердблюд";
    time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double Camel::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
    double timeWithoutStops = lengthPath / speedObject; // Время прибытия без остановок
    double timeWithStops = lengthPath / (speedObject * timeBeforeRest); // Время всего простоя на остановках

    if (timeWithStops > 0) {
        timeWithoutStops += timeRest;
        lengthPath / (speedObject * timeBeforeRest) != timeWithStops ? timeWithStops-- : timeWithStops -= 2;
    }
    if (timeWithStops > 1) {
        timeWithStops *= 8;
    }

    return timeWithoutStops + timeWithStops;
}