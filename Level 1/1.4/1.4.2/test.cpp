//test.cpp
//Author: TengxiaoFan
//This file tests the use of std::bind and placeholder
#include <iostream>
#include <functional>

double freeFunction3(double x, double y, double z)
{
	return x + y + z;
}

int main ()
{
	
	//Function of arity 2
	auto fxy = std::bind(freeFunction3, std::placeholders::_1, std::placeholders::_2, 3);//Bind the third
	auto fyz = std::bind(freeFunction3, 1, std::placeholders::_1, std::placeholders::_2);//Bind the first
	auto fxz = std::bind(freeFunction3, std::placeholders::_1, 2, std::placeholders::_2);//Bind the second

	//Function of arity 1
	auto fx = std::bind(freeFunction3, std::placeholders::_1, 2, 3);//Bind the second and third
	auto fy = std::bind(freeFunction3, 1, std::placeholders::_1, 3);//Bind the first and third
	auto fz = std::bind(freeFunction3, 1, 2, std::placeholders::_1);//Bind the first and second

	//Function of arity 0
	auto f0 = std::bind(freeFunction3, 1, 2, 3);//Bind all.

	//Test the results, and all the results should be 6(1+2+3).
	//Arity 3
	std::cout << "f(1,2,3)=" << freeFunction3(1, 2, 3) << std::endl;
	//Arity 2
	std::cout << "fxy(1,2)=" << fxy(1, 2) << std::endl;
	std::cout << "fyz(2,3)=" << fyz(2,3) << std::endl;
	std::cout << "fxz(1,3)=" << fxz(1, 3) << std::endl;
	//Arity 1
	std::cout << "fx(1)=" << fx(1) << std::endl;
	std::cout << "fy(2)=" << fy(2) << std::endl;
	std::cout << "fz(3)=" << fz(3) << std::endl;
	//Arity 0
	std::cout << "f0()=" << f0() << std::endl;

	
}