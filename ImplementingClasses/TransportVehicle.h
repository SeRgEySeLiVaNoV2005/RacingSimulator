#pragma once
#include <string>

#ifdef IMPLEMENTINGCLASSES_EXPORTS  //������ ��������
#define IMPLEMENTINGCLASSES_API __declspec(dllexport)
#else 
#define IMPLEMENTINGCLASSES_API __declspec(dllimport)
#endif

//����� ������������ ������� 
class TransportVehicle {
public:
	double time;
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
	 std::string nameTranspost, typeTransport;
	double speedTranspost, distanse; // �������� �� � ��������� �����
};

