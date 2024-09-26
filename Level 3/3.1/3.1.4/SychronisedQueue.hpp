//SychronisedQueue.hpp
// Author: TengxiaoFan
//This is the header file for class SychronisedQueue, a thread safe FIFO queue
#ifndef SychronisedQueue_HPP
#define SychronisedQueue_HPP
#include <queue>
#include <mutex>

template <typename T>
class SychronisedQueue
{
private:
	std::queue<T> m_queue; // stl queue, store data
	std::mutex m_mutex; // The mutex 
	std::condition_variable m_cond; // The condition variable
public:
	//Constructors and destructors
	SychronisedQueue();
	virtual ~SychronisedQueue()=default;
	SychronisedQueue(const SychronisedQueue<T>& source) = default;//copy constructor
	SychronisedQueue(SychronisedQueue<T>&& source) = default;//move constructor
	//Assignment operator and move operator
	SychronisedQueue& operator= (const SychronisedQueue<T>& source) = default;
	SychronisedQueue& operator= (SychronisedQueue<T>&& source) = default;

	// Add data to the queue and notify others
	void Enqueue(const T& data);
	// Get data from the queue. Wait for data if not available
	T Dequeue();
};


#endif // !SychronisedQueue_HPP
