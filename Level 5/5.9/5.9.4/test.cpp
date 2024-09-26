//test.cpp
//Author: TengxiaoFan
//This is a test file for combining returned value from slots
#include <boost\signals2.hpp>
#include <iostream>
#include <functional>
#include <numeric>

template <typename T>
struct SumCombiner
{// Iterate in slots and return the sum
	typedef double result_type;
	template <typename InputIterator>
	double operator()(InputIterator first, InputIterator last) const
	{
		return std::accumulate(first, last, 0.0);
	}
};

//Slots
double Slot1(double x, double y)
{
	return x * y;
}

//Slots
double Slot2(double x, double y)
{
	if (y == 0.0) return 0.0;
	return x / y;
}
//Slots
double Slot3(double x, double y)
{
	if (x == 0.0) return 0.0;
	return y / x;
}

int main()
{
	// Create a signal + custom combiner 
	boost::signals2::signal<double (double x, double y), SumCombiner<double>> sig;
	//Connect the slots
	sig.connect(Slot1);
	sig.connect(Slot2);
	sig.connect(Slot3);
	//Emit the slot
	double a=sig(2.0, 3.0);
	std::cout << "Result: "<<a << std::endl;
}