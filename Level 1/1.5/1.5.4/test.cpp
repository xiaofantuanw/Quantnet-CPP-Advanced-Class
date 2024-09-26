//test.cpp
//Author: TengxiaoFan
//This is a test program for some functions used in numerical analysis
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <cmath>

//Find the interval where x belongs to
int FindInterval(const std::vector<double>& vec,double x)
{
	auto iter = std::find_if(vec.begin(), vec.end(), [x](double n) {return n > x;});//Find the first number larger than x
	return (int)std::distance(vec.begin(), iter)-1;
}

//Find the index with the largest error
typedef std::function<double(double, double)> Err;
std::tuple<double, int> FindMaxError(const std::vector<double>& vec1, const std::vector<double>&vec2, int begin, int end, Err err)
{
	std::vector<double> norm;
	//Build a vector of error
	for (int i = begin;i <= end;i++)
		norm.push_back(err(vec1[i], vec2[i]));
	auto iter = std::max_element(norm.begin(), norm.end());//Find the max error
	return std::tuple<double, int>(*iter, (int)std::distance(norm.begin(), iter));
}

int main()
{
	std::vector<double> vec1{1.0, 2.0, 3.0, 4.0, 5.0};
	//Test of function FindInterval
	int n=FindInterval(vec1, 2.3);
	double err;
	std::cout << "Interval: "<<n << std::endl;

	//Find the max error
	std::vector<double> vec2{ 1.0,2.1,3.11,4.1,5.0 };
	//Absolute error
	std::tie(err, n) = FindMaxError(vec1, vec2, 0, 4, [](double a, double b) {return abs(a - b);});
	std::cout << "Max Error (absolute): "<<n << ", " << err << std::endl;
	//Relative error
	std::tie(err, n) = FindMaxError(vec1, vec2, 0, 4, [](double a, double b) {return abs((a - b)/a);});
	std::cout << "Max Error (relative): " << n << ", " << err << std::endl;
}