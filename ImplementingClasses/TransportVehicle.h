#pragma once
#include <string>

#ifdef IMPLEMENTINGCLASSES_EXPORTS
#define IMPLEMENTINGCLASSES_API __declspec(dllexport)
#else 
#define IMPLEMENTINGCLASSES_API __declspec(dllimport)
#endif


//Класс транспортных средств 
class IMPLEMENTINGCLASSES_API TransportVehicle {
public:
	double time;
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
	std::string nameTranspost, typeTransport;
	double speedTranspost, distanse; // Скорость ТС и дистанция гонки
};

