//Command.cpp
//Author: TengxiaoFan
//This is the Command class
#ifndef Command_HPP
#define Command_HPP
#include <functional>
#include <chrono>
#include <thread>

using FunctionType = std::function<double(double)>;

class Command
{//Command class
private:
	long ID; // priority of command 
	FunctionType algo;
public:
	Command(const FunctionType& algorithm, long priority) : algo(algorithm), ID(priority) {}
	double Execute(double x) const
	{ // Introduce delay to simulate a heavy algorithm 
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << algo(x) << '\n';
		return algo(x);
	}
	int priority() const
	{//return the priority of the command
		return ID;
	}
};
#endif