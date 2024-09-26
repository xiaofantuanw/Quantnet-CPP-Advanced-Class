//This class referenced the class producer on the slides of teacher
//Producer.hpp
// Author: TengxiaoFan
//This is the header file for the producer classs of SychronisedQueue
#ifndef Producer_HPP
#define Producer_HPP
#include "SychronisedQueue.cpp"
#include <string>
#include <iostream>
#include <chrono>

// Class that produces objects and puts them in a queue
class Producer
{
private:
	int m_id; // The id of the producer
	SychronisedQueue<std::string>* m_queue; // The pointer of queue to use
public:
	// Constructor with id and the queue to use
	Producer(int id, SychronisedQueue<std::string>* queue)
	{
		m_id = id; 
		m_queue = queue;
	}
	// The thread function fills the queue with data
	void operator () ()
	{
		int data = 0;
		int count = 0;
		while (count<10)
		{
			// Produce a string and store in the queue
			std::string str = "Producer: " + std::to_string(m_id) + " data: " + std::to_string(data++);
			m_queue->Enqueue(str);
			std::cout << str << std::endl;
			// Sleep one second
			std::this_thread::sleep_for(std::chrono::seconds(1));
			count++;
		}
	}
};

#endif // !Producer_HPP
