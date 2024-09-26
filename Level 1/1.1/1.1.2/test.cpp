//test.cpp
//Author: TengxiaoFan
//This program aims at Comparing Lambda Functions with Function Objects and Free Functions
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <complex>

struct FOMultiply//Function object
{
	template <typename T>//Template, T is the type
	T operator () (const T& x, const T& y)//Function that multiplies x and y
	{
		return x * y;
	}
};

//A template function for multiplying
template <typename T>
T MyMultiply2(const T& x, const T& y) { return x * y; };

int main()
{
	std::vector<int> vec{ 1,2,3,4,5 };
	// N.B. Generic lambda
	auto MyMultiply = [](auto x, auto y) { return x * y;};

	int initVal = 1;
	//Multiply using standard library function
	int acc1 = std::accumulate(vec.begin(), vec.end(), initVal,std::multiplies<int>());

	//Multiply using function object
	int acc2 = std::accumulate(vec.begin(), vec.end(), initVal,FOMultiply());

	//Multiply using generic lambda function
	int acc3 = std::accumulate(vec.begin(), vec.end(), initVal, MyMultiply);

	
	// Using complex numbers
	using Complex = std::complex<double>;
	std::vector<Complex> complexArray{ Complex(1.0, 1.0), Complex(2.0, 2.0) };
	Complex initCVal(1.0, 1.0);
	// auto acc6C = accumulate(complexArray.begin(), complexArray.end(),
	// initCVal, FOMultiply());
	Complex acc6C = accumulate(complexArray.begin(), complexArray.end(),initCVal, MyMultiply2<Complex>);
	Complex acc7C = accumulate(complexArray.begin(), complexArray.end(), initCVal, MyMultiply);
	
	//Implement the algorithm using for_each
	int acc_imp=1;
	std::for_each(vec.begin(), vec.end(), [&](int i) {acc_imp *= i;});
	

	//A stored lambda function used by an algorithm
	auto isEven = [](int i) {return i % 2 == 0;};//A function to judge whether a number is even.
	//Find the first even number in the vector
	auto result = std::find_if(vec.begin(), vec.end(), isEven);

	
	
	//This part for result output.
	//Output of question a
	std::cout << "Sum of integers (free function): "<< acc1 << std::endl;
	std::cout << "Sum of integers (function object): " << acc2 << std::endl;
	std::cout << "Sum of integers (lambda function): " << acc3 << std::endl;
	std::cout << "Sum of complex numbers (template): " << acc6C << std::endl;
	std::cout << "Sum of complex numbers (auto): " << acc7C << std::endl;
	//Output of question b
	std::cout << "Sum of integers (implement by for_each)"<< acc_imp << std::endl;
	//Output of question c
	if (result == vec.end())
		std::cout << "No even." << std::endl;
	else
		std::cout << "First even: " << *result << std::endl;
}