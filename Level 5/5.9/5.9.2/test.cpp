//test.cpp
//Author: TengxiaoFan
//This is a test file for basic functionalities of slot groups
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
	signal.connect(0,&Slot1);
	signal.connect(1,Slot2);
	signal.connect(1,Slot3::op);//same slot group as slot2
	Slot4 slot4;
	signal.connect(0,slot4);//prior than 1
	Slot5 slot5;
	signal.connect(2,std::bind(&Slot5::op, slot5));

	//Connect based on MyStruct::modify
	MyStruct s(10);
	signal.connect(1,std::bind(&MyStruct::modify, s, 1));//prior to slot5

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
	signalA.connect(0,signalB);
	//Signal C connected to Signal B
	signalB.connect(0,signalC);
	//Signal D connected to SignalC
	signalC.connect(0,signalD);
	//Slot B connected to signal B
	signalB.connect(1,slotB);
	//Slot C connected to signal C
	signalC.connect(1,slotC);
	//Slot D1 connected to signal D
	signalD.connect(1,slotD1);
	//Slot D2 connected to signal D
	signalD.connect(0,slotD2);

	//emit signal A
	signalA();//All slots called
	//Order:D2,D1,C,B

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