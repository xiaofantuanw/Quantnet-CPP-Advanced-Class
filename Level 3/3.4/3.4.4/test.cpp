//test.cpp
//Author:TengxiaoFan
//This is a test file for packaged_task
#include <iostream>
#include <future>
#include <queue>
#include <random>

// Thread function 
double compute(double x, double y) 
{ 
	// Wait a while 
	std::default_random_engine dre(42); 
	std::uniform_int_distribution<int> delay(0, 1000); 
	std::this_thread::sleep_for (std::chrono::milliseconds(delay(dre)));
	return std::cos(x) * std::exp(y); 
}

int main()
{
	double x = 0.0; 
	double y = 2.71;
	// A. 'Direct' tasks 
	std::future<double> fut = std::async(compute, x, y);
	// Get the shared data 
	double result = fut.get(); 
	std::cout << "Result: " << result << '\n';

	//Packaged Task
	std::packaged_task<double(double, double)> mytask(compute);
	auto fut2 = mytask.get_future();
	//Start the task (delayed execution)
	mytask(3.0,2.5);
	//Get the result
	std::cout << "Result: " << fut2.get() << '\n';

	//Create a queue of tasks
	std::queue< std::packaged_task<double(double, double)>> qtask;//A queue of tasks
	for (int i = 0;i < 10;i++)
	{
		std::packaged_task<double(double, double)> tmptask(compute);
		qtask.push(std::move(tmptask));//must use move
	}
	//dequeue each task and execute it.
	for (int i=1;i<10;i++)
	{
		std::packaged_task<double(double, double)> tasknow(std::move(qtask.front()));//Dequeue the task
		qtask.pop();
		auto futnow = tasknow.get_future();
		//Start the task
		tasknow(0.0, i * 1.0);
		//Get result
		std::cout << "Result " << i << ": " << futnow.get() << std::endl;
	}

}