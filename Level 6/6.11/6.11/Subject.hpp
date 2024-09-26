//Subject.hpp
//Author: TengxiaoFan
//This is the header file for subject class and derived counter class
#ifndef Subject_HPP
#define Subject_HPP
#include <list>
#include <memory>

class Observer;
class Subject
{//Subject class
private:
	std::list<std::shared_ptr<Observer>> obs;
public:
	virtual void Attach(std::shared_ptr<Observer> ob);//Attach an observer
	virtual void Detach();//Detach an observer
	virtual void Notify();//Iterate through all the observers and do ob.Update()
};

class Counter :public Subject
{
private:
	double m_value;
public:
	//Constructors and destructors
	Counter();
	Counter(double value);
	//GetCounter function
	double GetCounter() const;
	//Increase and Decrease counter
	void IncreaseCounter();
	void DecreaseCounter();

};


#endif