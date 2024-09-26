//test.cpp
//Author: TengxiaoFan
//This is the test program for the The Chi-Squared Test
#include <random>
#include <map>
#include <string>
#include <iostream>

double chi_squared(std::map<int,int> counter, std::map<int,double> expectation,int N)
{//Calculate the statistics chi-squared
	double result=0;
	for (auto it = expectation.begin();it != expectation.end();it++)
	{
		if (counter.find(it->first)!=counter.end())
		{//The type is observed at least once
			double tmp = ((double)counter[it->first] - N * (it->second)) * ((double)counter[it->first] - N * (it->second)) / (N * (it->second));
			result += tmp;
		}
		else
		{
			double tmp=(0-N*(it->second))* (0 - N * (it->second)) / (N * (it->second));
			result += tmp;
		}
	}
	return result;
}

template <typename Dist, typename Eng>
std::map<int,int> GenerateRandomNumbers(Dist d, Eng eng, int NTrials)
{//Generate Random numbers by distribution d 
	std::map<int, int> counter;
	for (int i = 0;i < NTrials;i++)
	{//make random values and the map
		int val = d(eng);
		if (counter.find(val) == counter.end())
		{
			counter[val] = 1;
		}
		else
		{
			counter[val]++;
		}
	}
	return counter;
}

double generate_pearson(int k,int N)
{//generate a chi-squared (Pearson) with k freedom and N uniform samples
	std::map<int, double> expectation;
	for (int i = 0;i <= k;i++)
	{
		expectation[i] = 1.0 / ((double)k+1.0);
	}
	std::random_device rd;
	std::default_random_engine eng(rd());//default engine
	std::uniform_int_distribution<int> dist(0, k);//uniform distribution
	std::map<int, int> counter = GenerateRandomNumbers(dist, eng, N);
	return chi_squared(counter, expectation, N);//calculate the statistics
}

double direct_chi_squared(int k)
{//directly generate a sample with chi_squared distribution
	std::random_device rd;
	std::default_random_engine eng(rd());//default engine
	std::chi_squared_distribution<double> dist(k);//chi-squared distribution
	return dist(eng);
}


int main()
{
	int k = 5;
	int N = 100;
	int Nhis = 1000;
	//Now make the histogram of pearson test
	std::map<int, int> counter;
	for (int i = 0;i < Nhis;i++)
	{//count the results
		double x=generate_pearson(k, N);
		int val = (int)x;
		if (counter.find(val) == counter.end())
		{
			counter[val] = 1;
		}
		else
		{
			counter[val]++;
		}
	}
	//Output the histogram
	std::cout << "Pearson's cumulative test statistic" << std::endl;
	for (auto i = counter.begin();i != counter.end();i++)
	{
		std::cout << (i->first) << "| \t";
		for (int j = 0;j < i->second / 10;j++)
		{
			std::cout << "*";
		}
		std::cout << "\t" << (i->second) << std::endl;
	}
	std::cout << std::endl<<std::endl;


	//now make the histogram of chi-distribution
	std::map<int, int> counter2;
	for (int i = 0;i < Nhis;i++)
	{//count the results
		double x = direct_chi_squared(k);
		int val = (int)x;
		if (counter2.find(val) == counter2.end())
		{
			counter2[val] = 1;
		}
		else
		{
			counter2[val]++;
		}
	}
	//Output the histogram
	std::cout << "Dirctly generated chi-squared Distribution" << std::endl;
	for (auto i = counter2.begin();i != counter2.end();i++)
	{
		std::cout << (i->first) << "| \t";
		for (int j = 0;j < i->second / 10;j++)
		{
			std::cout << "*";
		}
		std::cout << "\t" << (i->second) << std::endl;
	}
	std::cout << std::endl << std::endl;
}

//result: almost the same distribution