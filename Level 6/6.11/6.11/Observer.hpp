//Obserever.hpp
//Author: TengxiaoFan
//This is the header file for observer class and derived class
#ifndef Observer_HPP
#define Observer_HPP

class Subject;
class Observer
{//Observer base class
public:
	//Pure virtual ubdate
	virtual void Update(Subject* s)=0;
};

class LongFormat :public Observer
{//Long format
private:
	double m_label;
public:
	//Update function
	void Update(Subject* s);
};

class DoubleFormat :public Observer
{//Double format
private:
	double m_label;
public:
	//Update function
	void Update(Subject* s);
};


#endif // !Observer_HPP
