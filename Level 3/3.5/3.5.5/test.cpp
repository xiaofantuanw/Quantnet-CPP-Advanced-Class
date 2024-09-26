//test.cpp
// Author: TengxiaoFan
//This is the test file for class SychronisedQueue and its Consumer and Producer

#include "SychronisedQueue.cpp"
#include <iostream>
#include "Consumer.hpp"
#include "Producer.hpp"
#include <thread>
#include <future>

int main()
{
	double x = 0.1;
	// The shared queue
	SychronisedQueue<Command, std::vector<Command>, Compare> queue;
	//stop signal
	//std::promise<bool> stopsignal;
	//std::future<bool> stopfuture = stopsignal.get_future();
	//stopsignal.set_value(1);
	//std::cout << std::boolalpha << stopfuture.valid();
	// Create producers
	std::thread producers[THREADPRODUCER];
	for (int i = 0; i < THREADPRODUCER; i++)
	{
		Producer p(i, &queue);
		//p();
		producers[i]=std::thread(p);
	}
	// Create consumers
	std::thread consumers[THREADCONSUMER];
	for (int i = 0; i < THREADCONSUMER; i++)
	{
		Consumer c(i, &queue);
		//c(x);
		consumers[i]=std::thread(c,x);
	}
	
	//Join the threads
	for (int i = 0;i < THREADPRODUCER;i++)
	{
		producers[i].join();
	}
	for (int i = 0;i < THREADCONSUMER;i++)
	{
		consumers[i].join();
	}
}
