//test.cpp
//Author: TengxiaoFan
//This file tests the function wrapper and bind with object.
#include <iostream>
#include <functional>
#include "C.hpp"

//Define the function type
template <typename T>
using FunctionType = std::function<T(const T& t)>;

//Function wrapper
template <typename T>
void print(const FunctionType<T>& f, T obj)
{
	std::cout << f(obj) << std::endl;
}

int main()
{
	//Bind the static function
	FunctionType<double> f;
	f = std::bind(C::Square, std::placeholders::_1);
	print(f, 3.0);//9

	//Bind the member function with the object associated with &function
	C c(3.0);
	f = std::bind(&C::translate, c, std::placeholders::_1);
	print(f, 3.0);//6

	f = std::bind(&C::translate2, c, 3.0, std::placeholders::_1);
	print(f, 3.0);//9
}