//test.cpp
//Authro: TengxiaoFan
//This is the test file for observer and subject pattern
#include "Observer.hpp"
#include "Subject.hpp"
#include <memory>

int main()
{
	//Make obs
	std::shared_ptr<Observer> ob1(new LongFormat);
	std::shared_ptr<Observer> ob2(new DoubleFormat);
	Counter c(10.1);
	//Test the obs
	c.Attach(ob1);
	c.Attach(ob2);
	c.IncreaseCounter();
	c.DecreaseCounter();
	c.Detach();
	c.DecreaseCounter();
}