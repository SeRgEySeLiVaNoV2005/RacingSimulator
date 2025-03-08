#include "Camel.h"

Camel::Camel(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) : GroundTransportation() {
	nameTranspost = "��������";
    time = getTimeResult(lengthPath, speedObject, timeRest, timeBeforeRest);
}

double Camel::getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest) {
    double timeWithoutStops = lengthPath / speedObject; // ����� �������� ��� ���������
    int StopCount = lengthPath / (speedObject * timeBeforeRest); // ����� ����� ������� �� ����������
    return timeWithoutStops + timeRest + (StopCount - 1) * 8;
    /*if (StopCount > 0) {
        timeWithoutStops += timeRest;
        lengthPath / (speedObject * timeBeforeRest) != StopCount ? StopCount-- : StopCount -= 2;
    }
    if (StopCount > 1) {
        StopCount *= 8;
    }

    return timeWithoutStops + StopCount;*/
}