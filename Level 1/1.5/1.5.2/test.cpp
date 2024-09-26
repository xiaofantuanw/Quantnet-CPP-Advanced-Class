//test.cpp
//Author:TengxiaoFan
//This program create a class to calculate something of the tuple (underlying numeric).
#include <iostream>
#include <tuple>
#include <complex>

//Template Calculator, using recursive way to realize
template <typename T, typename Tuple, std::size_t N>
struct Calculator
{
	//Sum
	static T sum(Tuple tup)
	{
		return std::get<N-1>(tup) + Calculator<T, Tuple, N - 1>::sum(tup);//The n-th element plus the previous sum
	}
	//Average
	static T avg(Tuple tup)
	{
		return (Calculator<T, Tuple, N>::sum(tup))/(T)N;//Sum divided by N,type convert
	}
	//Maximum
	static T max(Tuple tup)
	{
		T tmp = Calculator<T, Tuple, N - 1>::max(tup);
		return (std::get<N - 1>(tup) > tmp ? std::get<N - 1>(tup) : tmp);//Compare the n-th element with the previous ones
	}
};

//The terminate of the calculator, with 1 element
template <typename T,typename Tuple>
struct Calculator<T, Tuple, 1>
{
	//Sum and maximum, return the first element
	static T sum(Tuple tup)
	{
		return std::get<0>(tup);
	}
	static T max(Tuple tup)
	{
		return std::get<0>(tup);
	}
};


//Define my tuple types
typedef std::tuple<double, double, double> mytuple;
typedef std::tuple<double, double> mytuple2;
typedef std::tuple<std::complex<int>, std::complex<int>, std::complex<int>> mycomplextuple;
int main()
{
	//Test the three-element double tuple
	mytuple tup(1.1, 2.2, 1.3);
	double max = Calculator<double, mytuple, 3>::max(tup);
	double sum= Calculator<double, mytuple, 3>::sum(tup);
	double avg= Calculator<double, mytuple, 3>::avg(tup);
	//Output
	std::cout << "Three-element double tuple.\n";
	std::cout << "Max: " << max << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Average: " << avg << std::endl<<std::endl;

	//Test the two-element double tuple
	mytuple2 tup2(1.1, 2.2);
	double max2 = Calculator<double, mytuple2, 2>::max(tup2);
	double sum2 = Calculator<double, mytuple2, 2>::sum(tup2);
	double avg2 = Calculator<double, mytuple2, 2>::avg(tup2);
	//Output
	std::cout << "Two-element double tuple.\n";
	std::cout << "Max: " << max2 << std::endl;
	std::cout << "Sum: " << sum2 << std::endl;
	std::cout << "Average: " << avg2 << std::endl << std::endl;

	//Test the complex tuple
	mycomplextuple tup3(std::complex<int>(1, 1), std::complex<int>(2, 2), std::complex<int>(3, 3));
	auto sumcomplex = Calculator<std::complex<int>, mycomplextuple, 3>::sum(tup3);
	auto avgcomplex= Calculator<std::complex<int>, mycomplextuple, 3>::avg(tup3);
	//Output
	std::cout << "Complex tuple.\n";
	std::cout << "Sum: "<<sumcomplex << std::endl;
	std::cout << "Avg:" << avgcomplex << std::endl;
}