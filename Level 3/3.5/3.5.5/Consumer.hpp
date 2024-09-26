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
#include <future>
#include "Command.hpp"
#include "Compare.hpp"

// Class that consumes objects from a queue
class Consumer
{
private:
	int m_id; // The id of the consumer
	SychronisedQueue<Command,std::vector<Command>,Compare>* m_queue; // The queue to use
public:
	// Constructor with id and the queue to use
	Consumer(int id, SychronisedQueue<Command, std::vector<Command>, Compare>* queue)
	{
		m_id = id; 
		m_queue = queue;
	}
	// The thread function reads data from the queue
	void operator () (double x)
	{
		bool signal = 1;
		while (signal)
		{
			double s=(m_queue->Dequeue().Execute(x));//Execute the command
			
			if (s!=x)
				signal = 0;
		}
	}
};



#endif
