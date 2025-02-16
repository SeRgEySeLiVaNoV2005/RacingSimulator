#include "FastCamel.h"

FastCamel::FastCamel(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) : GroundTransportation() {
	nameTranspost = "Верблюд-быстроход";
    time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double FastCamel::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
    double timeWithoutStops = lengthPath / speedObject; // Время прибытия без остановок
    double timeWithStops = lengthPath / (speedObject * timeBeforeRest); // Время всего простоя на остановках

    if (timeWithStops > 0) {
        timeWithoutStops += timeRest;
        lengthPath / (speedObject * timeBeforeRest) != timeWithStops ? timeWithStops-- : timeWithStops -= 2;
    }
    if (timeWithStops > 1) {
        timeWithStops += 8;
    }
    if (timeWithStops > 2) {
        if (lengthPath / (speedObject * timeBeforeRest) == timeWithStops) timeWithStops--;
        timeWithStops *= 8;
    }

    return timeWithoutStops + timeWithStops;
}