#pragma once

#include "Car.h"

class ShiftControl
{
public:
	ShiftControl(const Car& oCar);
	~ShiftControl();

	unsigned int onShift();
private:
	const Car& moCar;
};

