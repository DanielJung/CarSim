#pragma once

#include "Car.h"

class SimulationListener
{
public:
	virtual void onStep(const Car& oCar) = 0;
};

