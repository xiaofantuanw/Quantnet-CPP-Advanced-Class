//test.cpp
//Author: TengxiaoFan
//This is the test function for a barber-customer system
#include <iostream>
#include "Consumer.hpp"
#include "Producer.hpp"
#include "SychronisedQueue.cpp"
#include <thread>
#include <future>

int main()
{
	// The shared queue
	SychronisedQueue<int> queue;
	//Initialize the producer and consumer
	int id = 0;
	Producer p(id, &queue);
	Consumer c(id, &queue);

	//In order to stop the process
	std::promise < void > exitSignal1;
	std::future < void > futureObj1 = exitSignal1.get_future();
	std::promise < void > exitSignal2;
	std::future < void > futureObj2 = exitSignal2.get_future();

	//Threads
	std::thread producer(p, std::move(futureObj1));
	std::thread consumer(c, std::move(futureObj2));
	std::this_thread::sleep_for(std::chrono::seconds(10));//wait for 10 seconds to stop

	std::cout << "Asking Thread Producer to Stop" << std::endl;
	exitSignal1.set_value();
	std::cout << "Asking Thread Consumer to Stop" << std::endl;
	exitSignal2.set_value();
	producer.join();
	consumer.join();

}