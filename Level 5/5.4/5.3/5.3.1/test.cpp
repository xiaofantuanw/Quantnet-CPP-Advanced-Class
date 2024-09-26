//test.cpp
//Author: TengxiaoFan
//This is the test function for basic functionalities of std and boost hash
#include <functional>
#include <iostream>
#include <string>
#include <boost/container_hash/hash.hpp>

template <typename T>
size_t make_std_hash(const T& t)
{//return a hash using std function
	std::hash<T> Thash;//A hash maker
	return Thash(t);
}

template <typename T>
size_t make_boost_hash(const T& t)
{//return a hash using boost function
	boost::hash<T> Thash;//A hash maker
	return Thash(t);
}


int main()
{
	//Hash for integers
	int a = 354;
	std::cout << make_std_hash(a) << std::endl;
	std::cout << make_boost_hash(a) << std::endl;//it will be a itself
	//Hash for string
	std::string str("Apple");
	std::cout << make_std_hash(str) << std::endl;
	std::cout << make_boost_hash(str) << std::endl;
	//Test h1 ^ (h2 << 1)
	std::string str2("Banana");
	auto h1 = make_std_hash(str);
	auto h2 = make_std_hash(str2);
	std::cout << "h1^(h2<<1): " << (h1 ^ (h2 << 1)) << std::endl;

	//Hash for Pointer
	int* x = new(int);
	std::cout << make_std_hash(x) << std::endl;
	std::cout << make_boost_hash(x) << std::endl;
	*x = 5;//The hash will not change when giving the pointer a new value
	std::cout << make_std_hash(x) << std::endl;
	std::cout << make_boost_hash(x) << std::endl;
	//std::numeric_limits<long>::max()
	auto m = std::numeric_limits<long>::max();
	std::cout << make_std_hash(m) << std::endl;
	std::cout << make_boost_hash(m) << std::endl;

}