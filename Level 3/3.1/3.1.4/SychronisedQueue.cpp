//SychronisedQueue.hpp
// Author: TengxiaoFan
//This is the source file for class SychronisedQueue, a thread safe FIFO queue
#ifndef SychronisedQueue_CPP
#define SychronisedQueue_CPP
#include "SychronisedQueue.hpp"

template <typename T>
SychronisedQueue<T>::SychronisedQueue()
{
	//Default Constructor
}

template <typename T>
void SychronisedQueue<T>::Enqueue(const T& data)
{
	// lock the mutex
	std::unique_lock<std::mutex> lock(m_mutex);
	// Add data
	m_queue.push(data);
	m_cond.notify_one();
}//Lock released


template <typename T>
T SychronisedQueue<T>::Dequeue()
{
	// lock the mutex
	std::unique_lock<std::mutex> lock(m_mutex);
	// When there is no data, wait till someone fills it
	// Lock is automatically released in the wait and active again after the wait
	while (m_queue.size() == 0) m_cond.wait(lock);
	// get the data
	T result = m_queue.front(); //FIFO
	m_queue.pop();
	return result;
}

#endif // !SychronisedQueue_CPP
