//Subject.hpp
//Author: TengxiaoFan
//This is the header file for subject class and derived counter class
#ifndef Subject_HPP
#define Subject_HPP
#include <list>
#include <memory>
#include <functional>
#include <queue>

template <typename T, template <typename E, typename Alloc = std::allocator<E>> class Container = std::deque>
class Subject
{//Subject class, template template
private:
	Container<T> obs;
public:
	virtual void Attach(const T& ob);//Attach an observer
	virtual void Detach();//Detach an observer
	virtual void Notify();//Iterate through all the observers and do ob.Update()
	virtual double GetCounter() const = 0;
};


class Counter :public Subject< std::function<void(double)>>
{
private:
	double m_value;
public:
	//Constructors and destructors
	Counter();
	Counter(double value);
	//GetCounter function
	double GetCounter() const override;
	//Increase and Decrease counter
	void IncreaseCounter();
	void DecreaseCounter();

};


#endif