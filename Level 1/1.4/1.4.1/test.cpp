//test.cpp
//Author: TengxiaoFan
//This file tests the function wrapper
#include <iostream>
#include <functional>

template <typename T>
using FunctionType = std::function<T(const T& t)>;

template <typename T>
void print(const FunctionType<T>& f, T obj)
{
	std::cout << f(obj) << std::endl;
}

double freefunc(const double& t)
{
	return t * t;
}

class funcobj
{
public:
	double operator() (const double& t) { return t * t; };
};

int main()
{
	FunctionType<double> f;
	funcobj obj1;
	double t = 2.5;
	f = freefunc;//Assign a free function
	print(f, t);
	f = [&](double t) {return t * t;};//Assign a lambda function
	print(f, t);
	f = obj1;//Assign a function object
	print(f, t);
}