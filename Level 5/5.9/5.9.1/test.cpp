//test.cpp
//Author: TengxiaoFan
//This is a test file for basic functionalities of signal and slot
#include <boost\signals2.hpp>
#include <iostream>
#include <functional>

void Slot1()
{//free function
	std::cout << "Slot 1: free function \n";
}

class Slot3
{
public:
	static void op()
	{//static member function
		std::cout << "Slot 3: static member function\n";
	}
};

class Slot4
{//instance level member function
public:
	void operator() ()
	{
		std::cout << "Slot 4: Instance-level member function\n";

	}
};

class Slot5
{
public:
	void op()
	{//Binded member function
		std::cout << "Slot 5: Binded member function\n";
	}
};

struct MyStruct 
{
	double val;
	MyStruct(double v) { val = v; }
	void modify(double newValue) 
	{ 
		val = newValue; 
		std::cout << "A third slot " << val << std::endl;
	}
};

int main()
{
	auto Slot2 = []() 
	{//stored lambda
		std::cout << "Slot 2: stored lambda function\n";
	};

	//Create a signal
	boost::signals2::signal<void()> signal;
	
	//Connect the signals
	signal.connect(&Slot1);
	signal.connect(Slot2);
	signal.connect(Slot3::op);
	Slot4 slot4;
	signal.connect(slot4);
	Slot5 slot5;
	signal.connect(std::bind(&Slot5::op, slot5));

	//Connect based on MyStruct::modify
	MyStruct s(10);
	signal.connect(std::bind(&MyStruct::modify, s, 1));

	//Emit the signal
	signal();

	//Disconnect some signals
	signal.disconnect(&Slot1);
	signal.disconnect(Slot2);
	signal.disconnect(Slot3::op);

	//Emit again
	signal();

	//Test connect signal to signal.
	// Define potential emitters 
	boost::signals2::signal<void()> signalA; 
	boost::signals2::signal<void()> signalB; 
	boost::signals2::signal<void()> signalC; 
	boost::signals2::signal<void()> signalD;
	
	// Define slots 
	auto slotB = []() {std::cout << "Slot B called by B\n " << std::endl; }; 
	auto slotC = []() {std::cout << "Slot C called by C\n " << std::endl; }; 
	auto slotD1 = []() {std::cout << "Slot D1 called by D\n " << std::endl; }; 
	auto slotD2 = []() {std::cout << "Sloat D2 called by D\n " << std::endl; };

	//Signal B connected to Signal A
	signalA.connect(signalB);
	//Signal C connected to Signal B
	signalB.connect(signalC);
	//Signal D connected to SignalC
	signalC.connect(signalD);
	//Slot B connected to signal B
	signalB.connect(slotB);
	//Slot C connected to signal C
	signalC.connect(slotC);
	//Slot D1 connected to signal D
	signalD.connect(slotD1);
	//Slot D2 connected to signal D
	signalD.connect(slotD2);

	//emit signal A
	signalA();//All slots called
	//signalB.disconnect(&signalC);
	//Cannot be disconnected since signalC is connected with sth
	
	//Disconnect signal C from signal B
	signalD.disconnect(slotD1);
	signalD.disconnect(slotD2);
	signalC.disconnect(slotC);
	signalC.disconnect(&signalD);
	signalB.disconnect(&signalC);

	//Emit signal A again.
	signalA();//Only slot B called

}