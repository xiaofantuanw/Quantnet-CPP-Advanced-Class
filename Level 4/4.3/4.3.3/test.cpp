//test.cpp
//Author: TengxiaoFan
//This is the test function for random shuffling
#include <random>
#include <iostream>
#include <algorithm>

template <typename T>
void prtvec(const std::vector<T>& v)
{//To print a vector
	std::cout << "{";
	for (auto i = v.begin();i != v.end();i++)
	{
		std::cout << (*i) << " ";
	}
	std::cout << "}\n";
}

// random generator function:
int myrandom(int i) 
{ 
	return std::rand()%i; 
}

auto myrandom2()
{
	std::random_device rd;
	std::default_random_engine g1(rd());
	return g1;
}


int main()
{
    std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//Using different engines
    std::random_device rd;
    std::default_random_engine g1(rd());
	std::linear_congruential_engine<unsigned int, 16807, 0, 2147483647> g2(rd());
	std::mt19937 g3(rd());
	//Shuffling results, using shuffle
    std::shuffle(v.begin(), v.end(), g1);
	prtvec(v);
	std::shuffle(v.begin(), v.end(), g2);
	prtvec(v);
	std::shuffle(v.begin(), v.end(), g3);
	prtvec(v);
	std::shuffle(v.begin(), v.end(), myrandom2());//Self-defined
	prtvec(v);

	//Shuffling results, using random shuffle
	std::random_shuffle(v.begin(), v.end());//Default
	prtvec(v);
	std::random_shuffle(v.begin(), v.end(), myrandom);//My random function
	prtvec(v);
}