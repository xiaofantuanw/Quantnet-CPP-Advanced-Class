//Observer.cpp
//Author: TengxiaoFan
//This is the source file for observer class and derived class
#include "Subject.hpp"
#include "Observer.hpp"
#include <iostream>

void LongFormat::Update(Subject* s)
{//get the current counter value from the Observable object (cast to Counter) and put it in the label.
	Counter* c = dynamic_cast<Counter*>(s);//Transform to counter*
	m_label = c->GetCounter();
	printf("Long Format: %.0f\n", m_label);
}

void DoubleFormat::Update(Subject* s)
{//get the current counter value from the Observable object (cast to Counter) and put it in the label.
	Counter* c = dynamic_cast<Counter*>(s);//transform to counter*
	m_label = c->GetCounter();
	printf("Double Format: %.2f\n", m_label);
}