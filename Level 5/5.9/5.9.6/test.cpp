//test.cpp
//Author: TengxiaoFan
//This is a test file for layered communication with signals
#include <boost\signals2.hpp>
#include <iostream>
#include <functional>
#include <numeric>

void slotExterior(double& d) 
{//Slot of exterior layer
	d = -d;
}

void slotHardware(double& d)
{//Slot of hardware layer
	if (d < 2 || d>4)
		d = 3;
}

void slotData(double& d)
{//Slot of data layer
	d = d * 2 + 3;
}

void slotCommunication(double& d)
{//Slot of communication layer
	std::cout << "Result is: " << d << std::endl;
}

int main()
{
	//The four layers
	boost::signals2::signal<void(double& d)> signalExterior;//Exterior (model as main() ): where the data is initialised.
	boost::signals2::signal<void(double& d)> signalHardware;//Hardware: data is checked to be in the range [2,4]; if not in the range it is set to the value 3.
	boost::signals2::signal<void(double& d)> signalData;//Data: the data is modified by an algorithm.
	boost::signals2::signal<void(double& d)> signalCommunication;//Communication: the data is formatted and printed.
	//Connect the layers
	signalExterior.connect(0, &slotExterior);
	signalExterior.connect(1, signalHardware);
	signalHardware.connect(0, &slotHardware);
	signalHardware.connect(1, signalData);
	signalData.connect(0, &slotData);
	signalData.connect(1, signalCommunication);
	signalCommunication.connect(0, &slotCommunication);
	//Emit the signal
	double value = -3.7;
	signalExterior(value);
	//result: 10.4
}