//Circle,hpp
//Author: TengxiaoFan
//This is the header file of the class Circle, derived from class Shape
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Shape.hpp"
#include <iostream>

class Circle :public Shape//Derived
{
	//Public, override function for rotate
public:
	void rotate(double d) const override { std::cout << "Circle. Factor: " << d << std::endl; }
	
};

#endif