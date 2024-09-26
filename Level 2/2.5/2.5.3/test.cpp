//test.cpp
//Author: TengxiaoFan
//This is the test functions for some boost functionalities on machine precision
#include <boost/math/special_functions/next.hpp>
#include <iostream>
#include <limits>

int main()
{
	//Test the function float_next
	//The next representable value that is greater than x.
	double a = 0;
	std::cout << boost::math::float_next(a) << std::endl;
	//The following code will cause runtime error
	//double b = std::numeric_limits<double>::max();
	//std::cout << boost::math::float_next(b) << std::endl;
	
	//Test the function float_prior
	//The next representable value that is less than x.
	std::cout << boost::math::float_prior(a) << std::endl;
	double b = 1;
	std::cout << boost::math::float_prior(b) << std::endl;//This will only display 1

	//Find the number of gaps/bits/ULP between two floating-point value (float_distance).
	a = 0; 
	b = 0.001; 
	double c = boost::math::float_next(a);
	//Only the +/- matters
	std::cout << boost::math::float_distance(a, b) << std::endl;//showing a<b
	std::cout << boost::math::float_distance(b, a) << std::endl;//showing b>a
	std::cout << boost::math::float_distance(b, b) << std::endl;//showing b=b
	std::cout << boost::math::float_distance(a, c) << std::endl;//c is one unit after a

	//test float_advance
	//Advance a floating-point number by a specified number of ULP (Unit in Last Place)
	std::cout << boost::math::float_advance(a,3) << std::endl;//advance by 3 units


	//Return the next representable value of x in the direction y
	//Test of nextafter, both boost and std
	std::cout << boost::math::nextafter(a, b) << std::endl;//+
	std::cout << std::nextafter(a, -b) << std::endl;//-






}