//This class referenced the class producer on the slides of teacher
//Producer.hpp
// Author: TengxiaoFan
//This is the header file for the producer classs of SychronisedQueue
#ifndef Producer_HPP
#define Producer_HPP
#include "SychronisedQueue.cpp"
#include <string>
#include <iostream>
#include <future>
#include <chrono>

// Class that produces objects and puts them in a queue
class Producer
{
private:
	int m_id; // The id of the producer
	SychronisedQueue<Command, std::vector<Command>, Compare>* m_queue; // The pointer of queue to use
public:
	// Constructor with id and the queue to use
	Producer(int id, SychronisedQueue<Command, std::vector<Command>, Compare>* queue)
	{
		m_id = id; 
		m_queue = queue;
	}
	// The thread function fills the queue with data
	void operator () ()
	{
		int count = 0;
		while (count<10)
		{
			// Produce a command and store in the queue
			Command c([](double x) {return x;}, 1000 - count);
			m_queue->Enqueue(c);
			std::cout << "Enqueue: " <<count<< std::endl;
			// Sleep one second
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			count++;
		}
		count = 0;
		while (count < THREADCONSUMER / THREADPRODUCER + 1)
		{
			Command c([&](double x) { return x + 1.0;}, 0);//stop execution with lowest priority
			m_queue->Enqueue(c);
			std::cout << "Enqueue: End signal." << std::endl;
			count++;
		}
	}
};

#endif // !Producer_HPP
