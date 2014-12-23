#pragma once
class Motor
{
public:
	Motor(double dMinFrequency, double dMaxFrequency);
	~Motor();

	void setFrequency(double dFrequency);
	double getFrequency() const;

	void setGas(double dGas);
	double getGas() const;

	double getTorque() const;

	double getMinFrequency() const;
	double getMaxFrequency() const;

	double getConsumption() const;
	double getConsumption(double dFrequency, double dTorque) const;
private:
	double mdFrequency;
	double mdGas;

	double mdMinFrequency;
	double mdMaxFrequency;
	
};

