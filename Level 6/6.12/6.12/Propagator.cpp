//Propagator.cpp
//Author: TengxiaoFan
//This is the source file for Propagator class, which updates the value of a tree
#include "Propagator.hpp"
#include "Observer.hpp"

void Propagator::Addob(std::shared_ptr<Propagator> ob)
{
	obs.push_back(ob);
}

void Propagator::Deleteob()
{
	obs.pop_front();
}

void Propagator::Notifyob()
{
	for (auto it = obs.begin();it != obs.end();it++)
	{
		(*it)->Update(this);//Update
		(*it)->Notifyob();//Notify the observants of the observant
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

double Counter::GetCounter() const
{//Get the counter value
	return m_value;
}

void Counter::IncreaseCounter()
{//Increase the counter and notify
	m_value = m_value + 1.0;
	Propagator::Notifyob();
}

void Counter::DecreaseCounter()
{//Decrease the counter and notify
	m_value = m_value - 1.0;
	Propagator::Notifyob();
}

void Counter::Update(Propagator* p)
{
	std::shared_ptr<Observer> ob (new LongFormat);
	m_value=ob->Update(p);
}