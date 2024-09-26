//Compare.cpp
//Author: TengxiaoFan
//This is the compare function object
#ifndef Compare_HPP
#define Compare_HPP
#include "Command.hpp"

class Compare
{//A function object compares two commands
public:
	bool operator() (Command a, Command b)
	{
		return a.priority() < b.priority();
	}
};

#endif // !Compare_HPP
