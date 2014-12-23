#pragma once

#include "Gearbox.h"
#include "Motor.h"

class ShiftControl;
class Driver;

class Car
{
	friend Driver;
public:
	Car(double dMass, double dCW, double dRollCoefficient, double dSurfaceArea, double dAxleRatio, double dTireSize);
	~Car();

	void Accelerate(double dv);
	void setTime(double dTime);

	double getMass() const;
	double getCW() const;
	double getRollCoefficient() const;
	double getSurfaceArea() const;
	double getAxleRatio() const;
	double getTireSize() const;

	double getSpeed() const;
	double getAcceleration() const;
	double getTime() const;

	double getForce() const;

	const Gearbox& getGearbox() const;
	const Motor& getMotor() const;
private:
	double mdMass;
	double mdCW;
	double mdRollCoefficient;
	double mdSurfaceArea;
	double mdAxleRatio;
	double mdTireSize;

	double mdSpeed;
	double mdAcceleration;
	double mdTime;

	Motor moMotor;
	Gearbox moGearbox;
	ShiftControl* moShiftControl;

	bool mbOnShift;
};

