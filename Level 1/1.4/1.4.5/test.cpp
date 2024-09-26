//test.cpp
//Author: TengxiaoFan
//This file tests the composition and function wrapping 

#include "Shape.hpp"
#include <iostream>

int main()
{
	double d = 2.0;
	//Build a lambda func
	auto f0 = [](double d) {std::cout << "Rotate the shape, factor: " <<d<< std::endl;};
	Shape s1(f0);//Build a Shape object from the function
	s1.rotate(d);//Use the rotate function

	//Switch to a new lambda function
	s1.SwitchFunc([](double d) {std::cout << "New shape rotater, factor: " << d << std::endl;});
	s1.rotate(2*d);
}
