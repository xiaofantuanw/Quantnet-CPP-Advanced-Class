//test.cpp
//Author: TengxiaoFan
//This is a test file for combining returned value from slots
#include <boost\signals2.hpp>
#include <iostream>
#include <functional>

struct BootstrapCheck
{// Iterate in slots and return first 'false' value; otherwise, 'true'
	typedef bool result_type;
	template <typename InputIterator>
	bool operator()(InputIterator first, InputIterator last) const
	{
		while (first != last)
		{
			if (!*first) 
			{ //If false, the operation will return and stop
				return false; 
			} 
			++first;
		}
		return true;
	}
};

bool Slot1()
{
	std::cout << "Slot 1" << std::endl;
	return true;
}

bool Slot2()
{
	std::cout << "Slot 2" << std::endl;
	return false;
}
bool Slot3()
{
	std::cout << "Slot 13" << std::endl;
	return true;
}

int main()
{
	boost::signals2::signal<bool(), BootstrapCheck> sig;//A signal with BootstrapCheck
	//Connect the signals
	sig.connect(0, Slot1);
	sig.connect(1, Slot2);
	sig.connect(2, Slot3);
	//Emit the signal
	sig();//Only slot1 and 2 are operated

}