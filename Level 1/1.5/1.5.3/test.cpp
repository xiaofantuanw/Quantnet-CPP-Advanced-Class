//test.cpp
//Author: TengxiaoFan
//This is the test program for function returning tuples. Return the statistics of a vector
#include <tuple>
#include <numeric>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

//Return the mean, mean deviation, range, standard deviation and variance
template <typename T>
std::tuple<T, T, T, T, T> statistical(const std::vector<T>& vec)
{
	T mean, mean_dev=0, range, std_dev, var=0;
	//Calculate the mean
	mean = std::accumulate(vec.begin(), vec.end(), 0) / (T)vec.size();
	//Calculate the mean deviation
	std::for_each(vec.begin(), vec.end(), [&](T n) {mean_dev += abs(n-mean);});
	//Calculate the range
	range = *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
	//Calculate the variance and std deviation
	std::for_each(vec.begin(), vec.end(), [&](T n) {var += (n - mean) * (n - mean);});
	std_dev = sqrt(var);
	//Make a tuple and return 
	auto tup = std::tuple<T, T, T, T, T>(mean, mean_dev, range, std_dev, var);
	return tup;
}

//Return the median and mode of the vector
template<typename T>
std::tuple<T, T> MedianMode(std::vector<T>& vec)
{
	T median, mode=0;
	int N = (int)vec.size();
	//Sort the vector
	std::sort(vec.begin(), vec.end());
	//Calculate the median of sorted vector
	if (N % 2 == 0)
	{
		median= (vec[N / 2] + vec[N / 2 - 1]) / (T)2;
	}
	else
	{
		median= vec[(N - 1) / 2];
	}

	//Calculate the mode of the sorted vector
	int modenum = 0,tmpnum;
	for (auto i = vec.begin();i != vec.end();i++)
	{
		tmpnum = 0;
		auto j = i;
		//Find the repeated number
		while (j!=vec.end()&& *j==*i)
		{
			tmpnum++;
			j++;
		}
		if (tmpnum > modenum)
		{
			modenum = tmpnum;
			mode = *i;
		}
	}
	//Make a tuple and return 
	auto tup = std::tuple<T, T>(median, mode);
	return tup;
}

int main()
{
	std::vector<double> vec = { 7.0,4.0,3.0,4.0,5.0,5.0 };
	double mean, mean_dev, range, std_dev, var;
	//Use std::tie to give the values to the variables
	std::tie(mean, mean_dev, range, std_dev, var) = statistical<double>(vec);
	std::cout << mean << ", " << mean_dev << ", " << range << ", " << std_dev << ", " << var << std::endl;

	double median, mode;
	std::tie(median, mode) = MedianMode<double>(vec);
	std::cout << median << ", " << mode;
}