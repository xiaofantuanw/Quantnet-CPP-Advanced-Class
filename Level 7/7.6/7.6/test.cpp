//test.cpp
//Authro: TengxiaoFan
//This is the test file for observer and subject pattern
#include "Subject.hpp"
#include <memory>

int main()
{
	//Make obs
	//Long format
	auto obLongFormat = [](double d)
	{//get the current counter value from the Observable object (cast to Counter) and put it in the label.
		//Counter* c = dynamic_cast<Counter*>(s);//Transform to counter*
		//double m_label = c->GetCounter();
		printf("Long Format: %.0f\n", d);
	};
	//Double format
	auto obDoubleFormat = [](double d)
	{//get the current counter value from the Observable object (cast to Counter) and put it in the label.
		//Counter* c = dynamic_cast<Counter*>(s);//transform to counter*
		//double m_label = c->GetCounter();
		printf("Double Format: %.2f\n", d);
	};
	Counter c(10.1);//Counter is the derived class of template
	//Test the obs
	//Attach two observers
	c.Attach(obLongFormat);
	c.Attach(obDoubleFormat);
	//Increase and decrease counters
	c.IncreaseCounter();
	c.DecreaseCounter();
	c.Detach();//Detach one observer
	c.DecreaseCounter();
}