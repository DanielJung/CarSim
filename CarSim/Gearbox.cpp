#include "stdafx.h"
#include "Gearbox.h"


Gearbox::Gearbox() : miCurGear(0)
{
	maGearRatio[0] = 3.538;
	maGearRatio[1] = 1.913;
	maGearRatio[2] = 1.392;
	maGearRatio[3] = 1.029;
	maGearRatio[4] = 0.818;
	maGearRatio[5] = 0.700;
}


Gearbox::~Gearbox()
{
}

void Gearbox::setCurrentGear(unsigned int iGear){
	if (iGear > 6){
		throw string("This car has only 6 gears");
	}
	miCurGear = iGear;
}

unsigned int Gearbox::getCurrentGear() const {
	return miCurGear;
}

double Gearbox::getGearRatio(unsigned int iGear) const {
	return maGearRatio[iGear];
}