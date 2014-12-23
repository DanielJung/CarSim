#pragma once

#include "Car.h"
#include "SimulationListener.h"

class Driver : public SimulationListener
{
public:
	Driver(Car& oCar);
	~Driver();

	void setTargetSpeed(double dSpeed);
	double getTargetSpeed() const;

	void onStep(const Car& oCar);
private:
	Car& moCar;

	double mdTargetSpeed;
};

