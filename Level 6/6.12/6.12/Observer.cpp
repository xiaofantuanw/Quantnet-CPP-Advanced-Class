//Observer.cpp
//Author: TengxiaoFan
//This is the source file for observer class and derived class
#include "Propagator.hpp"
#include "Observer.hpp"
#include <iostream>

double LongFormat::Update(Propagator* s)
{//get the current counter value from the Observable object (cast to Counter) and put it in the label.
	Counter* c = dynamic_cast<Counter*>(s);//Transform to counter*
	m_label = c->GetCounter();
	printf("Long Format: %.0f\n", m_label);
	return m_label;
}

double DoubleFormat::Update(Propagator* s)
{//get the current counter value from the Observable object (cast to Counter) and put it in the label.
	Counter* c = dynamic_cast<Counter*>(s);//transform to counter*
	m_label = c->GetCounter();
	printf("Double Format: %.2f\n", m_label);
	return m_label;
}