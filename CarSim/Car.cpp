#include "stdafx.h"
#include "Car.h"
#include "ShiftControl.h"


Car::Car(double dMass, double dCW, double dRollCoefficient, double dSurfaceArea, double dAxleRatio, double dTireSize) :
mdMass(dMass),
mdCW(dCW),
mdRollCoefficient(dRollCoefficient),
mdSurfaceArea(dSurfaceArea),
mdAxleRatio(dAxleRatio),
mdTireSize(dTireSize),
mdSpeed(5.0),
mdAcceleration(0.0f),
mdTime(0.0),
moMotor(500.0/60.0, 6000.0/60.0),
moGearbox(),
mbOnShift(false)
{
	moShiftControl = new ShiftControl(*this);
}


Car::~Car()
{
	delete moShiftControl;
}

void Car::Accelerate(double dv) {
	mdAcceleration = dv;
	mdSpeed += dv;

	moGearbox.setCurrentGear(moShiftControl->onShift());

	moMotor.setFrequency(mdSpeed*mdAxleRatio*moGearbox.getGearRatio(moGearbox.getCurrentGear())/(2*M_PI*mdTireSize));
}

void Car::setTime(double dTime){
	mdTime = dTime;
}

double Car::getMass() const {
	return mdMass;
}

double Car::getCW() const {
	return mdCW;
}

double Car::getRollCoefficient() const {
	return mdRollCoefficient;
}

double Car::getSurfaceArea() const {
	return mdSurfaceArea;
}
double Car::getAxleRatio() const {
	return mdAxleRatio;
}

double Car::getTireSize() const {
	return mdTireSize;
}

double Car::getSpeed() const {
	return mdSpeed;
}

double Car::getAcceleration() const {
	return mdAcceleration;
}

double Car::getTime() const {
	return mdTime;
}

double Car::getForce() const {
	return moMotor.getTorque()*moGearbox.getGearRatio(moGearbox.getCurrentGear())*mdAxleRatio / mdTireSize;
}

const Gearbox& Car::getGearbox() const {
	return moGearbox;
}

const Motor& Car::getMotor() const {
	return moMotor;
}