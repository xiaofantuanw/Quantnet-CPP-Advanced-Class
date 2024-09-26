//Subject.hpp
//Author: TengxiaoFan
//This is the source file for subject class and derived counter class
#include "Subject.hpp"

template <typename T, template <typename E, typename Alloc = std::allocator<E>> class Container>
void Subject<T,Container>::Attach(const T& ob)
{//Attach an observer
	obs.push_back(ob);
}

template <typename T, template <typename E, typename Alloc = std::allocator<E>> class Container>
void Subject<T,Container>::Detach()
{//Detach an observer
	obs.pop_front();
}

template <typename T, template <typename E, typename Alloc = std::allocator<E>> class Container>
void Subject<T, Container>::Notify()
{//Notify all the observers for Update function
	for (auto it = obs.begin();it != obs.end();it++)
	{
		(*it)(this->GetCounter());
	}
}

Counter::Counter()
{//Default constructor
	m_value = 0.0;
}

Counter::Counter(double value)
{//Constructor with init value
	m_value = value;
}

void Counter::IncreaseCounter()
{//Increase the counter and notify
	m_value = m_value + 1.0;
	Subject::Notify();
}

void Counter::DecreaseCounter()
{//Decrease the counter and notify
	m_value = m_value - 1.0;
	Subject::Notify();
}

double Counter::GetCounter() const
{//Get the counter value
	return m_value;
}