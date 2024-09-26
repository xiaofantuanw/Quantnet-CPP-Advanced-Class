//This class referenced the class producer on the slides of teacher
//Consumer.hpp
// Author: TengxiaoFan
//This is the header file for the consumer classs of SychronisedQueue
#ifndef Consumer_HPP
#define Consumer_HPP
#include "SychronisedQueue.cpp"
#include <string>
#include <iostream>
#include <chrono>
#include <atomic>
#include <random>
#include <future>
#include <thread>


// Class that consumes objects from a queue
class Consumer
{
private:
	int m_id; // The id of the consumer
	SychronisedQueue<int>* m_queue; // The queue to use

public:
	// Constructor with id and the queue to use
	Consumer(int id, SychronisedQueue<int>* queue)
	{
		m_id = id; 
		m_queue = queue;
	}

	// The thread function reads data from the queue
	void operator() (std::future<void> futureObj)
	{
		while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
		{
			// Get the data from the queue and print it
			//std::cout << "Consumer " << m_id;
			int customerid = m_queue->Dequeue();
			std::cout << "Service starts, customer " << customerid << "." << std::endl;
			//Generate a random time to wait
			std::random_device rd;
			std::default_random_engine eng(rd());
			std::uniform_int_distribution<int> distr(5, 50);
			int sleep_time = distr(eng);
			std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time*10));
			// Make sure we can be interrupted
			std::cout << "Service finished, customer " << customerid << ", time: " << sleep_time << std::endl;
		}
	}

};



#endif
