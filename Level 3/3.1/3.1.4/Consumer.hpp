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


// Class that consumes objects from a queue
class Consumer
{
private:
	int m_id; // The id of the consumer
	SychronisedQueue<std::string>* m_queue; // The queue to use
public:
	// Constructor with id and the queue to use
	Consumer(int id, SychronisedQueue<std::string>* queue)
	{
		m_id = id; 
		m_queue = queue;
	}
	// The thread function reads data from the queue
	void operator () ()
	{
		int count = 0;
		while (count<5)
		{
			// Get the data from the queue and print it
			std::cout << "Consumer " << m_id;
			std::cout << " consumed: (" << m_queue->Dequeue() << ")" << std::endl;
			// Make sure we can be interrupted
			count++;
		}
	}
};



#endif
