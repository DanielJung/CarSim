#include "stdafx.h"
#include "CarTracker.h"
#include <sstream>

CarTracker::CarTracker() : moFile("track.txt", ios::out)
{
}


CarTracker::~CarTracker()
{
	moFile.close();
}

void CarTracker::onStep(const Car& oCar){
	double dTime = oCar.getTime();
	double dSpeed = oCar.getSpeed()*3.6;
	double dAccel = oCar.getAcceleration();
	double dForce = oCar.getForce();
	double dTorque = oCar.getMotor().getTorque();
	double dFrequency = oCar.getMotor().getFrequency()*60.0;
	double dGas = oCar.getMotor().getGas();
	double dConsumption = oCar.getMotor().getConsumption()/dSpeed*100.0;
	unsigned int iGear = oCar.getGearbox().getCurrentGear();

	stringstream ss;
	ss << dTime << " " << dSpeed << " " << dAccel << " " << dForce << " " << dTorque << " " << dFrequency << " " << dGas << " " << " " << dConsumption << " " << iGear << endl;
	moFile << ss.str();
}