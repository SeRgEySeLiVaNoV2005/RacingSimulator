#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

#include "..\ImplementingClasses\Transport.h"


class Generator : TransportVehicle{
public:
	void textWarning();
	int getPreparationOfRace();
	static bool sortWiner(map<string, double> a, map<string, double> b);
	Generator();
	int getTypeRace();
	int getLengthPath();
	map<string, unique_ptr<TransportVehicle>> getTransportVehicle(int tr, int lp);
	int getResultRace(map<string, unique_ptr<TransportVehicle>> result);
};

