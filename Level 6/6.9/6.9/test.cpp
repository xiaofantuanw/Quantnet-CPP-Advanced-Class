//test.cpp
//Author: TengxioFan
//This is the test function for stack using stackstate
#include "Stack.hpp"
#include "StackState.hpp"
#include "StackException.hpp"
#include <iostream>


int main()
{
	Stack s1(10);

	//Push sth into the stack
	try
	{
		for (int i = 0;i < 10;i++)
			s1.Push((double)i);
		std::cout << "Push success." << std::endl;
	}
	catch (StackException& ex)
	{
		std::cout << ex.GetMessage() << std::endl;
	}
	try
	{
		s1.Push(10.0);
	}
	catch (StackException& ex)
	{
		std::cout << ex.GetMessage() << std::endl;
	}
	//Pop sth out of the stack
	try
	{
		for (int i = 0;i < 10;i++)
			std::cout<<"Pop: "<<s1.Pop()<<std::endl;
		std::cout << "Pop success." << std::endl;
	}
	catch (StackException& ex)
	{
		std::cout << ex.GetMessage() << std::endl;
	}
	try
	{
		s1.Pop();
	}
	catch (StackException& ex)
	{
		std::cout << ex.GetMessage() << std::endl;
	}
}