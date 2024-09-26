//test.cpp
//Author: TengxiaoFan
//This program creates new bind functions using lambda function
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>


// Function maps Domain to Range 
template <typename R, typename D>
using FunctionType = std::function<R(const D x)>;

// Working function type 
using ScalarFunction = FunctionType<double, double>;

template <typename T> 
std::function<T(const T&)> bind1st(const std::function<T(const T& x, const T& y)>& f, const T& x_) 
{ // Bind to the first param x of f(x,y)
	return [=](const T& y)
	{
		return f(x_, y);
	};
}

template <typename T> 
std::function<T(const T&)> bind2nd(const std::function<T(const T& x, const T& y)>& f, const T& y_) 
{ // Bind to the second param y of f(x,y)
	return [=](const T& x)
	{
		return f(x, y_);
	};
}



int main()
{
	double yval = 10.0, xval=5.0; 
	auto fxy = [=](double x, double y) {return x * y;};
	//bind functions
	ScalarFunction fx = bind2nd<double>(fxy, yval); 
	ScalarFunction fy = bind1st<double>(fxy, xval);
	std::cout << fx(3.0) <<", "<<fy(5.0) << std::endl;

	// Test new bind code on STL algorithms 
	std::vector<double> vec(10, 2.0); 
	std::transform(vec.begin(), vec.end(), vec.begin(), fx); 
	for (auto i = 0; i < vec.size(); ++i) 
	{ 
		std::cout << vec[i] << ","; 
	}
}