#pragma once
#include <string>

//Класс транспортных средств 
class TransportVehicle {
public:
	double time;
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
	 std::string nameTranspost, typeTransport;
	double speedTranspost, distanse; // Скорость ТС и дистанция гонки
};

