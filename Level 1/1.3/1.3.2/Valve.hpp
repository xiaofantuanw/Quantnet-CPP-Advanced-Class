//Valve.hpp
//Author: TengxiaoFan
//This is the header file of the class Valve
#ifndef VALVE_HPP
#define VALVE_HPP
#include <iostream>

class Valve
{
	//Public, function of rotate
public:
	void rotate(double d) const { std::cout << "Valve. Factor: " << d << std::endl; }
};


#endif
