//Author: TengxiaoFan
//test.cpp
//This source file tests the definition of lambda functions.
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main()
//Main function
{
	std::vector<double> arr, arr1;//arr is the original array,
	//arr1 is the one changed by the function copy-by-value
	for (int n = 0;n <= 100;n++)
	{
		arr.push_back(n * 0.01);//Initialize
	}
	double multiplier = 3;
	auto f_copy = [multiplier](std::vector<double> arr)->std::vector<double>
		//The definition of lambda function using copy-by-value, store.
	{
		for (auto it = arr.begin();it != arr.end();it++)//Use auto iterator
		{
			*it = (*it) * multiplier;
		}
		return arr;
	};

	auto f_ref = [multiplier](std::vector<double>& arr)
		//The definition of lambda function call by reference, store.
	{
		for (auto it = arr.begin();it != arr.end();it++)//Use auto iterator
		{
			*it = (*it) * multiplier;
		}
	};
	arr1=f_copy(arr);//Use the lambda function
	f_ref(arr);
	for (auto it = arr.begin();it != arr.end();it++)//Use auto iterator
	{
		std::cout << *it << std::endl;//Output
	}
	
	auto f_minmax = [](std::vector<double>& arr)->std::pair<double,double>
		//The definition of the minmax function
	{
		double mintmp = *arr.begin(), maxtmp = *arr.begin();//Two variables storing the min and max
		for (auto it = arr.begin();it != arr.end();it++)
		{
			if (*it < mintmp)
				mintmp = *it;//Renew the min
			if (*it > maxtmp)
				maxtmp = *it;//Renew the max
		}
		std::pair<double, double> minmax(mintmp, maxtmp);//Build a pair
		return minmax;
	};

	auto minmax = f_minmax(arr);
	std::cout << "min: " << minmax.first << std::endl;//Output
	std::cout << "max: " << minmax.second << std::endl;
	auto minmax2 = std::minmax_element(arr.begin(), arr.end());
	std::cout << "min: " << *minmax2.first << std::endl;//Output using standard function
	std::cout << "max: " << *minmax2.second << std::endl;
	///The difference between the function I define and the standard one:
	//The pair returned by my function is the value of the min and max
	//The pair returned by the standard function is the reference of the min and max.
}