//test.cpp
// Author: TengxiaoFan
//This is the test file for class SychronisedQueue and its Consumer and Producer

#include "SychronisedQueue.cpp"
#include <iostream>
#include "Consumer.hpp"
#include "Producer.hpp"
#include <thread>

int main()
{
	// The shared queue
	SychronisedQueue<std::string> queue;
	// Create producers
	std::thread producers[3];
	for (int i = 0; i < 3; i++)
	{
		Producer p(i, &queue);
		producers[i]=std::thread(p);
	}
	// Create consumers
	std::thread consumers[3];
	for (int i = 0; i < 3; i++)
	{
		Consumer c(i, &queue);
		consumers[i]=std::thread(c);
	}
	
	for (int i = 0;i < 3;i++)
	{
		producers[i].join();
		consumers[i].join();
	}
}
