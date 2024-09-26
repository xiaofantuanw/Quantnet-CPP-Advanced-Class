#ifndef  IRNG_HPP
#define IRNG_HPP
#include <random>

class IRNG
{//Abstract class for random number generators
public:
	virtual double GenerateRn()=0;
};

class MyNormalRNG : public IRNG
{//A random number generator that returns a std normal random number
public:
	double GenerateRn() override
	{
		std::default_random_engine eng;
		std::normal_distribution<double> dist(0.0, 1.0);
		return dist(eng);
	}
};
#endif // ! IRNG_HPP
