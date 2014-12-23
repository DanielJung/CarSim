#include "stdafx.h"
#include "ShiftControl.h"


ShiftControl::ShiftControl(const Car& oCar) : moCar(oCar)
{
}


ShiftControl::~ShiftControl()
{
}

unsigned int ShiftControl::onShift() {
	if (moCar.getMotor().getFrequency() > 4200.0 / 60.0 && moCar.getGearbox().getCurrentGear() < 5){
		return moCar.getGearbox().getCurrentGear() + 1;
	}
	else if (moCar.getMotor().getFrequency() < 1000.0 / 60.0 && moCar.getGearbox().getCurrentGear()>0){
		return moCar.getGearbox().getCurrentGear() - 1;
	}
	return moCar.getGearbox().getCurrentGear();
}