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
public:
	//Constructors and destructors
	ShapeComposite() {}//Constructor
	
	virtual ~ShapeComposite()
	{
	}//Destructor
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

	//Clone the ShapeComposite
	virtual Shape* Clone() const
	{
		ShapeComposite* result = new ShapeComposite(*this);
		//for (auto it = l.begin();it != l.end();it++)
		//{
		//	result->AddShape((*it)->Clone());
		//}
		return result;
	}

	ShapeComposite(const ShapeComposite& source):Shape(source)
	{//copy constructor
		for (auto it = source.l.begin();it != source.l.end();it++)
		{
			l.push_back((*it)->Clone());
		}
	}
	ShapeComposite& operator = (const ShapeComposite& source) 
	{
		if (this == &source)//preclude self-assignment
		{
			return *this;
		}
		Shape::operator=(source);//Use the assignment operator in base class
		for (auto it = source.l.begin();it != source.l.end();it++)
		{
			l.push_back((*it)->Clone());
		}
	} //assignment operator.

	//Virtual function to use the shape visitor
	virtual void Accept(ShapeVisitor* sv);
};

#endif