//test.cpp
//Author: TengxiaoFan
//This is a test function for a random bitset engine
#include "independent_bits_engine.hpp"
#include <iostream>
int main()
{
	int NTrials = 100;
	const int width = 64;
	int count = 0;
	std::random_device seed;
	for (int i = 0;i < NTrials;i++)
	{	
		independent_bits_engine<std::default_random_engine, width, long long> e1(std::move(seed));
		std::cout << e1.get() << ": " << e1.getbit() << std::endl;
		count += e1.getbit().count();//Add the number of bits set
	}
	double probability = (double)count / (NTrials * width);
	std::cout << "Proportion of set digits: " << probability << std::endl;
}
//width=2 Ntrial=100 51.0%
//width=8 Ntrial=100 49.375%
//width=16 Ntrial=100 49.5625%
//width=64 Ntrial=100 50.0469%