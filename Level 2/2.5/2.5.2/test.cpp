//test.cpp
//Author: TengxiaoFan
//This is the test file for epsilon value
#include <iostream>
#include <limits>

template <typename T>
T ComputeEpsilon()
{
	//Template function to compute epsilon of type T
	T epsilon = 1;
	while (((T)1.0 + (T)0.5 * epsilon) != (T)1.0)//Convert everything to type T
	{
		epsilon *= (T)0.5;
	}
	return epsilon;
}


int main()
{
	double epsilon_double = ComputeEpsilon<double>();
	float epsilon_float = ComputeEpsilon<float>();

	std::cout << "Epsilon of double: "<<epsilon_double << std::endl;//epsilon of double
	std::cout << "Epsilon of float: " << epsilon_float << std::endl;//epsilon of float(different)
	std::cout << "Epsilon of double (std): " << std::numeric_limits<double>::epsilon() << std::endl;//epsilon of double by std
	std::cout << "Epsilon of double the same? " << std::boolalpha<<(epsilon_double == std::numeric_limits<double>::epsilon()) << std::endl;
	//Result: same
}