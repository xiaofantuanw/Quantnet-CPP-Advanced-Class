//This class referenced the class producer on the slides of teacher
//Producer.hpp
// Author: TengxiaoFan
//This is the header file for the producer classs of SychronisedQueue
#ifndef Producer_HPP
#define Producer_HPP
#include "SychronisedQueue.cpp"
#include <string>
#include<thread>
#include <future>
#include <iostream>
#include <chrono>

// Class that produces objects and puts them in a queue
class Producer
{
private:
	int m_id; // The id of the producer
	SychronisedQueue<int>* m_queue; // The pointer of queue to use
	
public:
	// Constructor with id and the queue to use
	Producer(int id, SychronisedQueue<int>* queue)
	{
		m_id = id; 
		m_queue = queue;
	}
	// The thread function fills the queue with data
	void operator() (std::future<void> futureObj)
	{
		int data = 0;
		int count = 0;
		while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
		{
			if (m_queue->size() < 10)
			{
				// Let the customer in the queue
				m_queue->Enqueue(count);
				std::cout << "Customer " << count << " in the queue" << std::endl;
			}
			else
			{
				//customer left
				std::cout << "Customer " << count << " left." << std::endl;
			}
			// Sleep one second
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			count++;
		}	
	}
};

#endif // !Producer_HPP
