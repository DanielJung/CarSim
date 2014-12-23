#pragma once
class Gearbox
{
public:
	Gearbox();
	~Gearbox();

	void setCurrentGear(unsigned int iGear);
	unsigned int getCurrentGear() const;

	double getGearRatio(unsigned int iGear) const;
private:
	unsigned int miCurGear;

	double maGearRatio[6];
};

