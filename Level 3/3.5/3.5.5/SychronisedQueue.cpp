//SychronisedQueue.hpp
// Author: TengxiaoFan
//This is the source file for class SychronisedQueue, a thread safe FIFO queue
#ifndef SychronisedQueue_CPP
#define SychronisedQueue_CPP
#include "SychronisedQueue.hpp"
//number of threads
const int THREADCONSUMER=2;
const int THREADPRODUCER=3;
template<
	class T,
	class Container,
	class Compare>
SychronisedQueue<T,Container,Compare>::SychronisedQueue()
{
	//Default Constructor
}

template<
	class T,
	class Container,
	class Compare>
void SychronisedQueue<T,Container,Compare>::Enqueue(const T& data)
{
	// lock the mutex
	std::unique_lock<std::mutex> lock(m_mutex);
	// Add data
	m_queue.push(data);
	m_cond.notify_one();
}//Lock released


template<
	class T,
	class Container,
	class Compare>
T SychronisedQueue<T,Container,Compare>::Dequeue()
{
	// lock the mutex
	std::unique_lock<std::mutex> lock(m_mutex);
	// When there is no data, wait till someone fills it
	// Lock is automatically released in the wait and active again after the wait
	while (m_queue.empty()) m_cond.wait(lock);
	// get the data
	T result = m_queue.top(); //The highest priority one 
	m_queue.pop();
	return result;
}

#endif // !SychronisedQueue_CPP
