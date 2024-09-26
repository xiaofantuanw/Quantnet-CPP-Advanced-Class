//Input.ixx
//Author TengxiaoFan
//This is the input module

//C++ modules and header files living side by side.
//module;
//#include <cstdio>

export module Input;//Export declaration
import <iostream>;//Import declaration


//Single Responsibility Principle
export double Ip()
{
	double x;
	std::cout << "Please enter a number.\n";
	std::cin >> x;
	return x;
}