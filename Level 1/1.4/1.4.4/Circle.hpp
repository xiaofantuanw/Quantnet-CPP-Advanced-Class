//Circle.hpp
// Author:Tengxiao Fan
//This is the header file of the class Circle, derived from class Shape
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <functional>
#include <iostream>
#include "Shape.hpp"

using VoidFunctionType = std::function<void(double)>;

class Circle:public Shape
{
public:
	//Constructor
	Circle(VoidFunctionType f0) :Shape(f0) { }//Inherited from base class
	//Rotate function
	void rotate(double d) 
	{ 
		Shape::rotate(d); 
		std::cout << "Circle override" << std::endl; //To show the difference of override
	}//Override
};


#endif // !CIRCLE_HPP
