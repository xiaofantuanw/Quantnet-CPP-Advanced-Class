//test.cpp
//Author: Tengxiao Fan
//This source file tests the variadic template function

#include <iostream>
#include <bitset>

//The terminal of the variadic template function
template <typename T>
void print(const T& object)
{
	std::cout << object << "." << std::endl;//Terminal: output the last object and a stop
}

//The variadic template of the function
template <typename T,typename ... Types>
void print(const T& object, const Types& ... objects)
{
	std::cout << object << ", ";//Output the object and a comma
	print(objects...);//recursively use the function
}



int main()
{
	int j = 1; double d = 2.0;
	print(j); print(d); print(j, d); print(d, j);//Test 2 parameters
	std::cout << "\n3 params \n";
	print(d, j, std::bitset<8>(233));//Test 3 parameters
}