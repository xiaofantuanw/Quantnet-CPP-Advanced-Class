//test.cpp
//author:TengxiaoFan
//This is the test function for different engines and distributions to generate random number
#include <random>
#include <iostream>

void test_random_engines()
{//Test different random engines
	// Choose the engine 
	std::default_random_engine eng;
	std::linear_congruential_engine<unsigned int, 16807, 0, 2147483647> eng2;
	std::mt19937 eng3;
	std::mt19937_64 eng4;
	// Generate uniform random variates in interval [A, B] 
	double A = 0.0;
	double B = 1.0;
	std::uniform_real_distribution<double> dist(A, B);
	int nTrials = 10;
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist(eng) << ", ";
	}
	std::cout << "end of engine 1\n\n";
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist(eng2) << ", ";
	}
	std::cout << "end of engine 2\n\n";
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist(eng3) << ", ";
	}
	std::cout << "end of engine 3\n\n";
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist(eng4) << ", ";
	}
	std::cout << "end of engine 4\n\n";
}

void test_distributions()
{//Test different distributions
	// Choose the engine 
	std::default_random_engine eng;
	// Generate uniform random variates in interval [A, B] 
	double A = 0.0;
	double B = 1.0;
	std::uniform_real_distribution<double> dist(A, B);
	//Generate normal distribution N(A,B)
	std::normal_distribution<double> dist2(A, B);
	// Chi^2 distribution
	int k = 1; // Degrees of freedom
	std::chi_squared_distribution<double> dist3(k);
	//Bernoulli distribution
	double p = 0.25;
	std::bernoulli_distribution dist4(p);//Probability of 0.25 true
	//Cauchy distribution with parameters A and B
	std::cauchy_distribution<double> dist5(A, B);
	int nTrials = 10;
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist(eng) << ", ";
	}
	std::cout << "end of distribution 1\n\n";
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist2(eng) << ", ";
	}
	std::cout << "end of distribution 2\n\n";
	
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist3(eng) << ", ";
	}
	std::cout << "end of distribution 3\n\n";
	
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist4(eng) << ", ";
	}
	std::cout << "end of distribution 4\n\n";
	
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << dist5(eng) << ", ";
	}
	std::cout << "end of distribution 5\n\n";
}

template <typename Dist, typename Eng>
void test_generic_random(Dist d, int nTrials=10)
{
	Eng e;
	for (int i = 1; i <= nTrials; ++i)
	{ // Produce a number of uniform variates
		std::cout << d(e) << ", ";
	}
	std::cout << "end\n\n";
}

int main()
{
	test_random_engines();
	test_distributions();

	//test the generic fun
	// Generate uniform random variates in interval [A, B] 
	double A = 0.0;
	double B = 1.0;
	std::uniform_real_distribution<double> dist(A, B);
	test_generic_random<std::uniform_real_distribution<double>, std::default_random_engine>(dist);

}