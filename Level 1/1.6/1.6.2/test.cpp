//test.cpp
//Author: TengxiaoFan
//This is the test function for TMPClass, which realized an algorithm
#include "TMPClass.hpp"
#include <iostream>

int main()
{
	InputFunction ifunction= []() {return 3.0;};//hardcoded
	OutputFunction ofunction = [](const std::vector<double>& v)//use range iteration
	{
		for (auto elem : v)
		{
			std::cout << elem << ", ";
		}
		std::cout << std::endl;
	};
	TMPClass tmpclass1(10, 2.5, ifunction, ofunction);//Initialize
	tmpclass1.Alg();//Run the algorithm
}