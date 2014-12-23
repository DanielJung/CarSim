#pragma once

#include "Car.h"
#include "CarTracker.h"
#include <vector>

class Simulator
{
public:
	Simulator(Car& oCar, double tBegin, double tEnd, double dt);
	~Simulator();

	void StartSim(std::vector<SimulationListener*>& aCarTracker);
private:
	Car& moCar;
	double mdTime;
	double mdDT;
	unsigned int miNumSteps;
};

