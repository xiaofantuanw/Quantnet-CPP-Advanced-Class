//test.cpp
//Author: TengxiaoFan
//This is the test file for a priority queue of commands
#include <functional>
#include <thread>
#include <iostream>
#include <numeric>
#include<queue>


using FunctionType = std::function<double(double)>;

class Command 
{//Command class
private: 
	long ID; // priority of command 
	FunctionType algo;
public: 
	Command(const FunctionType& algorithm, long priority) : algo(algorithm), ID(priority) {}
	void Execute(double x) const
	{ // Introduce delay to simulate a heavy algorithm 
		std::this_thread::sleep_for (std::chrono::milliseconds(5000)); 
		std::cout << algo(x) << '\n'; 
	}
	int priority() const 
	{//return the priority of the command
		return ID; 
	}
};

int main()
{
	//Compare function, smaller id will execute first
	auto cmp = [](const Command& a, const Command& b) {return (a.priority() > b.priority());};
	//Build four commands
	Command c1([](double x) {return 2 * x;}, 1333);
	Command c2([](double x) {return x;}, 1331);
	Command c3([](double x) {return std::sqrt(x);}, 1300);
	Command c4([](double x) {return std::exp(x);}, 1451);
	//Build the priority queue and push in the elements
	std::priority_queue<Command,std::vector<Command>,decltype(cmp)> q1(cmp);
	q1.push(c1);
	q1.push(c2);
	q1.push(c3);
	q1.push(c4);
	//While the queue is not empty, execute
	while (!q1.empty())
	{
		q1.top().Execute(0.3);
		q1.pop();
	}
	return 0;
}