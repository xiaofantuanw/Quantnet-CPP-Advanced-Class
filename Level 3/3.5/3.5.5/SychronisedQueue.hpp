//SychronisedQueue.hpp
// Author: TengxiaoFan
//This is the header file for class SychronisedQueue, a thread safe FIFO queue
#ifndef SychronisedQueue_HPP
#define SychronisedQueue_HPP
#include <queue>
#include <mutex>

template<
	class T,
	class Container = std::vector<T>,
	class Compare = std::less<typename Container::value_type>>
class SychronisedQueue
{
private:
	std::priority_queue<T,Container,Compare> m_queue; // stl queue, store data
	std::mutex m_mutex; // The mutex 
	std::condition_variable m_cond; // The condition variable
public:
	//Constructors and destructors
	SychronisedQueue();
	virtual ~SychronisedQueue()=default;
	SychronisedQueue(const SychronisedQueue<T, Container, Compare>& source) = default;//copy constructor
	SychronisedQueue(SychronisedQueue<T, Container, Compare>&& source) = default;//move constructor
	//Assignment operator and move operator
	SychronisedQueue& operator= (const SychronisedQueue< T, Container, Compare > & source) = default;
	SychronisedQueue& operator= (SychronisedQueue<T, Container, Compare>&& source) = default;

	// Add data to the queue and notify others
	void Enqueue(const T& data);
	// Get data from the queue. Wait for data if not available
	T Dequeue();
};


#endif // !SychronisedQueue_HPP
