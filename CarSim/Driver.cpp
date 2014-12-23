#include "stdafx.h"
#include "Driver.h"


Driver::Driver(Car& oCar) : 
moCar(oCar), 
mdTargetSpeed(0.0f)
{
}


Driver::~Driver()
{
}

void Driver::setTargetSpeed(double dTargetSpeed){
	mdTargetSpeed = dTargetSpeed;
}

double Driver::getTargetSpeed() const {
	return mdTargetSpeed;
}

void Driver::onStep(const Car& oCar){
	if (moCar.getSpeed() < mdTargetSpeed/1.1){
		moCar.moMotor.setGas((moCar.moMotor.getGas()+0.1)*1.1);
	}
	else if (moCar.getSpeed() > mdTargetSpeed*1.1){
		moCar.moMotor.setGas(moCar.moMotor.getGas()/1.1);
	}
}