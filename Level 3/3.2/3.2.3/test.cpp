#include "ActiveObject.hpp"
#include <iostream>

void f()
{//A function output
	std::cout << "My free function." << std::endl;
}

class F2
{
public:
	void operator () ()
	{//A function obj output
		std::cout << "My function object." << std::endl;

	}
};

int main()
{
	auto f3 = []()
	{
		//A lambda function output
		std::cout << "My lambda function." << std::endl;
	};
	F2 f2{};
	std::thread th(f);
	std::thread th2;//a thread with no associated thread function
	std::thread th3(f2);
	std::thread th4(f3);
	try//use this block to build an object
	{
		ActiveObject ao(std::move(th));
		ao.associated();
	}
	catch (int ex)
	{
		std::cout << "Not associated " << ex << std::endl;
	}
	
	try//use this block to build an object
	{
		ActiveObject ao2(std::move(th2));
		ao2.associated();
	}
	catch (int ex)
	{
		std::cout << "Not associated "<<ex << std::endl;//This line will print here
	}

	

	try//use this block to build an object
	{
		ActiveObject ao3(std::move(th3));
		ao3.associated();
	}
	catch (int ex)
	{
		std::cout << "Not associated " << ex << std::endl;
	}
	try//use this block to build an object
	{
		ActiveObject ao4(std::move(th4));
		ao4.associated();
	}
	catch (int ex)
	{
		std::cout << "Not associated " << ex << std::endl;
	}
	
}