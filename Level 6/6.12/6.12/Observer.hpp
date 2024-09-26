//Obserever.hpp
//Author: TengxiaoFan
//This is the header file for observer class and derived class
#ifndef Observer_HPP
#define Observer_HPP

class Propagator;
class Observer
{//Observer base class
public:
	//Pure virtual ubdate
	virtual double Update(Propagator* s) = 0;
};

class LongFormat :public Observer
{//Long format
private:
	double m_label;
public:
	//Update function
	double Update(Propagator* s);
};

class DoubleFormat :public Observer
{//Double format
private:
	double m_label;
public:
	//Update function
	double Update(Propagator* s);
};


#endif // !Observer_HPP
