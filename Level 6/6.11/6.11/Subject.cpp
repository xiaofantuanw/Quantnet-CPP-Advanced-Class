//Subject.hpp
//Author: TengxiaoFan
//This is the source file for subject class and derived counter class
#include "Subject.hpp"
#include "Observer.hpp"

void Subject::Attach(std::shared_ptr<Observer> ob)
{//Attach an observer
	obs.push_back(ob);
}

void Subject::Detach()
{//Detach an observer
	obs.pop_front();
}

void Subject::Notify()
{//Notify all the observers for Update function
	for (auto it = obs.begin();it != obs.end();it++)
	{
		(*it)->Update(this);
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