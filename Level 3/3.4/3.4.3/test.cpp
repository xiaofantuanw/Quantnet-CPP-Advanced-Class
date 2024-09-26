//test.cpp
//Author: TengxiaoFan
//This is the test file for the interaction between future and promise
#include <iostream>
#include <future>

void GetFutureState(std::future<double>& fut)
{ // Thread function
	double t = fut.get(); // Get the result of the future
	// Wait a while
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "Value: " << t << std::endl;//Output the value
}

int main()
{
	std::promise<double> p1;//default(empty shared state)
	std::promise<double> p2(std::move(p1));//Move constructor
	auto fut = p2.get_future();//create a future that is associated with the promise
	// Start thread with new future
	std::thread myThread(GetFutureState, std::ref(fut));
	//set the value of the promise to deliver it into the thread
	p2.set_value(1.1);
	myThread.join();
}