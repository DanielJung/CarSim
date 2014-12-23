#pragma once

#include "SimulationListener.h"

class CarTracker : public SimulationListener
{
public:
	CarTracker();
	~CarTracker();

	void onStart();

	void onStep(const Car& oCar);

	void onStop();
private:
	ofstream moFile;
};

