//Output.ixx
//Author TengxiaoFan
//This is the output module

//C++ modules and header files living side by side.
//module;
//#include <cstdio>

export module Output;//Export declaration
import <iostream>;//Import declaration


//Single Responsibility Principle
export void Op(double x)
{
	std::cout << "Result: " << x << std::endl;
}