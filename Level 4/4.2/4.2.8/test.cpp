//test.cpp
//Author: TengxiaoFan
//This program tests a stack ADT (First-In-First-Out) and a selection of its operations
#include <iostream>
#include "MyStack.hpp"

int main()
{//Modifying algorithms
	//Make a simple stack
	MyStack<int> s;
	s.push(-1);
	s.push(10);
	s.push(2);
	s.push(7);
	s.push(3);

	s.max();
	std::cout << s.top() << std::endl;//7
	s.min();
	std::cout << s.top() << std::endl;//2
	s.over();
	std::cout << s.top() << std::endl;//10
	s.drop();
	std::cout << s.top() << std::endl;//10
	s.push(9);
	s.rot();
	std::cout << s.top() << std::endl;//-1
	s.swap();
	std::cout << s.top() << std::endl;//9

}