//test.cpp
//Author: TengxiaoFan
//This file tests the inheritance and function wrapping 
#include "Circle.hpp"
#include "Shape.hpp"
#include <iostream>

int main()
{
	double d = 2.0;
	auto f0 = [](double d) {std::cout << "Rotate the shape, factor: " <<d<< std::endl;};//Build a lambda func
	Circle c1(f0);//Build a circle object
	c1.rotate(d);//Use the rotate function
}
