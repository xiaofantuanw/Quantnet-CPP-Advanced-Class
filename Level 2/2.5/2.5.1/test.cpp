//test.cpp
//Author: TengxiaoFan
//This is the test file for the classification of c++ doubles
#include <limits>
#include <iostream>

template <typename T> 
const char* Classify(T t) 
{ 
	//This is a classify function for number. using switch
	switch (std::fpclassify(t)) 
	{ 
		case FP_INFINITE: 
			return "Inf"; 
		case FP_NAN: 
			return "NaN"; 
		case FP_NORMAL: 
			return "normal"; 
		case FP_SUBNORMAL: 
			return "subnormal"; 
		case FP_ZERO: 
			return "zero"; 
		default: 
			return "unknown"; 
	} 
}

template <typename T>
void properties( T t)
{
	//This function gives the classification of a number
	std::cout << std::boolalpha;
	std::cout << "Finite? " << std::isfinite(t) << std::endl;	
	std::cout << "Inf? " << std::isinf(t) << std::endl;
	std::cout << "NaN? " << std::isnan(t) << std::endl;
	std::cout << "Normal? " << std::isnormal(t) << std::endl<<std::endl;
}

int main()
{
	//Experiment1
	double val = std::numeric_limits<double>::max();
	std::cout << "1. " << Classify<double>(val) << std::endl;//normal
	std::cout <<"2. "<< Classify<double>(2.0*val)<<std::endl;//Inf
	std::cout << "3. " << Classify<double>(val+3.1415) << std::endl;//normal
	double val2 = std::numeric_limits<double>::min()-3.1415;
	std::cout << "4. " << Classify<double>(val2) << std::endl;//normal
	std::cout << "5. " << Classify<double>(val2/2.0) << std::endl;//normal
	std::cout << "6. " << Classify<double>(DBL_MIN/2) << std::endl;//subnormal
	std::cout << "----------------------" << std::endl;

	//Experiment2
	double factor = 2.0; 
	val = factor * std::numeric_limits<double>::max();
	properties<double>(val);//Inf
	properties<double>(val - val);//NaN
	properties<double>(std::sqrt(-1.0));//NaN
	properties<double>(std::log(0.0));//Inf
	properties<double>(std::exp(val));//Inf

	
}