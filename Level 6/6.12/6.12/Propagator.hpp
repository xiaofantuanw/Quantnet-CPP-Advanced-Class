//Propagator.hpp
//Author: TengxiaoFan
//This is the header file for Propagator class, which updates the value of a tree
#ifndef Propagator_HPP
#define Propagator_HPP
#include <list>
#include <memory>

class Propagator
{//Propagator class
private:
	std::list<std::shared_ptr<Propagator>> obs;// A list of observants
public:
	//Pure virtual update func
	virtual void Update(Propagator* p) = 0;
	//Add and delete
	void Addob(std::shared_ptr<Propagator> ob);
	void Deleteob();
	//Notify all 
	void Notifyob();
};

class Counter :public Propagator
{//Counter class
private:
	double m_value;//private value
public:
	//Ctor
	Counter();
	Counter(double value);
	//Update
	void Update(Propagator* p);
	double GetCounter() const;
	//Increase and Decrease counter
	void IncreaseCounter();
	void DecreaseCounter();
};

#endif // !Propagator_HPP
