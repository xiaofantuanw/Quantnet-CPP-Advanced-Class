//Line.hpp
//Author: TengxiaoFan
//This is the header file of the class Line, derived from class Shape
#ifndef LINE_HPP
#define LINE_HPP
#include "Shape.hpp"
#include <iostream>

class Line :public Shape//Derived
{
	//Public, override function for rotate
public:
	void rotate(double d) const override { std::cout << "Line. Factor: " << d << std::endl; }
};

#endif