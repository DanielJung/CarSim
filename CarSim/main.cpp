// CarSim.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Car.h"
#include "CarTracker.h"
#include "Simulator.h"
#include "Driver.h"
#include <sstream>


int _tmain(int argc, _TCHAR* argv[])
{
	Car car(1100.0, 0.287, 0.02, 2.0, 2.87, 0.27);
	CarTracker tracker;
	Simulator sim(car, 0.0, 60.0, 0.001);
	Driver driver(car);
	driver.setTargetSpeed(160.0 / 3.6);

	vector<SimulationListener*> aSimListener;
	aSimListener.push_back(&tracker);
	aSimListener.push_back(&driver);

	try{
		sim.StartSim(aSimListener);
	}
	catch (string s){
		cout << "Exception. " << s << endl;
	}
	system("pause");
	return 0;
}

