//test.cpp
//Author: TengxiaoFan
//This file aims at test the difference between moving and copying.
#include <string>
#include <iostream>
#include <vector>
#include <chrono>

template < typename T >
void SwapCopyStyle(T& a, T& b)
{ // Swap a and b in copying way; temporary object needed
	T tmp(a); // Copy constructor
	a = b; // Copy all elements from b to a
	b = tmp; // Copy all elements from tmp to b
}

template < typename T >
void SwapMoveStyle(T& a, T& b)
{ // Swap a and b in moving way; temporary object needed
	T tmp=std::move(a); // Initialize
	a = std::move(b); // Move all elements from b to a
	b = std::move(tmp); // Move all elements from tmp to b
}

int main()
{
	using namespace std::chrono;//To record the time

	//Move of string
	std::string str1 = "Apple", str2;//Move the contents of str1 to str2
	std::cout <<"Before:\nstring1: "<< str1 << std::endl;//Before moving 
	std::cout << "string2: " <<str2<< std::endl;
	str2 = std::move(str1);//Move
	std::cout << "After:\nstring1: " << str1 << std::endl;//After moving
	std::cout << "string2: " <<str2<< std::endl;

	//Move of vector
	std::vector<int> vec, vec_copy, vec_move;//Move and copy
	for (int i = 1;i <= 100000;i++)//Initialize the vector
	{
		vec.push_back(i);
	}
	if (vec.size()!=0)//Conditions before moving
		std::cout << "Before:\nLast element of vector 1: " << *(vec.end()-1) << std::endl;
	else
		std::cout << "Before:\nvector 1 empty " << std::endl;
	if (vec_copy.size() != 0)
		std::cout << "Last element of vector 2: " << *(vec_copy.end()-1) << std::endl;
	else
		std::cout << "vector 2 empty " << std::endl;
	steady_clock::time_point t1 = steady_clock::now();//Record the time, 1.7e-4 seconds on my laptop
	vec_copy = vec;//Copy the vector
	steady_clock::time_point t2 = steady_clock::now();
	duration<double> t = duration_cast<duration<double>>(t2 - t1);//The time gap
	std::cout << "Copy time: " << t.count() <<" s"<< std::endl;//output the copy time
	if (vec.size() != 0)//Conditions after copy
		std::cout << "After:\nLast element of vector 1: " << *(vec.end()-1) << std::endl;
	else
		std::cout << "After:\nvector 1 empty " << std::endl;
	if (vec_copy.size() != 0)
		std::cout << "Last element of vector 2: " << *(vec_copy.end()-1) << std::endl;
	else
		std::cout << "vector 2 empty " << std::endl;

	if (vec.size() != 0)//Conditions before moving
		std::cout << "Before:\nLast element of vector 1: " << *(vec.end()-1) << std::endl;
	else
		std::cout << "Before:\nvector 1 empty " << std::endl;
	if (vec_move.size() != 0)
		std::cout << "Last element of vector 2: " << *(vec_move.end()-1) << std::endl;
	else
		std::cout << "vector 2 empty " << std::endl;
	t1 = steady_clock::now();//Record the time, 9e-7 second on my laptop
	vec_move = std::move(vec);//Move the vector
	t2 = steady_clock::now();
	t = duration_cast<duration<double>>(t2 - t1);//Time gap
	std::cout << "Move time: " << t.count() <<" s"<< std::endl;//Output the time of moving
	if (vec.size() != 0)//Conditions after moving
		std::cout << "After:\nLast element of vector 1: " << *(vec.end()-1) << std::endl;
	else
		std::cout << "After:\nvector 1 empty " << std::endl;
	if (vec_move.size() != 0)
		std::cout << "Last element of vector 2: " << *(vec_move.end()-1) << std::endl;
	else
		std::cout << "vector 2 empty " << std::endl;

	//Swap functions
	t1 = steady_clock::now();
	SwapCopyStyle(vec_copy, vec_move);//Use the copy style of swap
	t2 = steady_clock::now();
	t = duration_cast<duration<double>>(t2 - t1);//2.9e-4 second on my laptop
	std::cout << "Swap by copy: " << t.count() << " s" << std::endl;
	t1 = steady_clock::now();
	SwapMoveStyle(vec_copy, vec_move);//Use the move style of swap
	t2 = steady_clock::now();
	t = duration_cast<duration<double>>(t2 - t1);//1.6e-6 second on my laptop
	std::cout << "Swap by move: " << t.count() << " s" << std::endl;


}