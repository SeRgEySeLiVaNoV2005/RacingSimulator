#pragma once
#include <string>

//����� ������������ ������� 
class TransportVehicle {
public:
	double time;
	double getTimeResult(int lengthPath, double speedObject, double timeRest, double timeBeforeRest);
	 std::string nameTranspost, typeTransport;
	double speedTranspost, distanse; // �������� �� � ��������� �����
};

