//Polyline.hpp
//TengxiaoFan
//This is the template class for shape polyline
#ifndef Polyline_HPP
#define Polyline_HPP
#include "Shape.hpp"
#include <iostream>
#include "Point.hpp"

template<template<typename, typename> class Container, typename alloc = std::allocator<Point>>
class Polyline:public Shape
{
private:
	Container<Point, alloc> points; // Store the points
public:
	//Default constructor and destructor
	//Copy constructors and assignment operator
	Polyline(const Polyline& source) = default;
	Polyline& operator=(const Polyline& source) = default;
	Polyline() {}
	virtual ~Polyline() {}
	void AddPoint(Point p)
	{//Add a point to the polyline
		points.push_back(p);
	}
	double Length () const
	{//The length of the polyline
		double result = 0.0;
		auto endit = points.end();
		endit--;
		for (auto it = points.begin();it != endit;it++)
		{
			auto p1=(*it);
			auto tmp = it;
			tmp++;
			auto p2 = (*tmp);
			result += p1.Distance(p2);
		}
		return result;
	}
	//Override ptint function
	virtual void Print() const override
	{
		std::cout << "Polyline: " << std::endl;
		for (auto it = points.begin();it != points.end();it++)
		{//Print the points
			(*it).Print();
		}
	}
	//Clone function
	virtual std::shared_ptr<Shape> Clone() const override
	{
		std::shared_ptr<Shape> s(new Polyline(*this));
		return s;
	}

};

#endif // !Polyline_HPP
