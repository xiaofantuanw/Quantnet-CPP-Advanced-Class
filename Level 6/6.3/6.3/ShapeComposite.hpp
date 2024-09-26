#ifndef ShapeComposite_HPP
#define ShapeComposite_HPP

#include "Shape.hpp"
#include <list>
#include <iostream>

using iter = std::list<Shape*>::iterator;
using const_iter = std::list<Shape*>::const_iterator;


class ShapeComposite :public Shape
{
private:
	std::list<Shape*> l;
	ShapeComposite(const ShapeComposite& source) {}//private copy constructor
	const ShapeComposite& operator = (const ShapeComposite& source) {} // private assignment operator.
public:
	//Constructors and destructors
	ShapeComposite() {}//Constructor
	virtual ~ShapeComposite(){}//Destructor
	//Add an element
	void AddShape(Shape* s)
	{
		l.push_back(s);
	}
	//Begin and end iterators
	iter begin()
	{
		return l.begin();
	}
	iter end()
	{
		return l.end();
	}
	//Size of the list
	size_t count()
	{
		return l.size();
	}
	//Print function
	void Print() const override
	{//Print the shapes iteratively
		std::cout << Shape::ToString() <<": Shape Composite"<< std::endl;
		for (auto it = l.begin();it != l.end();it++)
		{
			(*it)->Print();
		}
	}
};

#endif