#include "stdafx.h"
#include "Motor.h"

#define A0 -0.033640557453369
#define A1 3.721828048006285
#define A2 7.963813900057554

#define Z1 -4.306945523138405e-05
#define Z2 3.993870063986087e-06
#define Z3 0
#define Z4 1.673467157918242e-05
#define Z5 -1.033177282188004e-03
#define Z6 -2.822621118936971e-07
#define Z7 -5.379962611773060e-07
#define Z8 8.689070823699555e-09
#define Z9 1.227489624623267e-01
#define Z10 -2.486244216123410e-02
#define Z11 -7.144009124601609e-14
#define Z12 1.451809345148319e-01
#define Z13 -1.147912376674705e-14
#define Z14 7.531194113084223e-02

#define SCALE_X 62.5
#define SCALE_Y 5



Motor::Motor(double dMinFrequency, double dMaxFrequency) : 
mdFrequency(dMinFrequency),
mdGas(1.0),
mdMinFrequency(dMinFrequency),
mdMaxFrequency(dMaxFrequency)
{
	cout << "Starting Motor. Min: " << mdMinFrequency << " | Max: " << mdMaxFrequency << endl;
}


Motor::~Motor()
{
}

void Motor::setFrequency(double dFrequency){
	if (dFrequency > mdMaxFrequency){
		throw string("Your motor caught fire cause of too high frequency");
	}
	else if (dFrequency < mdMinFrequency){
		throw string("Your motor ran out cause of too low frequency");
	}
	mdFrequency = dFrequency;
}

double Motor::getFrequency() const {
	return mdFrequency;
}

void Motor::setGas(double dGas){
	if (dGas < 0.0){
		mdGas = 0.0;
	}
	else if (dGas>1.0){
		mdGas = 1.0;
	}
	else {
		mdGas = dGas;
	}
}

double Motor::getGas() const {
	return mdGas;
}

double Motor::getTorque() const {
	return mdGas*(A0*mdFrequency*mdFrequency + A1*mdFrequency + A2+10.0);
}

double Motor::getMinFrequency() const {
	return mdMinFrequency;
}

double Motor::getMaxFrequency() const {
	return mdMaxFrequency;
}

double Motor::getConsumption(double dFrequency, double dTorque) const {
	return (Z1*pow(dFrequency, 2.0) +
		Z2*dFrequency +
		Z3 + 
		Z4*pow(dTorque, 2) +
		Z5*dTorque +
		Z6*pow(dFrequency, 2.0)*dTorque +
		Z7*dFrequency*pow(dTorque, 2.0) +
		Z8*pow(dFrequency, 2.0)*pow(dTorque, 2.0) +
		Z9*exp(dFrequency / SCALE_X) +
		Z10*exp(-dFrequency / SCALE_X) +
		Z11*exp(dTorque / SCALE_Y) +
		Z12*exp(-dTorque / SCALE_Y) +
		Z13*exp(dFrequency / SCALE_X*dTorque / SCALE_Y) +
		Z14*exp(-dFrequency / SCALE_X*dTorque / SCALE_Y));
}

double Motor::getConsumption() const {
	return getConsumption(getFrequency(), getTorque())*getFrequency()*getTorque()/1000.0*2.0*M_PI;
}