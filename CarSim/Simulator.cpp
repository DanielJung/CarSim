#include "stdafx.h"
#include "Simulator.h"


Simulator::Simulator(Car& oCar, double tBegin, double tEnd, double dt) :
moCar(oCar),
mdTime(tBegin),
mdDT(dt),
miNumSteps((unsigned int)((tEnd-tBegin)/dt))
{
}


Simulator::~Simulator()
{
}
#define A 2.0
#define p 1.20
#define g 9.81

void Simulator::StartSim(std::vector<SimulationListener*>& aCarTracker){
	for (unsigned int i = 0; i < miNumSteps; ++i){
		mdTime += mdDT;

		moCar.setTime(mdTime);

		double FMotor = moCar.getForce();
		double FAir = 0.5*moCar.getCW()*moCar.getSurfaceArea()*p*moCar.getSpeed()*moCar.getSpeed();
		double FRoll = moCar.getRollCoefficient()*g*moCar.getMass();

		double accel = (FMotor - FAir - FRoll) / moCar.getMass()*mdDT;

		moCar.Accelerate(accel);

		for (unsigned int i = 0; i < aCarTracker.size(); ++i){
			aCarTracker[i]->onStep(moCar);
		}
	}
}