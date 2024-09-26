//test.cpp
//Author: TengxiaoFan
//This is the test function for generic function to hash a variable number of arguments of different types
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <boost/container_hash/hash.hpp>
#include "Point.hpp"

template <typename T> 
void hash_value(std::size_t& seed, const T& val) 
{ // Template for two-value hash 
	boost::hash_combine(seed, val);
}

template <typename T, typename... Types> 
void hash_value(std::size_t& seed, const T& val, const Types&... args) 
{ // Template for more value
	boost::hash_combine(seed, val);
	hash_value(seed, args...);//recursive
}

template <typename... Types> 
std::size_t hash_value(const Types&... args) 
{ //Template without parameter seed
	std::size_t seed = 0; 
	hash_value(seed, args...); 
	return seed; 
}


int main()
{
	//Test of template hash_value function
	std::size_t seed = 0;
	int a = 91;
	double b = 3.5;
	std::string c = "Jack";
	Point d(3.0, 4.0);
	hash_value(seed, a, b, c,d);
	std::cout << seed << std::endl;

	//Test of template hash_value function (seed initialized as 0)
	auto seed2 = hash_value(a, b, c, d);
	std::cout << seed2 << std::endl;//The same as seed
}