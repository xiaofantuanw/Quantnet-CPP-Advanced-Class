//test.cpp
//Author: TengxiaoFan
//This is the test file for a random number generator which outputs a histogram
#include <random>
#include <iostream>
#include <map>

template <typename Dist, typename Eng> 
void GenerateRandomNumbers(Dist d, Eng eng, int NTrials, const std::string& s) 
{//Generate Random numbers by distribution d 
	std::map<long long, int> counter;
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
	//Output the histogram
	std::cout << s << std::endl;
	for (auto i = counter.begin();i != counter.end();i++)
	{
		std::cout << (i->first) << "| \t" ;
		for (int j = 0;j < i->second/10;j++)
		{
			std::cout << "*";
		}
		std::cout << "\t" << (i->second) << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	//Geometric distribution
	double p = 0.25;
	std::geometric_distribution<int> dist1(0.25);
	std::default_random_engine eng;
	GenerateRandomNumbers(dist1, eng, 1000, "Geometric Distribution");
	//Uniform  int distribution
	std::uniform_int_distribution<int> dist2(1, 10);
	GenerateRandomNumbers(dist2, eng, 1000, "Uniform int Distribution");
	//Poisson distribution
	std::poisson_distribution<int> dist3(1);//Poisson, mean=1
	GenerateRandomNumbers(dist3, eng, 1000, "Poisson Distribution");

	//Does it look like the probability of these distributions? Yes!
}