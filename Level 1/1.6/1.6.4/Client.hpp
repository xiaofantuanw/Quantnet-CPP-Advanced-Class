//Client.cpp
//Author:TengxiaoFan
//This is the definition of class Client, using alias template
#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <iostream>
#include <list>
#include <algorithm>


// C++ 98 approach // Data storage types 
//template <typename T> 
//struct Storage 
//{ 
	// Possible ADTs and their memory allocators 
	// typedef std::vector<T, CustomAllocator<T>> type; 
	// typedef std::vector<T, std::allocator<T>> type;
	//typedef std::list<T, std::allocator<T>> type; 
//};

//C++11 approach
template <typename T>
using Storage = std::list<T, std::allocator<T>>;

template <typename T>
class Client
{
	// An example of Composition 
private:
	//typename Storage<T>::type data; // typename mandatory, C++98
	Storage<T> data; //C++11
public:
	Client(int n, const T& val) : data(n, val) {}
	void print() const
	{
		std::for_each(data.begin(), data.end(), [](const T& n) { std::cout << n << ","; });
		std::cout << std::endl;
	}
};

#endif // !CLIENT_HPP
